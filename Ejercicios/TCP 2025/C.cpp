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

const int mxN = 1e5 + 5;

int N, M, K, I, S;
int C[mxN], Ind[mxN], Cand[mxN];
vector<pll> E[mxN];

vl Dijkstra(int root) {
    vl D(N, 1e18);
    D[root] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({D[root], root});
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(D[u] < d) continue;
        // cout<<"entre a "<<u<<" con distancia "<<d<<'\n';
        for(auto [v, w]: E[u]) if(D[v] > D[u] + w) {
            D[v] = D[u] + w;
            pq.push({D[v], v});
        } 
    }
    return D;
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M>>K>>I>>S; I--;
    rep(i, M) {
        ll u, v, d; cin>>u>>v>>d; u--, v--;
        E[u].pb({v, d});
        E[v].pb({u, d});
    }

    rep(i, N) cin>>C[i];
    rep(i, K + 1) cin>>Ind[i], Ind[i]--;
    rep(i, S) cin>>Cand[i], Cand[i]--;
    sort(Cand, Cand + S);

    ll dist = 1e17, best = Cand[0];
    if(I == 0) {
        vl DR = Dijkstra(Ind[I + 1]);
        rep(i, S) {
            ll curr_dist = C[Cand[i]] + DR[Cand[i]];
            // cout<<Cand[i]<<' '<<curr_dist<<'\n';
            if(curr_dist < dist) dist = curr_dist, best = Cand[i];
        }
    }
    else if(I == K) {
        vl DL = Dijkstra(Ind[I - 1]);
        rep(i, S) {
            ll curr_dist = C[Cand[i]] + DL[Cand[i]]; 
            // cout<<Cand[i]<<' '<<curr_dist<<'\n';
            if(curr_dist < dist) dist = curr_dist, best = Cand[i];
        }
    }
    else {
        // cout<<"entre aca1"<<'\n';
        // cout<<Ind[I - 1]<<' '<<Ind[I + 1]<<'\n';
        vl DL = Dijkstra(Ind[I - 1]);
        vl DR = Dijkstra(Ind[I + 1]);
        rep(i, S) {
            ll curr_dist = C[Cand[i]] + DL[Cand[i]] + DR[Cand[i]];
            // cout<<Cand[i]<<' '<<curr_dist<<' '<<C[Cand[i]]<<' '<<DL[Cand[i]]<<' '<<DR[Cand[i]]<<'\n';
            if(curr_dist < dist) dist = curr_dist, best = Cand[i];
        }
    }
    cout<<best + 1<<'\n';




    return 0;
}