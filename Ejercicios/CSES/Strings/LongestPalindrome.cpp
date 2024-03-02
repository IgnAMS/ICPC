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

template<const int LIM, const int MOD, const int BASE>
struct Hash {
    vector<int> H, P;
 
    int binpow(int a, int b) {
        int res = 1;
        while(b) {
            if(b & 1) res = (1LL * res * a) % MOD;
            a = (1LL * a * a) % MOD;
            b >>= 1;
        }
        return res;
    }
 
    void init(const string& s) {
        H.resize(LIM); P.resize(LIM);
        int n = s.length(), b = 1;
        H[0] = 0;
        rep(i, n) {
            H[i + 1] = (H[i] + 1LL * b * (s[i] - 'a' + 1)) % MOD;
            b = (1LL * b * BASE) % MOD;
        }
        P[n] = binpow(b, MOD - 2);
        for(int i = n - 1; i >= 0; i--) P[i] = (1LL * P[i + 1] * BASE) % MOD; 
    }
    int query(int l, int r) { 
        return (1LL * (H[r] - H[l] + MOD) * P[l]) % MOD;
    }
};
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    int n = s.length();
    Hash<mxN, 1000000007, 123> H1; 
    H1.init(s);
    string revs = s;
    reverse(revs.begin(), revs.end()); 
    Hash<1000005, 1000000007, 123> revH; revH.init(revs);
    
    pair<int, int> best_imp = {0, 0};
    pair<int, int> best_par = {0, -1};
    rep(i, n) {
        int l = 0, r = min(i, n - i - 1);
        while(l < r) {
            int largo = (l + r + 1) / 2;
            int j = i + largo;
            int revi = n - j - 1, revj = n - (i - largo) - 1;
            
            if(H1.query(i - largo, i + largo) == revH.query(revi, revj)) l = largo;
            else r = largo - 1;
        }
        if(best_imp.ss < l) best_imp = {i, l};

        if(i and s[i] == s[i - 1]) {
            int l = 0, r = min(i - 1, n - i - 1);
            while(l < r and i) {
                int largo = (l + r + 1) / 2;
                int j = i + largo;
                int revi = n - j - 1, revj = n - (i - largo - 1) - 1;

                if(H1.query(i - largo - 1, i + largo) == revH.query(revi, revj)) l = largo;
                else r = largo - 1;
            }
            if(best_par.ss < l) best_par = {i, l};
        }
    }
    string ans = "";
    if(2 * best_imp.ss + 1 > 2 * (best_par.ss + 1)) {
        for(int i = best_imp.ff - best_imp.ss; i <= best_imp.ff + best_imp.ss; i++) {
            ans += s[i];
        }
    }
    else {
        for(int i = best_par.ff - best_par.ss - 1; i <= best_par.ff + best_par.ss; i++) {
            ans += s[i];
        }
    }
    
    cout<<ans<<'\n';
 
 
    return 0;
}