#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

template<class T>
class MCMF {
    typedef pair<T, T> pTT;
    T INF = numeric_limits<T>::max();
    struct Edge {
        int v; T c, w;
        Edge(int v, T c, T w) : v(v), c(c), w(w) {}
    };
    int n; vector<vl> E;

public:
    vector<Edge> L; vl F; vector<T> D, P; vector<bool> V;

    bool dij(int s, int t) {
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
    
    pTT augment(int s, int t) {
        pTT flow(L[F[t]].c, 0);
        for(int v = t; v != s; v = L[F[v] ^ 1].v) {
            flow.ff = min(flow.ff, L[F[v]].c);
            flow.ss += L[F[v]].w;
        }
        for(int v = t; v != s; v = L[F[v] ^ 1].v) {
            L[F[v]].c -= flow.ff;
            L[F[v] ^ 1].c += flow.ff;
        }
        return flow;
    }
    
    MCMF(int n): n(n), E(n), D(n), P(n, 0), V(n, 0) {}
    pTT mcmf(int s, int t) {
        pTT ans(0, 0);
        if(!dij(s, t)) return ans;
        rep(i, n) if(D[i] < INF) P[i] += D[i];
        while(dij(s, t)) {
            auto flow = augment(s, t);
            ans.ff += flow.ff, ans.ss += flow.ff * flow.ss;
            rep(i, n) if(D[i] < INF) P[i] += D[i];
        }
        return ans;
    }
    int addEdge(int u, int v, T c, T w) {
        E[u].pb(L.size()); L.pb({v, c, w});
        E[v].pb(L.size()); L.pb({u, 0, -w});
        return (int)L.size() - 2;
    }
};



ll get_cost(ll x) {
    ll ans = 0;
    rep(i, 31) if(x & (1LL<<i)) ans++;
    return ans;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    ll a[n];
    rep(i, n) cin>>a[i];

    // 0,..., n - 1 are the initial nodes
    // n, ..., 2 * n - 1 are the next nodes
    // 2 * n, ..., 2 * n + m - 1 are the variables
    // 2 * n + m is the source
    // 2 * n + m + 1 is the target
    ll source = 2 * n + m, target = 2 * n + m + 1;
    
    ll asign[m][n];
    ll change[n][n];
    MCMF<ll> mcmf(2 * n + m + 3);
    rep(i, n) repx(j, i + 1, n) {
        ll next_j = n + j;
        if(a[i] == a[j]) change[i][j] =  mcmf.addEdge(i, next_j, 1, 0);
        else change[i][j] =  mcmf.addEdge(i, next_j, 1, get_cost(a[j]));
    }
    rep(i, m) rep(j, n) {
        ll next_j = n + j;
        ll var_i = 2 * n + i;
        asign[i][j] = mcmf.addEdge(var_i, next_j, 1, get_cost(a[j]));
    }
    rep(i, n) {
        mcmf.addEdge(source, i, 1, 0); 
    }
    rep(i, m) {
        ll var_i = 2 * n + i;
        mcmf.addEdge(source, var_i, n, 0);
    }
    rep(j, n) {
        ll next_j = n + j;
        mcmf.addEdge(next_j, target, 1, 0);
    }

    auto flow = mcmf.mcmf(source, target);
    cout<<flow.ff<<' '<<flow.ss<<'\n';

    vector<string> res;
    rep(i, n) {
        cerr<<mcmf.L.size()<<'\n';
        rep(j, m) {
            cerr<<asign[j][i]<<'\n';
            if(mcmf.L[asign[j][i]].c == 0) {
                cout<<"asigno la variable "<<j<<" con el indice "<<i<<'\n';
            
            }
        }
        rep(j, i) {
            cerr<<change[j][i]<<'\n';
            if(mcmf.L[change[j][i]].c == 0) {
                cout<<"asigno hago un cambio de la variable que estaba en "<<j<<" por el indice "<<i<<'\n';
            }
        }
    }
    




    return 0;
}