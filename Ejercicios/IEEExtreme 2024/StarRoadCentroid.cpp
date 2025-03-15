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


const int mxN = 1e5 + 10;
vl G[mxN];
int removed[mxN], sz[mxN], S[mxN];
  

struct ST {
    int T[4 * mxN];
    void update(int i, int x, int l = 0, int r = mxN, int u = 0) {
        if(l == r) {
            T[u] = max(T[u], x);
            return;
        }
        int m = (l + r) / 2;
        if(i <= m) update(i, x, l, m, 2 * u + 1);
        else update(i, x, m + 1, r, 2 * u + 2);
        T[u] = max(T[2 * u + 1], T[2 * u + 2]);
    }
    int query(int i, int j, int l = 0, int r = mxN, int u = 0) {
        if(r < i or j < l) return 0;
        if(i <= l and r <= j) return T[u];
        int m = (l + r) / 2;
        return max(query(i, j, l, m, 2 * u + 1), query(i, j, m + 1, r, 2 * u + 2));
    }
} st;

ll calcsz(int u, int p = -1) {
    sz[u] = 1;
    for(auto v: G[u]) {
        if(v != p and !removed[v]) {
            sz[u] += calcsz(v, u);
        }
    }
    return sz[u];
}
 
ll ctroid(int u, int tree_sz, int p = -1) {
    for(auto v: G[u]) {
        if(v != p and !removed[v]) {
            if(sz[v] * 2 > tree_sz) return ctroid(v, tree_sz, u);
        }
    }
    return u;
}


vl LIS, LDS;
int ans = 0;
ll n;


vector<array<int, 3>> X;
vector<array<int, 3>> Y;
pair<int, int> dfs_sz(int u, int p) {
    int indD = lower_bound(LDS.begin(), LDS.end(), -S[u]) - LDS.begin();
    int indI = lower_bound(LIS.begin(), LIS.end(),  S[u]) - LIS.begin();
    int valD = LDS[indD];
    int valI = LIS[indI];
    LDS[indD] = -S[u];
    LIS[indI] =  S[u];
    
    int left = indD;
    int right = indI;

    for(auto v: G[u]) {
        if(v != p and !removed[v]) {
            auto [valL, valR] = dfs_sz(v, u);
            left = max(left, valL);
            right = max(right, valR);
        }
    }
    X.pb({u, left - indD + 1, right - indI + 1});
    Y.pb({u, left - indD + 1, right - indI + 1});
    LDS[indD] = valD;
    LIS[indI] = valI;
    return {left, right};
}
 

void build(int u = 0) {
    int centroid = ctroid(u, calcsz(u));    
    cerr<<"CENTROIDE: "<<centroid<<'\n';
    for(auto v: G[centroid]) if(!removed[v]) {
        cerr<<"veo la rama desde "<<v<<'\n';
        X.clear();
        
        LDS[0] = -S[centroid];
        auto [valL, valR] = dfs_sz(v, centroid);
        ans = max({ans, valR, valL});

        for(auto [x, left, right]: X) {
            int L = st.query(0, S[x] - 1);
            cerr<<"x, left, L, right: "<<x<<' '<<left<<' '<<L<<' '<<right<<'\n';
            ans = max(
                ans,
                L + right
            );
        }

        X.pb({centroid, valL, 0});
        Y.pb({centroid, valL, 0});

        for(auto [x, left, right]: X) st.update(S[x], left);
        
        rep(i, valR) LIS[i] = mxN;
        rep(i, valL) LDS[i] = mxN;
        cerr<<'\n';
    }
    cerr<<"\n\n";

    for(auto [x, left, right]: Y) st.update(S[x], 0);
    Y.clear();

    removed[centroid] = 1;
    for(auto v: G[centroid]) if(!removed[v]) {
        build(v);
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i, n) cin>>S[i];
    rep(i, n - 1) {
        ll u, v; cin>>u>>v; u--, v--; 
        G[u].pb(v);
        G[v].pb(u);
    }

    LDS.assign(n + 2, mxN);
    LIS.assign(n + 2, mxN);

    build();

    cout<<ans<<'\n';
    return 0;
}