#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

#define rep(i, n) for(int i = 0; i < n; i++)
#define ff first
#define ss second
#define pb push_back

struct PST {
    vector<vl> ST; vector<vl> Leftv, Rightv;
    int N;
    PST(vl &A) {
        N = A.size();
        ST.resize(4*N, vl());
        Leftv.resize(4*N, vl(1, 0));
        Rightv.resize(4*N, vl(1, 0));
        bd(1, 0, N-1, A);
    }
    ll op(ll x, ll y) { return min(x, y); }
    ll neutro() { return 10000000000LL; }
    void bd(int n, int l, int r, vl &A) {
        if(l == r) ST[n].pb(A[r]);
        else {
            bd(2 * n, l, (l+r)/2, A);
            bd(2 * n + 1, (l+r)/2+1, r, A);
            ST[n].pb(op(ST[2*n].back(), ST[2*n+1].back()));
        }
    }
    ll query(int i, int j, int vs) {
        return query(i, j, vs, 0, N-1, 1);
    }
    ll query(int i, int j, int vs, int l, int r, int n) {
        if(r < i or j < l) return neutro();
        if(i <= l and r <= j) return ST[n][vs];
        int m = (l + r) / 2;
        return op(query(i, j, Leftv[n][vs], l, m, 2*n), query(i, j, Rightv[n][vs], m+1, r, 2*n+1));
    }
    void upd(int i, ll v) {
        return upd(i, v, 0, N-1, 1);
    }
    void upd(int i, ll v, int l, int r, int n) {
        if(i < l or r < i) return;
        if(l == r) {
            ST[n].pb(v);
        }
        else {
            int m = (l + r) / 2;
            upd(i, v, l, m, 2*n);
            upd(i, v, m+1, r, 2*n+1);
            ST[n].pb(op(ST[2*n].back(), ST[2*n+1].back()));
            Leftv[n].pb(ST[2*n].size() - 1);
            Rightv[n].pb(ST[2*n+1].size() - 1);
        } 
    }
};


const int mxN = 1e5+5;
ll L[mxN], R[mxN];
vl G[mxN];

int cont = 0;
void dfs(int u) {
    L[u] = cont++;
    for(auto v: G[u]) if(L[v] == -1) dfs(v);
    R[u] = cont-1;
}   



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, r; cin>>n>>r; r--;
    vl A(n); rep(i, n) cin>>A[i];
    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v); G[v].pb(u);
    }

    vl Aux(n, 1e10);
    memset(L, -1, sizeof(L));
    dfs(r);
    PST pst(Aux); 

    vl VersionProf = {0};
    vl D(n, 1e7);
    deque<int> q;
    q.push_back(r); 
        D[r] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop_front();
        VersionProf.pb(D[u]);
        pst.upd(L[u], A[u]);
        for(auto v: G[u]) if(D[v] > D[u] + 1) {
            D[v] = D[u] + 1;
            q.push_back(v);
        }
    }


    int m; cin>>m;
    ll last = 0;
    rep(_, m) {
        ll p, q; cin>>p>>q;
        ll x = (p + last) % n, k = (q + last) % n;
        // la profundidad que quiero es D[x] + k
        ll version = prev(upper_bound(VersionProf.begin(), VersionProf.end(), D[x] + k)) - VersionProf.begin();
        ll val = pst.query(L[x], R[x], version);
        cout<<val<<'\n';
        last = val;

    }

    return 0;
}