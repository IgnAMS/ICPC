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

ll n;
ll C[101];
ll DP[1000005];
ll INF = 1e8;

ll dp(ll x) {
    if(x < 0) return INF;
    if(x == 0) return 0;

    if(DP[x] != -1) return DP[x];
    DP[x] = INF;
    rep(i, n) DP[x] = min(DP[x], dp(x - C[i]) + 1);
    return DP[x];
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll x; cin>>n>>x;
    rep(i, n) cin>>C[i];

    rep(i, 1000005) DP[i] = -1;
    ll ans = dp(x);
    if(ans >= INF) cout<<"-1\n";
    else cout<<ans<<'\n';

    return 0;
}