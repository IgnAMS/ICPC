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

const int mxN = 5e5+10;
vector<vector<pair<int, int>>> G(500005);
int in[mxN], out[mxN];
int cont = 0;

class HLD {
    int n;
    vector<int> A, H, D, R, P;
    int dfs(int u) {
        int ans = 1, M = 0, s;
        in[u] = cont++;
        for(auto [v, w]: G[u]) if (v != A[u]) {
            A[v] = u, D[v] = D[u] + 1;
            s = dfs(v), ans += s;
            if(s > M) H[u] = v, M = s;
        }
        out[u] = cont;
        return ans;
    }
public:

    HLD(int N): n(N), A(N), D(N), R(N), P(N) {
        H.assign(n, -1); A[0] = -1, D[0] = 0; 
        dfs(0); 
        int p = 0;
        rep(i, n) if(A[i] == -1 || H[A[i]] != i) {
            for(int j = i; j != -1; j = H[j]) {
                R[j] = i, P[j] = p++;
            }
        }
    }
    
    int get_lca(int u, int v) {
        for (; R[u] != R[v]; v = A[R[v]]) {
            if(D[R[u]] > D[R[v]]) swap(u, v);
        }
        if(D[u] > D[v]) swap(u, v);
        return u;
    }
};

struct ST {
    pll T[4 * mxN];
    void update(int i, pll &x, int l, int r, int u) {
        if(l == r) T[u] = x;
        else {
            int m = (l + r) / 2;
            if(i <= m) update(i, x, l, m, 2 * u + 1);
            else update(i, x, m + 1, r, 2 * u + 2);
            T[u] = min(T[2 * u + 1], T[2 * u + 2]);
        }
    }
    pll query(int i, int j, int l, int r, int u) {
        if(i <= l and r <= j) return T[u];
        if(r < i or j < l) return pll(mxN, mxN);
        int m = (l + r) / 2;
        return min(query(i, j, l, m, 2 * u + 1), query(i, j, m + 1, r, 2 * u + 2));
    }
} st;



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    // cerr<<n<<' '<<m<<'\n';
    rep(i, n - 1) {
        int u, v, w; cin>>u>>v>>w; u--, v--;
        G[u].pb({v, w});
        G[v].pb({u, w});
    }
    HLD hld(n);
    
    // guardo: [a, b, v, w]
    vector<array<ll, 3>> X[n];
    rep(i, m) {
        int a, b, c, w; cin>>a>>b>>c>>w; a--, b--, c--;
        int lca = hld.get_lca(a, b);
        X[a].pb({lca, c, w});
        X[b].pb({lca, c, w});
    }


    pll pmax(mxN, mxN);
    rep(i, n) {
        sort(X[i].begin(), X[i].end(), [&](array<ll, 3> a, array<ll, 3> b){
            return in[a[0]] > in[b[0]];
        });
        if(X[i].empty()) st.update(in[i], pmax, 0, n - 1, 0);
        else {
            pll aux(in[X[i].back()[0]], i);
            st.update(in[i], aux, 0, n - 1, 0);
        }
    }


    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vector<ll> D(n, 1e17);
    D[0] = 0;
    pq.push({0, 0});
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(D[u] < d) continue;
        
        while(true) {
            auto [x, id] = st.query(in[u], out[u] - 1, 0, n - 1, 0);
            if(x > in[u]) break;
            // x <= in[u]
            auto [lca, v, w] = X[id].back();
            X[id].pop_back();
            if(D[v] > w + D[u]) {
                D[v] = D[u] + w;
                pq.push({D[v], v});
            }
            if(X[id].empty()) st.update(in[id], pmax, 0, n - 1, 0);
            else {
                pll aux(in[X[id].back()[0]], id);
                st.update(in[id], aux, 0, n - 1, 0);
            }
        }

        for(auto& [v, w]: G[u]) {
            if(D[v] > (ll)w + D[u]) {
                D[v] = (ll)w + D[u];
                pq.push({D[v], v});
            }
        }
    }
    repx(i, 1, n) cout<<D[i]<<' '; cout<<'\n';

    return 0;
}