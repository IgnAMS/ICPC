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


const int mxN = 1e5+10;
vector<pll> G[8 * mxN];
int id[mxN];

ll up(int u) { return u; }
ll down(int u) { return 4 * mxN + u; }

void init(int l, int r, int u) {
    if(l == r) {
        id[l] = up(u);
        // cout<<l<<" tiene id "<<id[l]<<'\n';
        G[up(u)].pb({down(u), 0});
        G[down(u)].pb({up(u), 0});
        return;
    }
    
    // up node
    G[up(2 * u + 1)].pb({up(u), 0});
    G[up(2 * u + 2)].pb({up(u), 0});
    
    // down node
    G[down(u)].pb({down(2 * u + 1), 0});
    G[down(u)].pb({down(2 * u + 2), 0});
    int m = (l + r) / 2;
    init(l, m, 2 * u + 1); init(m + 1, r, 2 * u + 2);
}

// [l, r] -> v with cost w
void up_edge(int i, int j, int x, int w, int l, int r, int u) {
    if(i <= l and r <= j) {
        G[up(u)].pb({id[x], w});
        // cout<<"anado una arista de ["<<l<<", "<<r<<"] a "<<x<<' '<<w<<'\n';
        return;
    }
    if(r < i or j < l) return;
    int m = (l + r) / 2;
    up_edge(i, j, x, w, l, m, 2 * u + 1);
    up_edge(i, j, x, w, m + 1, r, 2 * u + 2);
}

// v -> [l, r]
void down_edge(int i, int j, int x, int w, int l, int r, int u) {
    if(i <= l and r <= j) {
        G[id[x]].pb({down(u), w});
        // cout<<"anado una arista de "<<x<<" a ["<<l<<", "<<r<<"] "<<w<<'\n';
        return;
    }
    if(r < i or j < l) return;
    int m = (l + r) / 2;
    down_edge(i, j, x, w, l, m, 2 * u + 1);
    down_edge(i, j, x, w, m + 1, r, 2 * u + 2);
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q, s; cin>>n>>q>>s; s--;
    init(0, n - 1, 0);

    rep(_, q) {
        int t; cin>>t;
        if(t == 1) {
            int u, v, w; cin>>u>>v>>w; u--, v--;
            // cout<<"anado una arista de "<<id[u]<<" a "<<id[v]<<" con costo "<<w<<'\n';
            G[id[u]].pb({id[v], w});
        }
        else if(t == 2) {
            int v, l, r, w; cin>>v>>l>>r>>w; l--, r--, v--;
            down_edge(l, r, v, w, 0, n - 1, 0);
        }
        else {
            int v, l, r, w; cin>>v>>l>>r>>w; l--, r--, v--;
            up_edge(l, r, v, w, 0, n - 1, 0);
        }
    }

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vl D(8 * mxN, 1e17);
    D[id[s]] = 0;
    pq.push({D[id[s]], id[s]});
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        // cout<<"entro a "<<u<<" con distancia "<<d<<'\n';
        if(D[u] < d) continue;
        for(auto [v, w]: G[u]) {
            if(D[v] > D[u] + w) {
                D[v] = D[u] + w;
                pq.push({D[v], v});
            }
        }
    }
    rep(u, n) cout<<(D[id[u]] == 1e17? -1: D[id[u]])<<' '; 
    cout<<'\n';



    return 0;
}