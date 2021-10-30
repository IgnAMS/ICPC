#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
#define eb emplace_back
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt


template <class T>
class MCMF{
    typedef pair<T, T> pTT;
    T INF = numeric_limits<T>::max();
    struct Edge{
        int v; T c, w;
        Edge(int v, T c, T w) : v(v), c(c), w(w) {}
    };

    int n; vector<vi> E;
    vector<Edge> L; vi F; vector<T> D, P; vector<bool> V;

    bool dij(int s, int t){
        D.assign(n, INF); F.assign(n, -1); V.assign(n, false);
        D[s] = 0;
        rep(_, n){
            int best = -1;
            rep(i, n) if (!V[i] && (best == -1 || D[best] > D[i])) best = i;
            if (D[best] >= INF) break;
            V[best] = true;
            for (int e : E[best]){
                Edge ed = L[e];
                if (ed.c == 0) continue;
                T toD = D[best] + ed.w + P[best] - P[ed.v];
                if (toD < D[ed.v]) D[ed.v] = toD, F[ed.v] = e;
            }
        }
        return D[t] < INF;
    }
    pTT augment(int s, int t){
        pTT flow(L[F[t]].c, 0);
        for (int v = t; v != s; v = L[F[v] ^ 1].v)
            flow.ff = min(flow.ff, L[F[v]].c), flow.ss += L[F[v]].w;
        for (int v = t; v != s; v = L[F[v] ^ 1].v)
            L[F[v]].c -= flow.ff, L[F[v] ^ 1].c += flow.ff;
        return flow;
    }

public:
    MCMF(int n) : n(n), E(n), D(n), P(n, 0), V(n, 0) {}
    pTT mcmf(int s, int t){
        pTT ans(0, 0);
        if (!dij(s, t)) return ans;
        rep(i, n) if (D[i] < INF) P[i] += D[i];
        while (dij(s, t)){
            auto flow = augment(s, t);
            ans.ff += flow.ff, ans.ss += flow.ff * flow.ss;
            rep(i, n) if (D[i] < INF) P[i] += D[i];
        }
        return ans;
    }
    void addEdge(int u, int v, T c, T w)
    {
        E[u].pb(L.size()); L.eb(v, c, w);
        E[v].pb(L.size()); L.eb(u, 0, -w);
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin>>n){
        // 0 -> source, 2*n+1 -> target, 2*n+2 sumidero
        // 1, ..., n -> L, n+1, ..., 2*n -> R
        vector<vi> G(n, vi());
        vi cont(n, 0);
        rep(i, n){
            int u, v; cin>>u>>v; u--, v--;
            cont[u]++, cont[v]++;
            G[i].push_back(v); G[i].push_back(u);
        }
        int ans = 0;
        rep(i, n){
            // el jugador i es el werewolf
            MCMF<int> Dinic(2 * n + 2);
            int init_flow = 0;
            // todos los que puedan votar votan
            rep(u, n) if(G[u][0] != i and G[u][1] != i and u != i){
                init_flow++;
                Dinic.addEdge(0, u+1, 1, 0);
            }
            // Todos los que visitan al lobo votaran por el lobo, descarto esos casos
            rep(u, n) if(G[u][0] != i and G[u][1] != i and u != i) for(auto v: G[u]) if(u != v){ 
                // u -> v
                Dinic.addEdge(u+1, n+v+1, 1, 0);
            }
            // para todos los nodos que no son el lobo marco que puedo ir al target con un costo de ...
            rep(v, n) if(v != i) if(cont[i] - 1 - (G[i][0] == v or G[i][1] == v) >= 0){
                Dinic.addEdge(n+v+1, 2*n+1, cont[i] - 1 - (G[i][0] == v or G[i][1] == v), 0);
            }
            ans += (Dinic.mcmf(0, 2*n+1).ff != init_flow);
        }
        cout<<ans<<'\n';
    }


    return 0;
}