#include <vector>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <stack>
#include <string>
#include <cstdint>
#include <cstring>
#include <algorithm>
#include <ctime>

#include "testlib.h"
using namespace std;

constexpr double timeBonus    =  1.0e0;
constexpr double power        =  2.0e0;
constexpr double halfTime     =  1.0e0;
constexpr double floatTime    =  2.0e0;
constexpr double doubleTime   =  4.0e0;
constexpr double maxPrecision = 53.0e0;
constexpr double mantissaPow = 0.05;

const vector< double > example1 = {-4.815473e+04, -1.862622e+04};
const vector< double > example2 = {-4.815473e+01, 1.862622e+02, 2.997603e+02};

constexpr double maxAs = 1.0e-20;

constexpr double penaltyScaling       = 10.0e0; //scaling factor
constexpr unsigned int minPenalty     =  0; //minimal unscaled penalty
constexpr unsigned int maxPenalty     = 0; //maximal unscaled penalty, default 17
double penaltyCounter           = 0; //inital counter
constexpr double penaltyBarrier = 10'000; //penalty step
float currentPenaltyFee               = 0.0e0; //penalty storage
constexpr float penaltyFeeScaling     = 50.0e-2; //penalty fee step

//Register "size" to penalize for long jumps in the sequence
constexpr uint32_t regSize=16;

// public part begin

//simulated fp16
class Float16{
    static const uint32_t mantissaShift = 42;
    static const uint32_t expShiftMid   = 56;
    static const uint32_t expShiftOut   = 52;
    double dValue_;

public:    
    Float16(double in) : dValue_(in) {
        uint64_t utmp;
        memcpy(&utmp, &dValue_, sizeof utmp);
        //zeroing mantissa bits starting from 11th (this is NOT rounding)
        utmp = utmp >> mantissaShift;
        utmp = utmp << mantissaShift;
        //setting masks for 5-bit exponent extraction out of 11-bit one
        const uint64_t maskExpMid = (63llu << expShiftMid);
        const uint64_t maskExpOut = (15llu << expShiftOut);
        const uint64_t maskExpLead = (1llu << 62);
        const uint64_t maskMantissaD = (1llu << 63) + maskExpLead + maskExpMid + maskExpOut;
        if (utmp & maskExpLead) {// checking leading bit, suspect overflow
            if (utmp & maskExpMid) { //Detected overflow if at least 1 bit is non-zero
                //Assign Inf with proper sign
                utmp = utmp | maskExpMid; //setting 1s in the middle 6 bits of of exponent
                utmp = utmp & maskMantissaD; //zeroing mantissa irrelative of original values to prevent NaN
                utmp = utmp | maskExpOut; //setting 1s in the last 4 bits of exponent
            }
        } else { //checking small numbers according to exponent range
            if ((utmp & maskExpMid) != maskExpMid) { //Detected underflow if at least 1 bit is 0
                utmp = 0;
            }
        }
        memcpy(&dValue_, &utmp, sizeof utmp);
    }

    Float16() : dValue_(0) {}

    Float16& operator=(const Float16& rhs) {
        this->dValue_ = rhs.dValue_;
        return *this;
    }

    Float16& operator=(const double& rhs) {
        this->dValue_ = rhs;
        uint64_t utmp;
        memcpy(&utmp, &dValue_, sizeof utmp);
        utmp = utmp >> mantissaShift;
        utmp = utmp << mantissaShift;
        memcpy(&dValue_, &utmp, sizeof utmp);
        return *this;
    }

    friend Float16 operator+(const Float16& lhs, const Float16& rhs) {
        double tmp = lhs.dValue_ + rhs.dValue_;
        return Float16(tmp);
    }

    float convert2Float() { return static_cast<float>(dValue_); }
    double convert2Double() { return dValue_; }
};

// Calculate the fp64 sum sequence like {d:1,2,3}
double calculateFp64(stack<double>& nums) {
    volatile double currResultDouble = 0;
    while (!nums.empty()) {
        currResultDouble += nums.top();
        nums.pop();
    }
    return currResultDouble;
}

// Calculate the fp32 sum sequence like {s:1,2,3}
double calculateFp32(stack<double>& nums) {
    float currResultSingle = 0;
    while (!nums.empty()) {
        currResultSingle += static_cast<float>(nums.top());
        nums.pop();
    }
    return static_cast<double>(currResultSingle);
}

// Calculate the fp16 sum sequence like {h:1,2,3}
double calculateFp16(stack<double>& nums) {
    Float16 currResultHalf(0.);
    while (!nums.empty()) {
        currResultHalf = currResultHalf + Float16(nums.top());
        nums.pop();
    }
    return currResultHalf.convert2Double();
}

// public part end

double randomPenalty() { //penalty for "memory jumps"
    penaltyCounter += 1.0;
    double currentPenaltyFee=(penaltyCounter / penaltyBarrier)*penaltyFeeScaling;
    return currentPenaltyFee;
}

//"Exact" answer based on Kahan summation
double kahan_sum(const vector<double>& vec) {
    long double trueSum=0, corr=0;
    vector<double> dvtmp=vec;
    sort(dvtmp.begin(),dvtmp.end(), [](const double x, const double y) {
        return fabs(x) < fabs(y);
    });
    for (auto i : dvtmp) {
        volatile long double y = static_cast<long double>(i) - corr;
        volatile long double t = trueSum + y;
        corr = (t - trueSum) - y;
        trueSum = t;
    }
    return (double)trueSum;
}

//Mantissa-based score multiplier
double same_mantissa_count(const double calculatedSum, const double expectedSum) {
    if (isinf(calculatedSum) || isinf(expectedSum)) return (double)1.0e20; //worst case
    if (isnan(calculatedSum) || isnan(expectedSum)) return (double)1.0e20; //worst case
    if (calculatedSum == expectedSum) return 1.0e-20; //best case
    return std::max(std::fabs(calculatedSum-expectedSum)/std::max(std::fabs(expectedSum), 1.0e-200), 1.0e-20);
}

//Calculate total score for the solution
double score_calulator(const float exeTime, const double mantissaBits) {
    const double maxScore = 10.0 * sqrt(timeBonus / halfTime + 0.5) / pow(maxAs, mantissaPow); //max possible score
    
    double newExeTime = timeBonus/(exeTime + 0.5);
    double score = 10.0 * sqrt(newExeTime) / pow(mantissaBits, mantissaPow);
    if (std::isnan(score) || std::isinf(score)) score=0.0; //assigne lowest possible score
    
    //Printing information for reference
    cout<<"Current solution efficiency is "<<score/maxScore*100.0e0<<"% "<<endl;
    return score;
}

bool isExample = false;

//Interpreter and simulator of sum execution
pair<float,double> parse_and_simulate(const string& s, const vector<double>& vec) {
    if (s.empty()) quitf(_wa, "empty output");
    if (s[0] != '{') quitf(_wa, "illegal output, expected opening curly bracket \"{\". ");
    stack<char> ops;
    stack<double> nums;

    vector< bool > vis(vec.size(), false);
    
    vector<uint32_t> reg;
    double penalty=0;
    reg.resize(regSize);
    uint32_t regPos=0;

    double excution_time = 0.0e0;
    double answer = 0.0e0;
    uint32_t nCounted=0;

    int slen = s.length();
    char curr_op = ' ';
    for (int i = 0; i < slen; i++) {
        if (s[i] == '{') {
            if (i + 3 >= slen) {
                quitf(_wa, "illegal output, premature end of coding sequence. ");
            }

            if (s[i + 1] != 'd' && s[i + 1] != 's' && s[i + 1] != 'h') {
                quitf(_wa, "illegal output, expected one of \"d\", \"s\", \"h\". ");
            }

            if (s[i + 2] != ':') {
                quitf(_wa, "illegal output, expected \":\". ");
            }

            if (s[i + 3] != '{' && !isdigit(s[i + 3])) {
                quitf(_wa, "illegal output, expected opening curly bracket \"{\" or digit. ");
            }

            ops.push('{');
            ops.push(s[i + 1]);
            curr_op = s[i + 1];
            i += 2;
        } else if (isdigit(s[i])) {
            int j= i + 1;
            while (j < slen && isdigit(s[j])) ++j;
            if (j == slen) {
                quitf(_wa, "illegal output, premature end of coding sequence. ");
            }

            if (s[j] != ',' && s[j] != '}') {
                quitf(_wa, "illegal output, expected closing curly bracket \"}\" or comma \",\". ");
            }

            int index;
            try {
                index = stoi(s.substr(i, j - i)) - 1;
            } catch (...) {
                quitf(_wa, "illegal output, detected index out of int32 range in the coding sequence. ");
            }
            if (index < 0 || index >= (int)vec.size()) {
                quitf(_wa, "illegal output, detected index out of range in the coding sequence. ");
            }

            if (vis[index]) {
                quitf(_wa, "illegal output, detected repeat index in the coding sequence. ");
            }

            vis[index] = true;

            nums.push(vec[index]);
            i = j - 1;
            
            //Evaluating current penalty for long jumps
            if (regPos >= regSize) { //check if register is full
                for (uint32_t i=1; i<regSize; i++) {
                    if ((uint32_t)abs((int)reg[0]-(int)reg[i]) >= regSize) {
                        //penalty+=penaltyStep;
                        penalty+=randomPenalty(); //penalize randomly for jumps wrt to first index in register
                    }
                }
                regPos=0;
            }
            //Append next index to register
            reg[regPos]=index;
            regPos++;
        }
        else if (s[i] == ',') {
            if (i + 1 == slen) {
                quitf(_wa, "illegal output, premature end of coding sequence after comma \",\". ");
            }

            if (s[i + 1] != '{' && !isdigit(s[i + 1])) {
                quitf(_wa, "illegal output, expected opening curly bracket \"{\" or digit. ");
            }

            ops.push(curr_op);
            nCounted++;
            if (curr_op == 'd') {
                excution_time += doubleTime;
            }
            else if (curr_op == 's') {
                excution_time += floatTime;
            }
            else if (curr_op == 'h') { // 'h'
                excution_time += halfTime;
            } else {
                quitf(_wa, "illegal output, expected end of coding sequence, got \",\". ");
            }
        }
        else if (s[i] == '}') {
            if (i + 1 < slen && s[i + 1] != ',' && s[i + 1] != '}') {
                quitf(_wa, "illegal output, expected end of coding sequence, closing curly bracket \"}\", or comma \",\". ");
            }

            if (ops.empty()) {
                quitf(_wa, "illegal output, expected end of coding sequence, got \"}\". ");
            }

            stack<double> tmp_s;
            curr_op = ops.top();
            while (ops.top() != '{') {
                tmp_s.push(nums.top());
                ops.pop();
                nums.pop();
            }

            if (curr_op == 'd') {
                nums.push(calculateFp64(tmp_s));
            }
            else if (curr_op == 's') {
                nums.push(calculateFp32(tmp_s));
            }
            else { // h
                nums.push(calculateFp16(tmp_s));
            }

            ops.pop();
            if (!ops.empty()) {
                curr_op = ops.top();
            } else {
                curr_op = ' ';
            }
        }
        else {
            quit(_wa, "illegal output, detected invalid character. ");
        }
    }
    for (bool v : vis)
        if (!v)
            quitf(_wa, "illegal output, some index is missing.");
    
    if (!ops.empty()) {
        quitf(_wa, "illegal output, premature end of coding sequence. ");
    }
    answer = nums.top(); // Calculated sum based on provided coding sequence

    double ref = kahan_sum(vec); //Expected answer based on Kahan summation
    if ((vec.size() == 2 && ref == kahan_sum(example1)) || (vec.size() == 3 && ref == kahan_sum(example2))) {
        isExample = true;
    }
    double mantissa_bits = same_mantissa_count(answer, ref); // Accuracy score
    std::cout << "same mantissa score is " << mantissa_bits << std::endl;
    for (uint32_t i=1; i<regPos; i++) { // Process remaining numbers in register
        if ((uint32_t)abs((int)reg[0]-(int)reg[i]) >= regSize) {
            penalty+=randomPenalty();
        }
    }
    std::cout << " Penalty " << penalty << std::endl;
    std::cout << " Execution time " << excution_time << std::endl;
    excution_time+=penalty; //Appending penalty to execution time
    if (nCounted > vec.size()) nCounted=vec.size(); //Prevent summation of infinite number of zeros in lowest precision
    excution_time/=nCounted; //Calculate average execution per single sum operation including jump penalty
    std::cout << " Average execution time " << excution_time << std::endl;
    return make_pair(excution_time, mantissa_bits);
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    registerGen(argc, argv, 1); //register generator for random penalty calculation

    int n = inf.readInt(1, 1'000'000, "number of values");
    std::vector<double> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i] = inf.readDouble(-1.7976931348623157e+308, 1.7976931348623157e+308, format("value number %d from sequence",i+1).c_str());
    }

    string s = ouf.readString("[dsh:{},0-9]+","string that encodes summation algorithm");
    
    std::pair<float,double> time_and_mantissabits = parse_and_simulate(s, vec);
    double score = score_calulator(time_and_mantissabits.first, time_and_mantissabits.second);
    if (isExample) {
        cout << "[example points: " << score << "] ";
        score = 0.0;
    }
    quitp(score, "OK");
}
