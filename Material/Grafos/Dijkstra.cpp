#include "../template.cpp"


const int mxN = 1e5 + 5;
const ll inf = 1e17; 
ll D[mxN];
vector<vector<pll>> G(mxN, vector<pll>());

void Dijkstra(int s) {
    D[s] = 0;
    memset(D, inf, sizeof(D));
    priority_queue<pll, vector<pll>, greater<pll>> pq; pq.push(s);
    while(!pq.empty()) {
        pll x = pq.top(); pq.pop();
        ll u = x.ss, d = x.ff;
        if(D[u] < d) continue;
        for(auto e: G[u]) if(D[e.ff] > D[u] + e.ss) {
            D[v] = D[u] + e.ss;
            q.push({D[v], v});
        }
    }
}