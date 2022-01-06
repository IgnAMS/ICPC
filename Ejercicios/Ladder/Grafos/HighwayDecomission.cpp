#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define repx(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;
#define ff first
#define ss second

struct Edge{
    ll v, l, c;
    Edge(ll v, ll l, ll c): v(v), l(l), c(c) {}
    bool operator<(const Edge &e) const { return l > e.l; }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vector<vector<Edge>> G(n, vector<Edge>());
    rep(i, m){
        int u, v, l, c; cin>>u>>v>>l>>c;
        u--, v--;
        G[u].push_back(Edge(v,l,c));
        G[v].push_back(Edge(u,l,c));
    }

    vector<ll> D(n, 1e17); D[0] = 0;
    vector<ll> Cost(n, 0); 
    ll sol = 0;
    priority_queue<Edge> q; q.emplace(0, 0, 0);
    while(!q.empty()){
        ll u = q.top().v, l = q.top().l, c = q.top().c; q.pop();
        if(D[u] < l) continue;
        for(auto e: G[u]) {
            if(D[e.v] > e.l + l){
                D[e.v] = e.l + l, q.emplace(e.v, D[e.v], e.c);
                sol += e.c - Cost[e.v];
                Cost[e.v] = e.c;
            } 
            else if(D[e.v] == e.l + l and e.c < Cost[e.v]){
                sol += e.c - Cost[e.v];
                Cost[e.v] = e.c;
            } 
        }
    }

    cout<<sol<<'\n';


    return 0;
}