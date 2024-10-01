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

// Dado nodo u quiero el camino que tiene mas cosas diferentes

const int mxN = 3e5+5;
vl G[mxN];
ll A[mxN];

int removed[mxN], sz[mxN];
  
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

ll ans = 1;
map<ll, ll> mp;
ll dfs_sz(int u, int p) {
    if(!mp.count(A[u])) mp[A[u]] = 0;
    mp[A[u]]++;
    ll best = mp.size();
    for(auto v: G[u]) if(!removed[v] and v != p) {
        ll size = dfs_sz(v, u);
        best = max(best, size);
    }
    mp[A[u]]--;
    if(mp[A[u]] == 0) mp.erase(A[u]);
    return best;
}

 
void build(int u) {
    int centroid = ctroid(u, calcsz(u));
    cout<<"estoy en el centroide "<<centroid<<'\n';
    mp.clear();
    ll mx = 1;
    for(auto v: G[centroid]) if(!removed[v]) {
        mp[A[centroid]] = 1;
        ll size = dfs_sz(v, centroid);
        cout<<"consigo que los nodos por el camino "<<v<<" tiene tam "<<size<<'\n';
        ans = max(ans, mx * size);
        mx = max(mx, size);
    }
    
    removed[centroid] = 1;
    for(auto v: G[centroid]) if(!removed[v]) {
        build(v);
    }
}
 



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        rep(i, n) G[i].clear();
        rep(i, n) removed[i] = 0;
        // cout<<n<<'\n';
        rep(i, n - 1) {
            int p; cin>>p; p--;
            // cout<<p + 1<<' '; 
            G[i + 1].pb(p); G[p].pb(i + 1);
        }
        // cout<<'\n';
        rep(i, n) cin>>A[i];
        // rep(i, n) cout<<A[i]<<' '; cout<<'\n';
        ans = 1;
        build(0);
        cout<<ans<<'\n';

    }


    return 0;
}