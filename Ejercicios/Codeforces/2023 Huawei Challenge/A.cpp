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

struct Num {
    ll number, exponent, digits, binexp, binmant;
    Num(): number(0), exponent(0), digits(0), binexp(0), binmant(0) {}
    Num(string& s) {
        number = 0, exponent = 0, digits = 0;

        ll sign_number = 1, sign_exponent = 1, reading_number = 1;
        for(auto c: s) {
            if(c == '-' and reading_number) sign_number = -1;
            else if(c == '+') sign_exponent = 1;
            else if(c == '-' and !reading_number) sign_exponent = -1;
            else if(c == 'e') reading_number = 0;
            else if(c == '.') continue;
            else if(reading_number) number = number * 10 + (c - '0'), digits++;
            else exponent = exponent * 10 + (c - '0');
        }
        
        number *= sign_number;
        exponent *= sign_exponent;
    }
};


int n;
vector<string> s;
vector<Num> Nums;

char tipo[] = {'d', 's', 'h'};
void solve(int i, vector<vl> &X, bool init) {
    if(i == 3) return;

    if(X[i].size() >= 2) {
        if(!init) cout<<",";
        cout<<"{"<<tipo[i]<<":";
        bool primer = 0;
        for(auto u: X[i]) {
            if(primer) cout<<",";
            primer = 1;
            cout<<u;
        }
        solve(i + 1, X, 0);
        cout<<"}";
    }

    else if(X[i].size() == 1) {
        ll suma = 0;
        repx(j, i + 1, 3) suma += X[j].size();
        if(suma > 0) {
            if(!init) cout<<",";
            cout<<"{"<<tipo[i]<<":";
            bool primer = 0;
            for(auto u: X[i]) {
                if(primer) cout<<",";
                primer = 1;
                cout<<u;
            }
            solve(i + 1, X, 0);
            cout<<"}";
        }
        else cout<<","<<X[i][0];
        
    }
    else solve(i + 1, X, init);
}


void solve_by_blocks() {
    ll right[2] = {4, 6};
    ll difmax[2] = {30, 50};

    db result = 0;
    rep(i, n) result += stod(s[i]);
    ll exp = (result == 0? 0: (result >= 1) + floor(log10(fabs(result))));
    
    // Testing
    // difmax = [[30, 70], [30, 50]]
    ll best1 = 0, best2 = 0;
    db mndif = 1e301;
    for(int a = 20; a <= 40; a += 4) {
        for(int b = 40; b <= 80; b += 4) {
            db partial = 0;
            rep(i, n) {
                if(Nums[i].exponent <= exp - a and Nums[i].exponent <= 3) {
                    if(Nums[i].exponent <= -5) partial += 0;
                    else {
                        db x = 0, pot = 1;
                        string aux = to_string(abs(Nums[i].number));
                        rep(j, 4) if(j < aux.size()) x += db(aux[j] - '0') * pot, pot *= 0.1;
                        if(Nums[i].number < 0) x *= -1.;
                        // cout<<x<<' '<<aux<<'\n';
                        partial += db(x) * pow(10, db(Nums[i].exponent));
                    }
                }
                else if(Nums[i].exponent <= exp - b and Nums[i].exponent <= 37) {
                    if(Nums[i].exponent <= -38) partial += 0;
                    else {
                        db x = 0, pot = 1;
                        string aux = to_string(abs(Nums[i].number));
                        
                        rep(j, 6) if(j < aux.size()) x += db(aux[j] - '0') * pot, pot *= 0.1;
                        if(Nums[i].number < 0) x *= -1.;
                        // cout<<x<<' '<<aux<<'\n';
                        partial += db(x) * pow(10, db(Nums[i].exponent));
                    }
                }
                else partial += stod(s[i]);  
            }

            if(abs(partial - result) > mndif) {
                mndif = abs(partial - result);
                best1 = a, best2 = b;
            }
        }
    }


    // Diferencia mayor a 10^difmax -> lo tiro a uno mas chico
    if(n > 16) cout<<"{d:";
    rep(i, (n + 15) / 16) {
        vl fp16, fp32, fp64;
        for(int j = 16 * i; j < min(n, 16 * (i + 1)); j++) {
            // Llevo a 0 el numero ya que no es significante para la respuesta final, no lo llevo a 0
            // pero si lo estoy llevando a un tipo de numero mas pequeño tal que no me haga mucha diferencia
            if(Nums[j].exponent <= exp - best1 and Nums[j].exponent <= 3) fp16.pb(j + 1);
            else if(Nums[j].exponent <= exp - best2 and Nums[j].exponent <= 37) fp32.pb(j + 1);
            
            // Llevo el número a su representación correcta ya que es suficientemente significante para su tipo de dato
            // Numeros de valor absoluto de exponente lo llevo a un tipo de dato chico siempre y cuando no pierda mantissa
            else if(-4 <= Nums[j].exponent and Nums[j].exponent <= 3 and Nums[j].digits <= right[0]) fp16.pb(j + 1);
            else if(-37 <= Nums[j].exponent and Nums[j].exponent <= 37 and Nums[j].digits <= right[1]) fp32.pb(j + 1);
            else fp64.pb(j + 1);
        }
        vector<vl> X = {fp64, fp32, fp16};
        solve(0, X, (i == 0));
    }

    if(n > 16) cout<<"}";
}

void solve_by_type() {
    ll right[2] = {6, 9};
    vl fp16, fp32, fp64;

    ll mx = -300;
    rep(i, n) mx = max(mx, Nums[i].exponent);

    rep(i, n) {
        if(Nums[i].exponent <= mx - 50) fp16.pb(i + 1);
        else if(Nums[i].exponent <= mx - 100) fp32.pb(i + 1);
        else if(-4 <= Nums[i].exponent and Nums[i].exponent <= 4 and Nums[i].digits <= right[0]) fp16.pb(i + 1);
        else if(-38 <= Nums[i].exponent and Nums[i].exponent <= 38 and Nums[i].digits <= right[1]) fp32.pb(i + 1);
        else fp64.pb(i + 1);
    }

    vector<vl> X = {fp64, fp32, fp16};

    solve(0, X, 1);
}




int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    s.resize(n);
    Nums.resize(n);
    
    rep(i, n) {
        cin>>s[i];
        Nums[i] = Num(s[i]);
    }

    solve_by_blocks();
    // solve_by_type();

    return 0;
}