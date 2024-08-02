#pragma GCC optimize("Ofast")
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
        Edge(int v, T c, T w): v(v), c(c), w(w) {}
    };
    int n; vector<vl> E;
    vector<Edge> L; vl F; vector<T> D, P; vector<bool> V;
    bool dij(int s, int t) {
        D.assign(n, INF); F.assign(n, -1); V.assign(n, false);
        priority_queue<pair<T, int>> q;
        D[s] = 0;
        q.push({D[s], s});
        while(!q.empty()) {
            auto [d, x] = q.top(); q.pop();
            d *= -1;
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
        for (int v = t; v != s; v = L[F[v] ^ 1].v) {
            flow.ff = min(flow.ff, L[F[v]].c), flow.ss += L[F[v]].w;
        }
        for (int v = t; v != s; v = L[F[v] ^ 1].v) {
            L[F[v]].c -= flow.ff, L[F[v] ^ 1].c += flow.ff;
        }
        return flow;
    }
public: 
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
        E[u].pb(L.size()); L.emplace_back(v, c, w);
        E[v].pb(L.size()); L.emplace_back(u, 0, -w);
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string t; cin>>t;
    int n; cin>>n;
    string S[n];
    ll Cap[n];
    rep(i, n) cin>>S[i]>>Cap[i];

    MCMF<ll> mcmf(n + 30);
    
    ll source = 0;
    ll String[n];
    rep(i, n) String[i] = i + 1;
    ll Char[26];
    rep(i, 26) Char[i] = i + n + 1;
    ll target = n + 27;
    
    // cout<<source<<'\n';
    // rep(i, n) cout<<"string: "<<String[i]<<'\n';
    // rep(i, 26) cout<<"char: "<<Char[i]<<'\n';
    // cout<<"target: "<<target<<'\n';
    
    rep(i, n) {
        // Aristas: 
        mcmf.addEdge(source, String[i], Cap[i], i + 1);

        vl F(26, 0);
        for(auto c: S[i]) F[c - 'a']++; 
        rep(c, 26) {
            // Aristas a la letra
            mcmf.addEdge(String[i], Char[c], F[c], 0);
        }
    }

    vl F(26, 0);
    for(auto c: t) F[c - 'a']++;
    rep(c, 26) {
        mcmf.addEdge(Char[c], target, F[c], 0);
    }

    auto ans = mcmf.mcmf(source, target);
    
    if(ans.ff == t.length()) cout<<ans.ss<<'\n';
    else cout<<"-1\n";




    return 0;
}