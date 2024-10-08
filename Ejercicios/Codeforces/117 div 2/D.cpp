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
    int query(int l, int r) { return (1LL * (H[r] - H[l] + MOD) * P[l]) % MOD; }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s1, s2; cin>>s1>>s2;
    int n1 = s1.length(), n2 = s2.length();
    
    Hash<100005, 1000000007, 122> H1, H2; 
    H1.init(s1); H2.init(s2);

    ll ans = 0;
    for(int i = 1; i <= n1; i++) {
        if(n1 % i != 0 or n2 % i != 0) continue;
        
        bool oc = 1;
        ll val = H1.query(0, i);
        for(int j = 0; j + i <= n1; j += i) {
            if(H1.query(j, j + i) != val) oc = 0;
        } 
        for(int j = 0; j + i <= n2; j += i) {
            if(H2.query(j, j + i) != val) oc = 0;
        }
        ans += oc;
    }
    cout<<ans<<'\n';


    return 0;
}