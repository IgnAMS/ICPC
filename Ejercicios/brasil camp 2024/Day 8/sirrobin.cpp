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


const int mxN = 2e5+50;
vector<pll> G[mxN];

map<ll, int> invid;
vl id, id2;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k; cin>>n>>k;
    vl b(k); 
    rep(i, k) cin>>b[i];
    sort(b.begin(), b.end());

    ll curr = 1;
    ll paso = 1, cont = 0;
    int indk = 0;

    while(curr <= 1000000000000000LL) {
        id.pb(curr);
        while(indk < k and curr <= b[indk] and curr + paso > b[indk]) {
            ll next;
            if(b[indk] == 4 or b[indk] == 6) next = 1;
            else next = (b[indk] - curr - 1) + id[id.size() - 5];

            if(!invid.count(b[indk])) {
                invid[b[indk]] = id2.size();
                id2.pb(b[indk]);
            }
            if(!invid.count(next)) {
                invid[next] = id2.size();
                id2.pb(next);
            }
            G[invid[b[indk]]].pb({invid[next], 1});
            G[invid[next]].pb({invid[b[indk]], 1});
            indk++;
        }
        curr += paso, cont++;
        if(cont == 2) cont = 0, paso++;
    }
    
    if(!invid.count(1)) {
        invid[1] = id2.size(); 
        id2.pb(1);
    }
    if(!invid.count(n)) {
        invid[n] = id2.size(); 
        id2.pb(n);
    }
    
    id.clear();
    for(auto u: id2) id.pb(u);
    
    sort(id2.begin(), id2.end());
    rep(i, id2.size() - 1) {
        G[invid[id2[i]]].pb({invid[id2[i + 1]], id2[i + 1] - id2[i]});
        G[invid[id2[i + 1]]].pb({invid[id2[i]], id2[i + 1] - id2[i]});
    }

    // for(auto u: id2) {
    //     cout<<"vecinos de "<<u<<'\n';
    //     for(auto& [v, w]: G[invid[u]]) {
    //         cout<<id[v]<<' '<<w<<'\n';
    //     }
    //     cout<<'\n';
    // }
    ll D[mxN];
    rep(i, mxN) D[i] = 1e16;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    D[invid[1]] = 0; 
    pq.push({D[invid[1]], invid[1]});
    while(!pq.empty()) {
        ll u = pq.top().ss, d = pq.top().ff; pq.pop();
        if(d > D[u]) continue;
        
        // cout<<"estoy visitando al nodo "<<id[u]<<" con costo "<<d<<'\n';
        for(auto& [v, w]: G[u]) {
            // cout<<"chequeo a "<<id[v]<<'\n';
            if(D[v] > D[u] + w) {
                D[v] = D[u] + w;
                pq.push({D[v], v});
            }
        } 
    }
    cout<<D[invid[n]]<<'\n';
    
    return 0;
}