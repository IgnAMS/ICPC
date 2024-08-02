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

struct Compare {
    bool operator()(const array<ll, 3>& a, const array<ll, 3>& b) const {
        return a > b; // Comparison for min-heap (less to more)
    }
};

bool comp(array<ll, 3>& a, array<ll, 3>& b) {
    return a > b;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    set<array<ll, 3>> X; // x, y, nodo
    // Nodos:
    // 0: origen
    // 1: destino
    // Optimo: usar teletransportador para llegar al lugar (?)
    pll init, exit; cin>>init.ff>>init.ss>>exit.ff>>exit.ss;
    pll Pos[m + 2];
    Pos[0] = init, Pos[1] = exit;

    priority_queue<array<ll, 3>, vector<array<ll, 3>>, Compare> pq;
    X.insert({0, init.ff, init.ss}); 
    X.insert({1, exit.ff, exit.ss}); 
    rep(i, m) {
        ll x, y; cin>>x>>y;
        X.insert({i + 2, x, y});
        Pos[i + 2] = {x, y};
    }
    
    ll D[m + 2];
    rep(i, m + 2) D[i] = 2e9 + 5;
    D[0] = 0;
    pq.push({abs(init.ff - exit.ff) + abs(init.ss - exit.ss), 0, 0});
    ll cont = 0;
    while(true) {
        auto [g, d, u] = pq.top(); pq.pop();
        if(u == 1) break;
        if(D[u] < d) continue;
        cout<<Pos[u].ff<<' '<<Pos[u].ss<<' '<<d<<'\n';
        // auto [v, x, y] = *X.lower_bound({u, 0, 0});
        X.erase(X.lower_bound({u, 0, 0}));

        for(auto& [v, x, y]: X) {
            ll w1 = min(abs(x - Pos[u].ff), abs(y - Pos[u].ss));
            ll w2 = abs(x - Pos[u].ff) + abs(y - Pos[u].ss);
            ll w = (v <= 1? w2: w1);
            if(D[v] > D[u] + w) {
                D[v] = D[u] + w;
                ll g = D[v] + abs(x - Pos[v].ff) + abs(y - Pos[v].ss);
                pq.push({g, D[v], v});
            }
        }
    }
    cout<<D[1]<<'\n';


    return 0;
}