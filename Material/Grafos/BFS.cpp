#include "../template.cpp"


const int mxN = 1e5 + 5;
const ll inf = 1e17; 
ll D[mxN];
vector<vl> G(mxN, vl());

void BFS(int s) {
    D[s] = 0;
    memset(D, inf, sizeof(D));
    dequeue<int> q; q.push(s);
    while(!q.empty()) {
        int u = q.top(); q.pop();
        for(auto v: G[u]) if(D[v] > D[u] + 1) {
            D[v] = D[u] + 1;
            q.push(v);
        }
    }
}
