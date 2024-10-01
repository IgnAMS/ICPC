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

struct RH {
    int binpow(int a, int b, int MOD) {
        int res = 1;
        while(b) {
            if(b & 1) res = (1LL * res * a) % MOD;
            a = (1LL * a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    const int B = 119, M[2] = {999727999, 1070777777}, P[2] = {325255434, 10018302};
    vector<int> H[2], I[2];
    RH(string &s) {
        int N = s.size(); 
        rep(k, 2) {
            H[k].resize(N + 1), I[k].resize(N + 1);
            H[k][0] = 0; ll b = 1;
            rep(i, N) {
                H[k][i + 1] = (H[k][i] + b * (s[i] - 'a' + 1)) % M[k];
                b = (b * B) % M[k];
            }
            I[k][N] = binpow(b, M[k] - 2, M[k]);
            for(int i = N - 1; i >= 0; i--) I[k][i] = (1LL * I[k][i + 1] * B) % M[k]; 
        }
    }
    ll get(int l, int r)  // inclusive - exclusive
    {
        ll h0 = (H[0][r] - H[0][l] + M[0]) % M[0];
        h0 = (1LL * h0 * I[0][l]) % M[0];
        ll h1 = (H[1][r] - H[1][l] + M[1]) % M[1];
        h1 = (1LL * h1 * I[1][l]) % M[1];
        return (h0 << 32) | h1;
    }
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    string g; cin>>g;
    vl G(26, 0); rep(i, 26) G[i] = g[i] == '1';
    int k; cin>>k;

    int n = s.length();
    RH H(s);
    vector<set<ll>> S(n, set<ll>());

    ll ans = 0;
    rep(i, n) {
        int bad = 0;
        string aux = "";
        repx(j, i, n) {
            if(G[s[j] - 'a'] == 0) bad++;
            if(bad > k) break;

            aux += s[j];
            ll val = H.get(i, j + 1);
            if(!S[j - i].count(val)) {
                // cout<<aux<<' '<<val<<'\n';
                ans++;
                S[j - i].insert(val);
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}