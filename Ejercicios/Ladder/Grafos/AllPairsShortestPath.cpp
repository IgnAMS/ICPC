#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

const int INF = 1e9;

struct Edge
{
    ll v, w;
    Edge(ll v, ll w) : v(v), w(w) {}
};

int n; vi D; vi NI;
vector<vector<Edge>> G;


void dfs(int u) {
    NI[u] = 1;
    for(auto& e: G[u]) if(!NI[e.v]) dfs(e.v);
}


vi bellmanFord(int s) {
    D.assign(n, INF); D[s] = 0;
    NI.assign(n, 0);
    
    rep(i, n - 1) rep(j, n) if(D[j] < INF) for(Edge e : G[j])
        D[e.v] = min(D[e.v], D[j] + e.w);

    rep(i, n) if(D[i] < INF) for(Edge& e : G[i]) if(D[e.v] > D[i] + e.w) dfs(e.v);

    return D;
}




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int m, q;
    bool p = 0;
    while(cin>>n>>m>>q and n) {
        if(p) cout<<'\n';
        else p = 1;
        G.assign(n, vector<Edge>());
        rep(i, m) {
            int u, v, w; cin>>u>>v>>w;
            G[u].push_back(Edge(v, w));
        }
        
        vi V(n, 0);
        vector<vi> DD(n, vi());
        vector<vi> NN(n, vi(n, 0));
        
        rep(_, q) {
            int u, v; cin>>u>>v;
            if(!V[u]) DD[u] = bellmanFord(u), NN[u] = NI, V[u] = 1;
            if(NN[u][v]) cout<<"-Infinity\n";
            else if(DD[u][v] == INF) cout<<"Impossible\n";
            else cout<<DD[u][v]<<'\n'; 
        }

    }





    return 0;
}