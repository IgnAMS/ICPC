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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, s, d; 
    while(cin>>n>>m and n) {
        cin>>s>>d;
        vector<set<vi>> G(n, set<vi>()); // v, w
        vector<set<vi>> NG(n, set<vi>());
        rep(i, m) {
            int u, v, w; cin>>u>>v>>w;
            G[u].insert({v, w});
            NG[v].insert({u, w});
        }
        priority_queue<vi, vector<vi>, greater<vi>> pq;
        vi D(n, 1e10);
        D[s] = 0;
        pq.push({0, s});
        while(!pq.empty()) {
            ll u, w; w = pq.top()[0], u = pq.top()[1]; pq.pop();
            if(D[u] < w) continue;
            for(auto& e: G[u]) if(D[e[0]] > w + e[1]) { // D[v] > w + e.w
                D[e[0]] = w + e[1];
                pq.push({D[e[0]], e[0]});
            }
        }
        vector<vi> E; // Eliminate
        vi S = {d};
        set<int> C = {d};
        while(!S.empty()) {
            ll v = S.back(); S.pop_back();
            for(auto& e: NG[v]) if(D[v] == D[e[0]] + e[1]) {
                if(!C.count(e[0])) S.push_back(e[0]);
                E.push_back({e[0], v, e[1]});
                C.insert(e[0]);
            }
        }
        for(auto& e: E) G[e[0]].erase({e[1], e[2]});
        D.assign(n, 1e10);
        D[s] = 0;
        pq.push({0, s});
        while(!pq.empty()) {
            ll u, w; w = pq.top()[0], u = pq.top()[1]; pq.pop();
            if(D[u] < w) continue;
            for(auto& e: G[u]) if(D[e[0]] > w + e[1]) { // D[v] > w + e.w
                D[e[0]] = w + e[1];
                pq.push({D[e[0]], e[0]});
            }
        }
        cout<<(D[d] == 1e10? -1: D[d])<<'\n';
        

    }

    return 0;
}