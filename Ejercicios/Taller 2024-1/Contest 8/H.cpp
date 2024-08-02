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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    if(n == 1) {
        cout<<"YES\n";
        return 0;
    }

    vector<set<ll>> G(n, set<ll>());
    vl inv(n, 0);
    vl cont(n, 1);
    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].insert(v);
        G[v].insert(u);
        inv[u]++, inv[v]++;
    }

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    rep(u, n) if(inv[u] == 1) pq.push({cont[u], u});
    vl V(n, 0);

    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        // cout<<"saco a "<<u<<" con "<<d<<'\n';

        V[u] = 1;
        for(auto v: G[u]) {
            G[v].erase(u);
            // cout<<"saco a "<<u<<" como vecino de "<<v<<'\n';

            if(G[v].size() == 1 and cont[u] <= cont[v]) {
                // cout<<"meto a "<<u<<'\n';
                cont[v] += cont[u];
                pq.push({cont[v], v});
            }
            else if(cont[u] <= cont[v]) cont[v] += cont[u];
            
        }
    }

    bool pos = 1;
    rep(u, n) if(!V[u]) pos = 0;

    if(pos) cout<<"YES\n";
    else cout<<"NO\n";

    
    return 0;
}