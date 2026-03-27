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
// g++ -O2 LongestFlightRoute.cpp && time ./a.out <input.txt> output.txt

const int mxN = 1e5+5;
int n, m;
vl G[mxN];
ll DP[mxN];
ll P[mxN];
set<ll> Vis;

const ll INF = 1e7;

ll dp(int u) {
    if(u == n - 1) return 1;
    if(DP[u] != INF) return DP[u];

    DP[u] = -INF;
    for(auto v: G[u]) {
        if(dp(v) + 1 > DP[u]) {
            DP[u] = dp(v) + 1;
            P[u] = v;
        }
    }
    // cout<<u + 1<<" "<<DP[u]<<"\n";
    return DP[u];
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i, n) DP[i] = INF;
    rep(i, m) {
        int a, b; cin>>a>>b; a--, b--;
        G[a].pb(b);
    }
    if(dp(0) < 0) {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    cout<<dp(0)<<"\n";
    cout<<1<<" ";
    int curr = P[0];
    while(curr != n - 1) {
        cout<<curr + 1<<" ";
        curr = P[curr];
    }
    cout<<n<<"\n";
    




    return 0;
}