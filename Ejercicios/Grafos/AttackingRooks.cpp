#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt



class Dinic
{
    struct Edge { int to, rev; ll f, c; };
    int n, t_; vector<vector<Edge>> G;
    vl D; vi q, W;

    bool bfs(int s, int t)
    {
        W.assign(n, 0); D.assign(n, -1); D[s] = 0;
        int f = 0, l = 0; q[l++] = s;
        while (f < l)
        {
            int u = q[f++];
            for (const Edge &e : G[u]) if (D[e.to] == -1 && e.f < e.c)
                D[e.to] = D[u] + 1, q[l++] = e.to;
        }
        return D[t] != -1;
    }
    ll dfs(int u, ll f)
    {
        if (u == t_) return f;
        for (int &i = W[u]; i < (int)G[u].size(); ++i)
        {
            Edge &e = G[u][i]; int v = e.to;
            if (e.c <= e.f || D[v] != D[u] + 1) continue;
            ll df = dfs(v, min(f, e.c - e.f));
            if (df > 0) { e.f += df, G[v][e.rev].f -= df; return df; }
        }
        return 0;
    }

public:
    Dinic(int N) : n(N), G(N), D(N), q(N) {}
    void addEdge(int u, int v, ll cap)
    {
        G[u].push_back({v, (int)G[v].size(), 0, cap});
        G[v].push_back({u, (int)G[u].size() - 1, 0, 0}); // cap if bidirectional
    }
    ll maxFlow(int s, int t)
    {
        t_ = t; ll ans = 0;
        while (bfs(s, t)) while (ll dl = dfs(s, LLONG_MAX)) ans += dl;
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; 
    while(cin>>n){
        string lineas[n]; rep(i, n) cin>>lineas[i];
        vector<vi> hor(n, vi(n));
        vi SH;
        int id = 1;
        int prev = -1;
        rep(i, n) rep(j, n){
            if(lineas[j][i] == 'X') { prev = id++; continue; }
            if(id != prev) { SH.push_back(id); prev = id; }
            hor[j][i] = id;
            if(j == n-1) prev = id++;
        }
        id++;
        vector<vi> vert(n, vi(n));
        vi SV;
        rep(i, n) rep(j, n){
            if(lineas[i][j] == 'X') { prev = id++; continue; }
            if(id != prev) { SV.push_back(id); prev = id; }
            vert[i][j] = id;
            if(j == n-1) prev = id++;
        }
        // 0 -> source, id + 1 -> target
        Dinic dinic(id + 3);
        for(auto u: SH) dinic.addEdge(0, u, 1);
        for(auto u: SV) dinic.addEdge(u, id+1, 1);
        rep(i, n) rep(j, n) if(lineas[i][j] != 'X')
            dinic.addEdge(hor[i][j], vert[i][j], 1);
        cout<<dinic.maxFlow(0, id+1)<<'\n';
        
    }

    return 0;
}