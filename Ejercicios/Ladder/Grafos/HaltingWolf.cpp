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
    int n; cin>>n;
    vector<vi> G(n + 1, vi(n + 1, 0));
    string line; getline(cin, line);

    repx(i, 1, n + 1) {
        getline(cin, line);
        cerr<<line<<'\n';
        stringstream ss(line);
        string command; ss >> command;
        ll L;
        if(command == "*") {
            ss >> L;
            G[i][L] = 1e8;
        }
        else {
            ll k = stoi(command);
            rep(j, k) {
                ss >> L;
                G[i][L]++;
            }
        }
    }  
    MCMF<ll> Dinic(n + 3);
    // 0: source, n + 1: target
    Dinic.addEdge(0, 1, 1e8, 0);
    repx(i, 1, n + 1) {
        Dinic.addEdge(i, n + 1, G[i][1], 0);
        repx(j, 2, n + 1) if(G[i][j]) {
            Dinic.addEdge(i, j, G[i][j], 0);
        }
    }
    ll x = Dinic.mcmf(0, n + 1).ff;
    // cout<<x<<'\n';
    if(x == 1e8) cout<<"*\n";
    else cout<<x + 1<<'\n';

    // cout<<Dinic.mcmf(0, n + 1).ff + 1<<'\n';


    return 0;
}