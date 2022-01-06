#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second
#define inf 1e8
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
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,g; 
    int u,v;
    while(cin>>n>>m>>g){
        if(n==0 && m==0 && g==0) break;
        vector<vector<int>> flow(n,vector<int>(n,m));
        vector<int> points(n,0);
        char c;
        rep(i,g){
            cin>>u>>c>>v;
            flow[min(u,v)][max(u,v)]--; 
            if(c=='>') points[u]+=2;
            if(c=='='){ points[u]++; points[v]++; }
            if(c=='<') points[v]+=2;
        }
        
        //rep(i,n) {rep(j,n) cout<<flow[i][j]<<" "; cout<<"\n";} cout<<points[0]<<"\n\n";
        for(int i=1;i<n;i++) {points[0]+=2*flow[0][i]; flow[0][i]=0;}
        //rep(i,n) {rep(j,n) cout<<flow[i][j]<<" "; cout<<"\n";} cout<<points[0]<<"\n\n";
        map<ii,ii> nodes;
        int cont=n;
        //nodo 0 es start, nodo 1,2,3,4,5,...,n-1 son nodos normales, (n-2)*(n-1)/2 conexiones
        for(int i=1;i<n;i++)
            for(int j=i+1;j<n;j++)
                nodes[{i,j}]={cont++, 2*flow[i][j]};
            
        int fin=cont++;
        Dinic din(cont);
        int start=0;
        for(auto& u: nodes){
            //cout<<"arista desde "<<0<<" hacia "<<u.ss.ff<<" con flujo "<<u.ss.ss<<"\n";
            //cout<<"arista desde "<<u.ss.ff<<" hacia "<<u.ff.ff<<" con flujo "<<inf<<"\n";
            //cout<<"arista desde "<<u.ss.ff<<" hacia "<<u.ff.ss<<" con flujo "<<inf<<"\n";
            din.add_edge(0, u.ss.ff, u.ss.ss); start+=u.ss.ss;
            din.add_edge(u.ss.ff, u.ff.ff, inf);
            din.add_edge(u.ss.ff, u.ff.ss, inf);
        }
        bool stop=0;
        for(int i=1;i<n;i++){
            if(points[0]-points[i]-1<0) {stop=1; break;}
            //cout<<"arista desde "<<i<<" hacia "<<fin<<" con flujo "<<points[0]-points[i]-1<<"\n";
            din.add_edge(i,fin,points[0]-points[i]-1);
        }
        if(stop){cout<<"N\n"; continue;}
        if(din.max_flow(0,fin)==start) cout<<"Y\n";
        else cout<<"N\n";
    } 

    return 0;
}