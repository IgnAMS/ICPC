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

const int mxN = 5e5+5;
int D[mxN];
ll V[mxN];
vl G[mxN];
int lejano = 0, mxdist = 0;
int n, m; 

void bfs(int u) {
    rep(i, n) D[i] = -1;
    queue<int> q; q.push(u);
    D[u] = 0;
    int best = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        // lejano = u;
        mxdist = max(mxdist, D[u]);
        if(D[u] >= mxdist and !V[u]) lejano = u;
        for(auto v: G[u]) if(D[v] == -1) {
            D[v] = D[u] + 1;
            q.push(v);
        }
    }
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i, m) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v); G[v].pb(u);
    }

    lejano = 0;
    rep(i, 2) {
        V[lejano] = 1;
        bfs(lejano);
    }
    rep(i, 30) {
        if(mxdist <= (1<<i)) {    
            cout<<i + 1<<'\n';
            return 0;
        }
    }

    return 0;
}