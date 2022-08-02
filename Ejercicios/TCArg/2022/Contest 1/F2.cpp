#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int, int> ii;
typedef double db;
typedef vector<int> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int n, k, m;
vector<vector<ii>> G;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k>>m;
    G.assign(n, vector<ii>());
    vector<map<int, int>> G2(n);
    rep(i, m) {
        int u, v, w; cin>>u>>v>>w; u--, v--;
        if(!G2[u].count(v)) G2[u][v] = w;
        G2[u][v] = min(G2[u][v], w);
    }
    rep(u, n) for(auto e: G2[u]) G[u].push_back(e);

    vector<vector<vi>> E(n, vector<vi>());
    rep(i, n) E[i].push_back({0, i, i});
    rep(_, k - 1) {
        vector<vector<vi>> E2(n, vector<vi>());
        rep(u, n) {
            // cout<<"nivel: "<<_ + 1<<", nodo: "<<u<<'\n';
            for(auto &e: G[u]) for(auto &seg: E[e.ff]) {
                if(u < seg[1] or seg[2] < u) E2[u].push_back({e.ss + seg[0], min(u, seg[1]), max(u, seg[2])});
                // cout<<"posible: "<<(u < seg[1] or seg[2] < u)<<", costo: "<<e.ss + seg[0]<<'\n';
            }
            // cout<<'\n';
        }
        E = E2;
    }
    int ans = 1e9;
    rep(u, n) for(auto seg: E[u]) ans = min(seg[0], ans);
    cout<<(ans == 1e9? -1: ans)<<'\n';

    return 0;
}