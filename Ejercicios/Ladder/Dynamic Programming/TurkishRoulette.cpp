#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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


const ll mxN = 252;
const ll INF = 1e10;

ll DP[126][mxN];
ll S[mxN];
ll B[126];

int nb, ns;

ll dp(ll b, ll s) {
    if(s >= ns - 1 and b < nb) return -INF;
    if(b == nb) return 0;
    
    if(DP[b][s] != INF) return DP[b][s];
    DP[b][s] = max(
        dp(b, s + 1),
        dp(b + 1, s + 2) - B[b] * (S[s] + S[s + 1])
    );
    return DP[b][s];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(cin>>ns>>nb and ns) {
        rep(i, ns) cin>>S[i];
        rep(i, nb) cin>>B[i];

        ll ans = -INF;
        rep(_, ns) {
            rep(b, nb) rep(s, ns) DP[b][s] = INF;
            ans = max(ans, dp(0, 0));
            
            ll aux = S[0];
            rep(i, ns - 1) S[i] = S[i + 1];
            S[ns - 1] = aux;
        }
        cout<<ans<<'\n';

    }

    return 0;
}