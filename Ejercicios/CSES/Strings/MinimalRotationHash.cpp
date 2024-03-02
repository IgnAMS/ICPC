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


const int MOD = 1e9+7, BASE = 123;

int binpow(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = (1LL * res * a) % MOD;
        a = (1LL * a * a) % MOD;
        b >>= 1;
    }
    return res;
}

vector<int> P, H;
void init(const string& s) {
    int n = s.size();
    int b = 1;
    P.assign(n, 0);
    H.assign(n + 1, 0);
    rep(i, n) {
        H[i + 1] = (H[i] + 1LL * b * (s[i] - 'a' + 1)) % MOD;
        P[i] = binpow(b, MOD - 2);
        b = (1LL * b * BASE) % MOD;
    }
}

int query(int l, int r) { return (1LL * (H[r] - H[l] + MOD) * P[l]) % MOD; }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    int n = s.size();
    
    s += s;
    init(s);
    int t = 0;
    repx(i, 1, n) {
        int l = 0, r = n - 1;
        while(l < r) {
            int m = (l + r) / 2;
            if(query(t, t + m) == query(i, i + m)) l = m + 1;
            else r = m;
        }
        int lcp = l - 1;
        if(lcp == n) continue;
        if(s[t + lcp] > s[i + lcp]) t = i;
    }
    string ans = "";
    rep(i, n) ans += s[(i + t) % n];
    cout<<ans<<'\n';



    return 0;
}