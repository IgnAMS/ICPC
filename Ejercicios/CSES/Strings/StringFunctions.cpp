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


vl KMP(string& s) {
    int n = s.size();
    vl L(n);
    L[0] = 0;
    rep(j, n - 1) {
        int i = L[j];
        while(s[i] != s[j + 1] && i) i = L[i - 1];
        L[j + 1] = (s[i] == s[j + 1] ? i + 1 : 0);
    }
    return L;
}

vl Zfunc(string& s) {
    int n = s.length();
    vl Z(n, 0);
    Hash<1000001, 1000000007, 123> H; H.init(s);
    repx(i, 1, n) {
        int l = 0, r = n - i;
        while(l < r) {
            int m = (l + r + 1) / 2;
            // cout<<0<<' '<<m<<", "<<i<<' '<<i + m<<' '<<(H.query(0, m) == H.query(i, i + m))<<'\n';
            if(H.query(0, m) == H.query(i, i + m)) l = m;
            else r = m - 1;
        }
        Z[i] = l;
    }
    return Z;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    vl K = KMP(s);
    vl Z = Zfunc(s);
    for(auto u: Z) cout<<u<<' '; cout<<'\n';
    for(auto u: K) cout<<u<<' '; cout<<'\n';



    return 0;
}