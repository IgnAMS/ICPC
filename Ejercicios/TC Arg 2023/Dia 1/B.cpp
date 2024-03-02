#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define rep(i, n) for(int i = 0; i < n; i++)

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e9;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};


ll get_node(ll u, ll offset) {
    return 2 * u + offset;
}



int main() {
    int m, na, nb, t; cin>>m>>na>>nb>>t;
    vl A(na); rep(i, na) cin>>A[i];
    vl B(nb); rep(i, nb) cin>>B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // 0, ..., 2 * na - 1 -> A
    // 2 * na, ..., 2 * (na + nb) - 1 -> B
    // Source = 500 * 4 + 2 
    // Target = 500 * 4 + 3

    ll Source = 500 * 4 + 2, Target = 500 * 4 + 3;
    Dinic Din(20004, Source, Target);

    // A1 = entrada 2 * i, A2 = salida 2 * i + 1
    // B1 = entrada 2 * i + 2 * na, B2 = salida 2 * i + 1 + 2 * na

    // Del source a los m mas grandes de A1
    rep(i, m) Din.add_edge(Source, get_node(na - 1 - i, 0), 1); 
    // De los m mas pequenos de B2 al target
    rep(i, m) Din.add_edge(get_node(i, 2 * na) + 1, Target, 1);
    
    // Conexiones entre entradas y salidas
    rep(i, na) Din.add_edge(get_node(i, 0), get_node(i, 0) + 1, 1);
    rep(i, nb) Din.add_edge(get_node(i, 2 * na), get_node(i, 2 * na) + 1, 1);
    

    
    // Nodos intermediarios
    rep(i, na) rep(j, nb) if(abs(A[i] - B[j]) < t) {
        // Nodos A2 -> B1 y B2 -> A1
        ll nodea = get_node(i, 0), nodeb = get_node(j, 2 * na);
        // A2 -> B1
        Din.add_edge(nodea + 1, nodeb, 1);
        // B2 -> A1
        Din.add_edge(nodeb + 1, nodea, 1);
    }

    ll mxflow = Din.flow();
    cout<<mxflow<<'\n';
    if(mxflow == m) cout<<"S\n";
    else cout<<"N\n";

    return 0;
}