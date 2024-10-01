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


struct DSU {
    vl p; DSU(int N) : p(N, -1) {}
    int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -p[get(x)]; }
    void unite(int x, int y) {
        if ((x = get(x)) == (y = get(y))) return;
        if (p[x] > p[y]) swap(x,y);
        p[x] += p[y], p[y] = x;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin>>n>>m>>k;
    vl c(k); rep(i, k) cin>>c[i];

    vector<pll> G[n];
    DSU dsu(n);
    rep(i, m) {
        ll u, v, x;
        cin>>u>>v>>x; u--, v--;
        G[u].pb({v, x});
        G[v].pb({u, x});
        if(x == 0) dsu.unite(u, v);
    }
    ll acc = 0;
    bool pos = 1;
    rep(i, k) {
        rep(j, c[i]) if(!dsu.sameSet(acc + j, acc)) pos = 0;
        acc += c[i];
    }

    if(!pos) {
        cout<<"No\n";
        return 0;
    }

    ll INF = 1e17;
    vector<vl> D(500, vl(500, INF));

    ll P[n];
    acc = 0;
    rep(i, k) {
        rep(j, c[i]) P[acc + j] = i;
        acc += c[i];
    }

    rep(u, n) for(auto [v, x]: G[u]) {
        D[P[u]][P[v]] = min(D[P[u]][P[v]], x);
    }

    rep(i, k) D[i][i] = 0;

    rep(h, k) rep(i, k) rep(j, k) if(D[i][h] < INF and D[h][j] < INF) {
        D[i][j] = min(D[i][j], D[i][h] + D[h][j]);
        D[j][i] = min(D[j][i], D[j][h] + D[h][i]);
    }
    
    cout<<"Yes\n";
    rep(i, k) {
        rep(j, k) {
            ll d = D[i][j];
            // cout<<"\ni: "<<i<<' '<<j<<' '<<d<<"\n";
            if(d == INF) cout<<"-1 ";
            else cout<<d<<' ';
        }
        cout<<'\n';
    }


    

    






    return 0;
}