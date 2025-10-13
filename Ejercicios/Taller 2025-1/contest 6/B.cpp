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

const int mxN = 1e5;
vector<pll> G[mxN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin>>n>>m>>k;
    vl catapulta(n, 0);
    rep(i, m) {
        ll u, v, w; cin>>u>>v>>w; u--,v--;
        G[u].pb({v, w});
        G[v].pb({u, w});
    }

    vector<pll> Cat(k);
    rep(i, k) {
        cin>>Cat[i].ff>>Cat[i].ss; Cat[i].ff--;
    }

    
    priority_queue<pll, vector<pll>, greater<pll>> pq; 
    pq.push({0, 0});
    
    vl D(n, 1e15);
    D[0] = 0;
    for(auto [v, w]: Cat) {
        if(D[v] > w) {
            catapulta[v] = 1;
            D[v] = w;
            pq.push({D[v], v});
        }
    }


    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(D[u] < d) continue;

        for(auto [v, w]: G[u]) {
            if(D[v] == D[u] + w and catapulta[v]) {
                catapulta[v] = 0;
            }

            if(D[v] > D[u] + w) {
                catapulta[v] = 0;
                D[v] = D[u] + w;
                pq.push({D[v], v});
            }
        }
    }
    ll ans = 0;
    rep(i, n) ans += catapulta[i];
    cout<<k - ans<<'\n';



    return 0;
}