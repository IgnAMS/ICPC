#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

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
// g++ -std=c++11 B3.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 B3.cpp && time ./a.out <input.txt> output.txt

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
    // choose base B random to avoid hacks 33 37 41
    // randomize V(s[i])
    const int B = 152, M[2] = {999727999, 1070777777}, P[2] = {325255434, 10018302};
    vector<int> H[2], I[2];
    void init(string &s) {
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


string s; 
string S[10001];
int n, m; 
RH Rh[10001];
RH sh;

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};


// 1 if every permutation has a substring of large k
bool subk(int k) {
    if(k == 0) return 1;

    bool can = 0;
    gp_hash_table<ll, bool, chash> has;
    rep(i, m) {
        rep(j, int(S[i].length()) - k + 1) {
            can = 1;
            has[Rh[i].get(j, j + k)] = 1;
        }
    }
    if(!can) return 0;

    vector<ll> Open(3 * n, 0), Closed(3 * n, 0);
    ll cont = 0;
    ll gap = 0;
    rep(i, 2 * n) {
        if(has[sh.get(i, i + k)]) {
            Open[gap + k]++;
            if(gap + n + 1 < 3 * n) Closed[gap + n + 1]++;
        }
        cont += Open[gap];
        cont -= Closed[gap];
        gap++;
    }
    rep(i, n) {
        if(has[sh.get(i, i + k)]) {
            if(gap + k < 3 * n) Open[gap + k]++;
            if(gap + n + 1 < 3 * n) Closed[gap + n + k]++;
        }
        cont += Open[gap];
        cont -= Closed[gap];
        gap++;
        if(cont == 0) return 0;
    }
    return 1;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    cin>>s;
    s = s + s + s + s;
    sh.init(s);
    rep(i, m) {
        cin>>S[i];
        Rh[i].init(S[i]);
    }

    ll l = 0, r = n + 1;
    while(l < r) {
        int m = (l + r) / 2;
        ll val = subk(m);
        // cout<<l<<' '<<r<<'\n';
        // cout<<m<<' '<<!val<<'\n';
        if(!val) r = m;
        else l = m + 1;
    }
    cout<<l - 1<<'\n';


    return 0;
}