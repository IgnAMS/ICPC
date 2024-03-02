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

ll M = 1e9+7;

ll binpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}

ll minv(ll a) { return binpow(a, M - 2); }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll A[n]; rep(i, n) cin>>A[i];
    ll D[n];
    rep(i, n) {
        ll aux = A[i];
        D[i] = 0;
        while(aux) {
            aux /= 10;
            D[i]++;
        }
    }
    ll F[1001]; F[0] = 1;
    rep(i, 1000) {
        F[i + 1] = (F[i] * (ll)(i + 1)) % M;
    }
    ll P10[1001];
    P10[0] = 1;
    rep(i, 1000) {
        P10[i + 1] = P10[i] * 10LL;
        P10[i + 1] %= M;
    }
    cerr<<n * n * 1001<<'\n';
    ll DP[n][n][1001], DP2[n][n][1001];
    rep(i, n) rep(elem, n) rep(d, 1001) DP[i][elem][d] = 0, DP2[i][elem][d] = 0;
    rep(i, n) DP[i][0][0] = 1;
    rep(i, n) {
        rep(j, n) for(int elem = n - 1; elem >= 0; elem--) for(int d = 1000; d >= 0; d--) if(d >= D[j] and i != j and DP[i][elem - 1][d - D[j]]) {
            DP[i][elem][d] += DP[i][elem - 1][d - D[j]];
            DP[i][elem][d] %= M;

            if(elem > 1) DP2[i][elem][d] += ((DP2[i][elem - 1][d - D[j]] * P10[D[j]]) % M + A[j]) % M;
            DP2[i][elem][d] += (DP2[i][elem - 1][d - D[j]] + (A[j] * P10[d - D[j]]) % M) % M;
            DP2[i][elem][d] %= M;

            // if(elem > 1) cout<<"sumo "<<(DP2[i][elem - 1][d - D[j]] * P10[D[j]]) % M + A[j]<<'\n';
            // cout<<"sumo2: "<<(DP2[i][elem - 1][d - D[j]] + (A[j] * P10[d - D[j]]) % M)<<'\n';
        }
    }
    cerr<<"ola\n";

    ll ans = 0;
    rep(i, n) rep(elem, n) rep(d, 1001) {
        if(DP[i][elem][d]) {
            cout<<DP[i][elem][d]<<' '<<P10[d]<<' '<<A[i]<<' '<<DP2[i][elem][d]<<' '<<F[elem]<<'\n';
            // cout<<(A[i] * P10[d]) % M<<'\n';
            // cout<<(((A[i] * P10[d]) % M) * DP[i][d]) % M<<'\n';
            // cout<<DP2[i][d]<<'\n';

            ll curr = (A[i] * P10[d]) % M;
            curr = (curr * DP[i][elem][d]) % M;
            curr = (curr * F[elem]) % M;

            curr += DP2[i][elem][d];
            curr %= M;
            if(curr) cout<<"sumo "<<curr<<'\n';
            ans += curr;
            ans %= M;
        }
        
    }
    cout<<ans<<'\n';


    return 0;
}