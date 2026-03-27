#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<iostream>
#include <algorithm>
#include<set>
#include<array>
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
// g++ -std=c++17 A.cpp -o a && ./a <input.txt> output.txt   
// ulimit -s 1000000
// g++ -O2 GameRoutes.cpp && time ./a.out <input.txt> output.txt

const int mxN = 1e5+5;
int n, m;
vl G[mxN];
ll DP[mxN];
ll P[mxN];
set<ll> Vis;

const ll INF = 1e7;
const ll MOD = 1e9+7;

ll dp(int u) {
    if(u == n - 1) return 1;
    if(DP[u] != -1) return DP[u];

    DP[u] = 0;
    for(auto v: G[u]) {
        DP[u] += dp(v);
        if(DP[u] >= MOD) DP[u] -= MOD;
    }
    return DP[u];
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i, n) DP[i] = -1;
    rep(i, m) {
        int a, b; cin>>a>>b; a--, b--;
        G[a].pb(b);
    }
    cout<<dp(0)<<"\n";



    return 0;
}