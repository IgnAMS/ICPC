#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

vl I;
vector<string> s;

// Code published by the problem 
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


map<pll, db> mp;
db calc(ll l, ll r) {
    // cerr<<l<<' '<<r<<'\n';
    if(l == r) return stod(s[I[l - 1]]);
    if(mp.count({l, r})) return mp[{l, r}];
    ll m = l + (r - l - 1) / 2;
 
    return mp[{l, r}] = calc(l, m) + calc(m + 1, r);
}


void unite(ll l, ll r) {
    if(l == r) {
        cout<<I[l - 1] + 1;
        return;
    }

    ll m = l + (r - l - 1) / 2;

    db left = calc(l, m);
    db right = calc(m + 1, r);
    db result = left + right;


    uint8_t *byteLeft = (uint8_t *)&left;
    uint8_t *byteRight = (uint8_t *)&right;

    db result_h = db(float(left) + float(right));
    db result_s = (Float16(left) + Float16(right)).convert2Double();

    // cout<<result_h<<' '<<result_s<<' '<<result<<'\n';
    // cout<<fabs(result_s - result)<<'\n';
    // cout<<(fabs(result_s - result <= 1e-150))<<'\n';

    // cout<<result_h<<' '<<isinf(result_h)<<' '<<result<<' '<<fabs(result_h - result)<<'\n';
    // cout<<"isinf: "<<isinf(result_h)<<", isnan:"<<isnan(result_h)<<'\n';
    // cout<<result_h<<'\n';
    // cout<<(fabs(result_h - result) <= 1e-80)<<'\n';
    
    // cerr<<left<<'\n';
    // for(auto u: BL) cerr<<u; cerr<<'\n';
    // cerr<<right<<'\n';
    // for(auto u: BR) cerr<<u; cerr<<'\n';

    // Si pierdo poca info entonces lo mantengo :)
    if(!isnan(result_s) and !isinf(fabs(result_s)) and fabs(result_s - result) <= 1e-150) cout<<"{s:";
    else if(!isnan(result_h) and !isinf(fabs(result_h)) and fabs(result_h - result) <= 1e-80) cout<<"{h:";
    else cout<<"{d:";

    unite(l, m);
    cout<<",";
    unite(m + 1, r);
    cout<<"}";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    s.resize(n);
    rep(i, n) cin>>s[i];

    I.resize(n);
    rep(i, n) I[i] = i;
    
    db nums[n];
    rep(i, n) nums[i] = stod(s[i]);
    auto rng = std::default_random_engine {};
    srand(time(0));
    ll interval = 8;
    rep(i, (n + interval - 1) / interval) {
        // ll mx = n;
        if(interval * (i + 1) > n) {
            sort(I.begin() + interval * i, I.end(), [&](int a, int b){
                return fabs(nums[a]) < fabs(nums[b]);
            });
            // random_shuffle(I.begin() + interval * i, I.end());
        }
        else {
            sort(I.begin() + interval * i, I.begin() + interval * (i + 1), [&](int a, int b) {
                return fabs(nums[a]) < fabs(nums[b]);
            });
            // random_shuffle(I.begin() + interval * i, I.begin() + interval * (i + 1));
        }
    }

    // rep(i, n) cout<<I[i]<<' '<<abs(nums[I[i]])<<'\n'; cout<<'\n';

    unite(1, n);

    return 0;
}