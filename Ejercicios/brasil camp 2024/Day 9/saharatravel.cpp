#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define ar array
#define rep(i, n) for(int i = 0; i<(int)n; ++i)
#define int ll
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
const int mxN = 1e5+5, M = 1e9+7;

int n, q, p[mxN], depth[mxN], hvc[mxN], head[mxN], pos[mxN], sz[mxN], curpos = 0, aa[mxN], ans[mxN]; 
vector<pair<int, int>> adj[mxN];


struct SegmentTree{
    ll sum[4*mxN];
    void init(){
        memset(sum, 0, sizeof(sum));
    }
    void merge(int i){
        sum[i] = sum[2*i] + sum[2*i+1];
    }
    void upd(int l1, int r1, int l2, int r2, int i, ll val){
        if(l2 > r1 || r2 < l1) return; 
        if(l1 <= l2 && r2 <= r1){
            sum[i] = val; 
            return; 
        }
        int m2 = (l2+r2)/2; 
        upd(l1, r1, l2, m2, 2*i, val); 
        upd(l1, r1, m2+1, r2, 2*i+1, val); 
        merge(i); 
    }
    void upd(ll u, ll x) {
        upd(u, u, 0, mxN, 1, x);
    }
    ll qry(int l1, int r1, int l2, int r2, int i){
        if(l2 > r1 || r2 < l1) return 0;
        if(l1 <= l2 && r2 <= r1){
            return sum[i];
        }
        int m2 = (l2+r2)/2; 
        return qry(l1, r1, l2, m2, 2*i) + qry(l1, r1, m2+1, r2, 2*i+1);        
    }
}; 

class HLD{
    SegmentTree st;
    vl A, H, D, R, P;
    int dfs(vector<vector<pll>> &G, int u){
        int ans = 1, M = 0, s;
        for (auto& [v, w] : G[u]) if (v != A[u]) {
            A[v] = u, D[v] = D[u] + 1;
            s = dfs(G, v), ans += s;
            if (s > M) H[u] = v, M = s;
        }
        return ans;
    }
    template <class OP>
    void path(int u, int v, OP op){
        for (; R[u] != R[v]; v = A[R[v]]){
            if (D[R[u]] > D[R[v]]) swap(u, v);
            op(P[R[v]], P[v] + 1);
        }
        if (D[u] > D[v]) swap(u, v);
        // op(P[u], P[v] + 1);                // VALUES ON VERTEX
        op(P[u] + 1, P[v] + 1);         // VALUES ON EDGE
    }

public:
    HLD(vector<vector<pll>> &G, int n) : A(n), D(n), R(n), P(n){
        st = SegmentTree();
        st.init();
        H.assign(n, -1); 
        A[0] = -1, D[0] = 0; 
        dfs(G, 0); 
        int p = 0;
        rep(i, n) if (A[i] == -1 || H[A[i]] != i)
            for (int j = i; j != -1; j = H[j]) R[j] = i, P[j] = p++;
    }
    // void set(int v, const node &x) { st.set(P[v], x); } // VALUES ON VERTEX
    void set(int u, int v, ll x)            // VALUES ON EDGE
    {
        if (D[u] > D[v]) swap(u, v);
        st.upd(P[v], x);
    }
    // void update(int u, int v, const node &x)                  // OPTIONAL FOR RANGE UPDATES
    // { path(u, v, [this, &x](int l, int r) { st.update(l, r, x); }); }
    ll query(int u, int v){
        ll ans = 0;
        path(u, v, [this, &ans](int l, int r) { ans = ans + st.query(l, r); });
        return ans;
    }
};


ll check(ll num, ll pos){
    ll l = pos+1, r = 20020;
    while(l<r){
        int m = (l+r+1)/2;
        if(num/pos == num/l){
            l = m;
        }else{
            r = m-1;
        }
    }
    return l;
}

signed main(){
#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", " w", stdout);
#endif
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    cin >> n >> q;
    memset(aa, 0, sizeof(aa));
    rep(i, n-1){
        ll a, b, c;
        cin >> a >> b >> c, --a, --b;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    HDL hdl;
    priority_queue<ar<ll, 3>, vector<ar<ll, 3>>, greater<ar<ll, 3>>> pq;
    for(int i = 1; i<n; ++i){
        seg.upd(pos[i], pos[i], 0, n-1, 1, aa[i]-1);
        //cout << aa[i]-1 << " " << check(aa[i]-1, 1) << "\n";
        pq.push({check(aa[i]-1, 1), 1, i}); //  {next important divisor, actual divisor, index}
    }
    vector<ar<ll, 4>> qrys;
    rep(T, q){
        ll a, b, c;
        cin >> a >> b >> c, --a, --b;
        qrys.push_back({c, a, b, T});
    }
    sort(qrys.begin(), qrys.end());
    for(int _ = 0; _<q; ++_){
        while(pq.size() && pq.top()[0] <= qrys[_][0]){
            //cout << pq.top()[0] << " " << qrys[_][0] << "\n";
            //cout << "here" << "\n";
            ar<ll, 3> u = pq.top();
            pq.pop();
            seg.upd(pos[u[2]], pos[u[2]], 0, n-1, 1, (aa[u[2]]-1)/qrys[_][0]);
            pq.push({check(aa[u[2]-1], qrys[_][0]), qrys[_][0], u[2]});
        }
        ans[qrys[_][3]] = qry(qrys[_][1], qrys[_][2]);
    }
    for(int i = 0; i<q; ++i){
        cout << ans[i] << "\n";
    }
}