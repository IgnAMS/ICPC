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
    void addEdge(int u, int v, T c, T w) {
        E[u].pb(L.size()); L.pb({v, c, w});
        E[v].pb(L.size()); L.pb({u, 0, -w});
    }
};



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, p, s; cin>>n>>p>>s;

    // i = initial node for i = 0,...,n-1
    ll a[n], b[n];
    rep(i, n) cin>>a[i];
    rep(i, n) cin>>b[i];
    ll source = n + 1;
    ll target = n + 2;
    ll Programming = n + 3;
    ll Sport = n + 4;

    
    MCMF<ll> MaxFlow(n + 6);
    rep(i, n) {
        // Connect Sport and programming to initial node
        MaxFlow.addEdge(Programming, i, 1, -a[i]);
        MaxFlow.addEdge(Sport, i, 1, -b[i]);
        
        // Connect the initial node to the target
        MaxFlow.addEdge(i, target, 1, 0);
    }

    // Connect the source to programming and sport
    MaxFlow.addEdge(source, Programming, p, 0);
    MaxFlow.addEdge(source, Sport, s, 0);

   
    pll flow = MaxFlow.mcmf(source, target);
    ll ans = -flow.ss;
    cout<<ans<<'\n';

    vl P, S;
    ll ansP = 0, ansS = 0;
    rep(i, n) {
        if(MaxFlow.L[3 * 2 * i].c == 0) {
            P.pb(i);
            ansP += a[i];
        }
        if(MaxFlow.L[3 * 2 * i + 2].c == 0) {
            S.pb(i);
            ansS += b[i];
        }
    }

    // cout<<ansP<<' '<<ansS<<'\n';
    for(auto u: P) cout<<u + 1<<' '; cout<<'\n';
    for(auto u: S) cout<<u + 1<<' '; cout<<'\n';

    return 0;
}