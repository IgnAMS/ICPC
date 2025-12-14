#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
#include<iostream>
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

const int mxN = 1e5+5;
int n, m;
vl G[mxN];
vl V(mxN, -1);
ll posible = true;

void dfs(int u, int color) {
    V[u] = color;
    for(auto v: G[u]) {
        if(V[v] == V[u]) posible = false;
        if(V[v] == -1) dfs(v, !color);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i, m) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v); G[v].pb(u);
    }
    rep(i, n) if(V[i] == -1) dfs(i, 0);
    if(posible) {
        rep(i, n) cout<<V[i]+1<<" "; cout<<"\n";
    }
    else cout<<"IMPOSSIBLE\n";

    
    return 0;
}