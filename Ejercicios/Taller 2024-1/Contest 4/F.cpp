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

const int mxN = 1e3+5;
const ll INF = 1e13;
struct Edge  {
    ll v, w, index; 
    bool operator<(const Edge& e) const {
        return w <= e.w;
    }
};

vector<Edge> G[mxN];
ll Ds[2][mxN], Dt[2][mxN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll n, m, L, s, t; cin>>n>>m>>L>>s>>t;
    vector<vl> E;
    rep(i, m) {
        ll u, v, w; cin>>u>>v>>w;
        G[u].pb({v, w, i}), G[v].pb({u, w, i});
        E.pb({u, v, w});
    }

    rep(i, n) rep(b, 2) Ds[b][i] = INF, Dt[b][i] = INF;

    rep(b, 2) {
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push({0, s});
        Ds[b][s] = 0;
        while(!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if(Ds[b][u] < d) continue;
            for(auto& [v, w, ind]: G[u]) {
                ll next = d + (w == 0? (b == 0? 1: INF) : w);
                if(Ds[b][v] > next) {
                    Ds[b][v] = next;
                    pq.push({Ds[b][v], v});
                }
            }
        }

        Dt[b][t] = 0;
        pq.push({0, t});
        while(!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if(Dt[b][u] < d) continue;
            for(auto& [v, w, ind]: G[u]) {
                ll next = d + (w == 0? (b == 0? 1: INF) : w);
                if(Dt[b][v] > next) {
                    Dt[b][v] = next;
                    pq.push({Dt[b][v], v});
                }
            }
        }
    }

    // Si el menor camino se demora mas de L o el mayor camino se demora menos que L no se puede
    if(Ds[0][t] > L or Ds[1][t] < L) {
        cout<<"NO\n";
        return 0;
    } 

    vl D(n, INF);
    D[s] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, s});
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(D[u] < d) continue;
        for(auto& [v, w, ind]: G[u]) {
            if(w == 0 and E[ind][2] == 0) {
                // Si Dt[0][v] + 1 + d <= L -> w = L - (Dt[0][v] + d)
                // Dt[0][v] + 1 + d > L entonces es un camino que no sera optimo
                if(Dt[0][v] + 1 + d <= L) w = L - (Dt[0][v] + d), E[ind][2] = w;
                else w = 1, E[ind][2] = w;
            }

            if(D[v] > w + d) {
                D[v] = w + d;
                pq.push({D[v], v});
            }
        } 
    }
    cout<<"YES\n";
    for(auto& e: E) {
        rep(i, 3) cout<<e[i]<<' '; cout<<'\n';
    }



    return 0;
}