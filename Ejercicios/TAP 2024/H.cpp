#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

const int mxN = 200005;
ll n, m; 

const int mxM = 1e6;
struct ST {
    int T[4 * mxM], L[4 * mxM];
    void push(int l, int r, int u) {
        T[u] = L[u];
        if(l != r) L[2 * u + 1] = L[2 * u + 2] = L[u];
        L[u] = -1;
    }
    void set(int i, int j, int x, int l, int r, int u = 0) {
        if(L[u] != -1) push(l, r, u);
        if(i <= l and r <= j) {
            L[u] = x;
            push(l, r, u);
            return;
        }
        if(r < i or j < l) return;
        int m = (l + r) / 2;
        set(i, j, x, l, m, 2 * u + 1), set(i, j, x, m + 1, r, 2 * u + 2);
        T[u] = max(T[2 * u + 1], T[2 * u + 2]);
    }
    int query(int i, int j, int l, int r, int u = 0) {
        if(L[u] != -1) push(l, r, u);
        if(i <= l and r <= j) return T[u];
        if(r < i or j < l) return -1;
        int m = (l + r) / 2;
        return max(query(i, j, l, m, 2 * u + 1), query(i, j, m + 1, r, 2 * u + 2));
    }
} st;


vl G[mxN];
ll ans = 0;
ll DP[mxN];

ll sz[mxN];
ll dp(int u) {
    for(auto v: G[u]) {
        ll valor = dp(v);
        ans += valor * (m - valor);
        DP[u] += valor;
    }
    return DP[u];
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    memset(st.L, -1, sizeof(st.L));
    memset(st.T, 0, sizeof(st.T));
    cin>>n>>m;
    vector<array<int, 5>> E; // event (x, type, y1, y2, id), 
    set<int> S; 
    rep(i, n) {
        int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
        E.pb({x1, 0, y1, y2, i + 1});
        E.pb({x2, 1, y1, y2, i + 1});
        S.insert(y1), S.insert(y2);
    }
    rep(i, m) {
        int x, y; cin>>x>>y;
        E.pb({x, 2, y, 0, 0});
        S.insert(y);
    }
    // S es a lo mas 4 * 10^5 + 2 * 10^5 ~ 6 * 10^5
    unordered_map<int, int> mp; mp.reserve(mxM);
    for(auto& u: S) mp[u] = mp.size();
    sort(E.begin(), E.end());
    ll P[n + 1];

    int last = 0;
    for(auto& [x, type, y1, y2, id]: E) {
        if(type == 0) {
            int parent = st.query(mp[y1], mp[y2], 0, mp.size());
            P[id] = parent;
            // cout<<"el padre de "<<id<<" es "<<parent<<'\n';
            G[parent].pb(id);
            // G[id].pb(parent);
            st.set(mp[y1], mp[y2], id, 0, mp.size());
        }
        // retorno el segmento al padre
        else if(type == 1) st.set(mp[y1], mp[y2], P[id], 0, mp.size());
        else {
            int parent = st.query(mp[y1], mp[y1], 0, mp.size());
            // cout<<"el punto "<<x<<' '<<y1<<" esta dentro de "<<parent<<'\n';
            DP[parent]++;
        }
    }
    dp(0);
    cout<<setprecision(13)<<fixed<<db(2) * ans / db(m * m)<<'\n';

    return 0;
}