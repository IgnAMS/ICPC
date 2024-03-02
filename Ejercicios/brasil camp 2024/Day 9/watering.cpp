#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define ar array
#define rep(i, n) for(int i = 0; i<(int)n; ++i)
#define vvi vector<vector<int>>
#define vi vector<int>
#define ff first
#define ss second
#define eb emplace_back
#define pb push_back

const int mxN = 305, M = 1e9+7;

template <class T>
class MCMF{
    typedef pair<T, T> pTT;
    T INF = numeric_limits<T>::max();
    struct Edge{
        int v; T c, w;
        Edge(int v, T c, T w) : v(v), c(c), w(w) {}
    };
    int n; vvi E;
    vector<Edge> L; vi F; vector<T> D, P; vector<bool> V;
    bool dij(int s, int t){
        D.assign(n, INF); F.assign(n, -1); V.assign(n, false);
        priority_queue<pair<T, int>> q;
        D[s] = 0;
        q.push({D[s], s});
        while(!q.empty()) {
            int x = q.top().second;
            ll d = -q.top().first;
            q.pop();
            if(D[x] != d) continue;
            for(int e: E[x]) {
                Edge ed = L[e];
                if(ed.c == 0) continue;
                T toD = D[x] + ed.w + P[x] - P[ed.v];
                if(D[ed.v] > toD) {
                    D[ed.v] = toD;
                    q.push({-D[ed.v], ed.v});
                    F[ed.v] = e;
                }
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
    void addEdge(int u, int v, T c, T w){
        E[u].pb(L.size()); L.eb(v, c, w);
        E[v].pb(L.size()); L.eb(u, 0, -w);
    }
};

ll a[mxN][mxN], v[mxN];
signed main(){
#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", " w", stdout);
#endif
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    int n;
    cin >> n;
    rep(i, n) cin >> v[i];
    rep(i, n){
        rep(j, n){
            cin >> a[i][j];
        }
    }
    MCMF<int> mcmf(n*n+2);
    int start = n*n;
    int finish = n*n+1;
    rep(i, n) {
        mcmf.addEdge(start, i, n+1, v[i]);
        mcmf.addEdge((n-1)*n+i, finish, 1, 0);
    }
    rep(k, n-1) {
        rep(i, n) {
            rep(j, n) {
                mcmf.addEdge(k*n+i, (k+1)*n+j, n+1, a[i][j]);
            }
        }
    }
    // rep(i, n){
    //     mcmf.addEdge(start, i, 400, v[i]);
    //     //mcmf.addEdge(n+i, 2*n+i, 1, 0);
    //     //mcmf.addEdge(2*n+i, finish, 1, 0);
    //     mcmf.addEdge(n+i, finish, 1, 0);
    //     rep(j, n){
    //         mcmf.addEdge(i, n+j, 1, a[i][j]);
    //     }
    // }
    cout << mcmf.mcmf(start, finish).second << "\n";

}