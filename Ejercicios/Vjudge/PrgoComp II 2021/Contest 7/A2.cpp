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
#define pb push_back
#define eb emplace_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt


template <class T>
class MCMF
{
    typedef pair<T, T> pTT;
    T INF = numeric_limits<T>::max();
    struct Edge
    {
        int v; T c, w;
        Edge(int v, T c, T w) : v(v), c(c), w(w) {}
    };

    int n; vector<vi> E;
    vector<Edge> L; vi F; vector<T> D, P; vector<bool> V;

    bool dij(int s, int t)
    {
        D.assign(n, INF); F.assign(n, -1); V.assign(n, false);
        D[s] = 0;
        rep(_, n)
        {
            int best = -1;
            rep(i, n) if (!V[i] && (best == -1 || D[best] > D[i])) best = i;
            if (D[best] >= INF) break;
            V[best] = true;
            for (int e : E[best])
            {
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
            ans.ff += flow.ff, ans.ss = max(ans.ss, flow.ss);
            rep(i, n) if (D[i] < INF) P[i] += D[i];
        }
        return ans;
    }
    void addEdge(int u, int v, T c, T w){
        E[u].pb(L.size()); L.eb(v, c, w);
        E[v].pb(L.size()); L.eb(u, 0, -w);
    }
};

struct Edge{
    int v, w;  // CHECK FOR OVERFLOW
    Edge(int v, int w) : v(v), w(w) {}
    bool operator<(const Edge &e) const { return w > e.w; }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, s; cin>>n>>m>>s;
    vi P(n); rep(i, n) cin>>P[i];
    vector<vector<Edge>> G(n, vector<Edge>());
    MCMF<ll> Dinic(n + 3);
    rep(i, m){
        int u, v, w; cin>>u>>v>>w;
        Dinic.addEdge(u, v, 1e15, w); Dinic.addEdge(v, u, 1e15, w);
    }
    vector<ii> S(s);
    rep(i, s) cin>>S[i].ff>>S[i].ss; 
    rep(i, n) Dinic.addEdge(0, i+1, P[i], 0);
    cerr<<"me cai aca?\n";
    rep(i, s) Dinic.addEdge(S[i].ff, n + 1, S[i].ss, 0);
    
    cerr<<"me cai aca?\n";
    cout<<Dinic.mcmf(0, n + s + 1).ss<<'\n';




    return 0;
}