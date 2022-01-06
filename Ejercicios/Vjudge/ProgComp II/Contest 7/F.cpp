#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

struct Dinic {
    struct edge {
        int to, rev;
        ll f, cap;
    };
 
    vector<vector<edge>> g;
    vector<ll> dist;
    vector<int> q, work;
    int n, sink;
 
    bool bfs(int start, int finish) {
        dist.assign(n, -1);
        dist[start] = 0;
        int head = 0, tail = 0;
        q[tail++] = start;
        while (head < tail) {
            int u = q[head++];
            for (const edge &e : g[u]) {
                int v = e.to;
                if (dist[v] == -1 and e.f < e.cap) {
                    dist[v] = dist[u] + 1;
                    q[tail++] = v;
                }
            }
        }
        return dist[finish] != -1;
    }
 
    ll dfs(int u, ll f) {
        if (u == sink)
            return f;
        for (int &i = work[u]; i < (int)g[u].size(); ++i) {
            edge &e = g[u][i];
            int v = e.to;
            if (e.cap <= e.f or dist[v] != dist[u] + 1)
                continue;
            ll df = dfs(v, min(f, e.cap - e.f));
            if (df > 0) {
                e.f += df;
                g[v][e.rev].f -= df;
                return df;
            }
        }
        return 0;
    }

    Dinic(int n) {
        this->n = n;
        g.resize(n);
        dist.resize(n);
        q.resize(n);
    }
 
    void add_edge(int u, int v, ll cap) {
        edge a = {v, (int)g[v].size(), 0, cap};
        edge b = {u, (int)g[u].size(), 0, 0}; //Poner cap en vez de 0 si la arista es bidireccional
        g[u].push_back(a);
        g[v].push_back(b);
    }
 
    ll max_flow(int source, int dest) {
        sink = dest;
        ll ans = 0;
        while (bfs(source, dest)) {
            work.assign(n, 0);
            while (ll delta = dfs(source, LLONG_MAX))
                ans += delta;
        }
        return ans;
    }
};




int main(){
    int n;
    while(cin>>n){
        vector<vector<int>> g(n+1,vector<int>());
        vector<vector<bool>> mat(n+1,vector<bool>(n+1,0));
        vector<int> C(n+1,0);
        int u,v;
        rep(i,n) { 
            cin>>u>>v; g[i+1].push_back(u); g[i+1].push_back(v); 
            mat[i+1][u] = mat[i+1][v]=1;
            C[u]++; C[v]++;
        }
        int cont=0;
        for(int u=1;u<=n;u++){
            Dinic din(2*n+2);
            int max=C[u];
            for(int i=1;i<=n;i++) if(u!=i) { 
                din.add_edge(0,i,1);
                din.add_edge(i+n, 2*n+1, max-1-(mat[u][i]? 1:0));
            }

            for(int i=1;i<=n;i++) if(i!=u && !mat[i][u]){
                for(int j: g[i]) if(j!=u)
                    { din.add_edge(i,j+n,1e8); }   
            }
            if(din.max_flow(0,2*n+1) < n-1-C[u]) { cont++; }
        }

        cout<<cont<<"\n";
    }




    return 0;
}