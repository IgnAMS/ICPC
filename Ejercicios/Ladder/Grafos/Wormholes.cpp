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


int n; vi D;
vector<vector<Edge>> G;

bool bellmanFord(int s) {
    D.assign(n, INF); D[s] = 0;
    
    rep(i, n - 1) rep(j, n) if(D[j] < INF) for(Edge e : G[j])
        D[e.v] = min(D[e.v], D[j] + e.w);

    rep(i, n) if(D[i] < INF) for(Edge& e : G[i]) if(D[e.v] > D[i] + e.w) return 1;

    return 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int m; cin>>n>>m;
        G.assign(n, vector<Edge>());
        rep(i, m) {
            int u, v, d; cin>>u>>v>>d;
            G[u].push_back(Edge(v, d));
        }
        if(bellmanFord(0)) cout<<"possible\n";
        else cout<<"not possible\n";
    }    





    return 0;
}