#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
#define ff first
#define ss second
#define mp make_pair

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
    int n; 
    while(cin>>n){
        char mat[n][n];
        int hor[n][n]; memset(hor,-1,sizeof(hor));
        int ver[n][n]; memset(ver,-1,sizeof(ver));
        int nod=1;
        int lasthor=1;
        rep(i,n) rep(j,n) cin>>mat[i][j];
        rep(i,n)
            rep(j,n){
                int j0= j;
                while(j<n && mat[i][j]!='X') hor[i][j]=nod, j++;
                if(j==j0) continue;     
                lasthor=nod;
                nod++;
            }
        
        rep(j,n)
            rep(i,n){
                int i0= i;
                while(i<n && mat[i][j]!='X') ver[i][j]=nod, i++;
                if(i==i0) continue;
                nod++;
            }
        
        //rep(i,n){ rep(j,n) cout<<hor[i][j]<<" "; cout<<"\n";}
        //rep(i,n){ rep(j,n) cout<<ver[i][j]<<" "; cout<<"\n";}

        Dinic din(nod+2);
        for(int i=1; nod!=1 && i<=lasthor;i++) din.add_edge(0,i,1);
        for(int i=lasthor+1; nod!=1 && i<nod;i++) din.add_edge(i,nod,1);
        rep(i,n)
            rep(j,n){
                while(j<n && mat[i][j]!='X'){
                    din.add_edge(hor[i][j],ver[i][j],1e8);
                    //cout<<hor[i][j]<<" "<<ver[i][j]<<"\n";
                    //cout<<"i,j: "<<i<<" "<<j<<"\n";
                    j++;
                }
            }

        cout<<din.max_flow(0,nod)<<"\n";
    }




    return 0;
}