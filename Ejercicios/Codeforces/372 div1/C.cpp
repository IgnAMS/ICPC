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
vector<pll> G[mxN];
int removed[mxN], sz[mxN];
  
ll calcsz(int u, int p = -1) {
    sz[u] = 1;
    for(auto [v, dig]: G[u]) {
        if(v != p and !removed[v]) {
            sz[u] += calcsz(v, u);
        }
    }
    return sz[u];
}
 
ll ctroid(int u, int tree_sz, int p = -1) {
    for(auto [v, dig]: G[u]) {
        if(v != p and !removed[v]) {
            if(sz[v] * 2 > tree_sz) return ctroid(v, tree_sz, u);
        }
    }
    return u;
}


ll Pot10[mxN], InvPot10[mxN];
map<ll, ll> mp;
ll digit[mxN];
vl Centroid;
ll ans = 0;
ll n, M;

vector<pll> Rev;
void dfs_sz(int u, int p, int d, ll dir, ll rev, ll sign) {
    mp[rev] += sign;
    Rev.pb({dir, d});
    for(auto [v, dig]: G[u]) {
        if(v != p and !removed[v]) {
            ll dir_v = (dir * 10 + dig) % M;
            ll rev_v = (rev + dig * Pot10[d]) % M;
            dfs_sz(v, u, d + 1, dir_v, rev_v, sign);
        }
    }
}
 

void build(int u) {
    int centroid = ctroid(u, calcsz(u));
    mp.clear();
    for(auto [v, dig]: G[centroid])  {
        // aumento los contadores
        if(!removed[v]) dfs_sz(v, centroid, 1, dig, dig, 1);
    }
    // cout<<"el centroide es "<<centroid<<'\n';
    // cout<<"por default tengo "<<mp[0]<<" bacanes\n";
    ans += mp[0];
    mp[0]++;
    
    for(auto [v, dig]: G[centroid]) if(!removed[v]) {
        Rev.clear();
        // Saco la branch
        dfs_sz(v, centroid, 1, dig, dig, -1);
        
        // cout<<"reviso la branch que parte desde "<<v<<'\n';
        // cout<<"Rev: "; for(auto [rev, d]: Rev) cout<<"("<<rev<<' '<<d<<"), "; cout<<'\n';
        // cout<<"Map: "; for(auto [x, val]: mp) cout<<"("<<x<<' '<<val<<"), "; cout<<'\n';
        
        // Calculo la resp por la branch
        ll prev = ans;
        for(auto [rev, d]: Rev) {
            // rev esta modulo MOD y InvPot10[d] tambien
            ll val = (M * M - rev * InvPot10[d]) % M; 
            ans += mp[val];
        }
        // cout<<"la respuesta cambio en "<<ans - prev<<'\n';

        // Vuelvo a meter la branch
        dfs_sz(v, centroid, 1, dig, dig, 1);
    }
    
    removed[centroid] = 1;
    for(auto [v, dig]: G[centroid]) if(!removed[v]) {
        build(v);
    }
}


ll binpow(ll a, ll b) {
    if(b < 0) return 1;
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}

ll inv(ll x, ll phi) { return binpow(x, phi - 1); }

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>M;
    rep(i, n - 1) {
        ll u, v, d; cin>>u>>v>>d; 
        G[u].pb({v, d % M});
        G[v].pb({u, d % M});
    }

    ll phi = M - 1;
    ll x = M;
    for(ll i = 2; i * i <= M; i++) {
        if(x % i == 0) {
            while(x % i == 0) x /= i; 
            phi -= phi / i;
        }
    }
    if(x > 1) phi -= phi / x;

    // Inicializo Pot10 e InvPot10
    Pot10[0] = 1, InvPot10[0] = 1;
    repx(i, 1, mxN) {
        Pot10[i] = (Pot10[i-1] * 10) % M;
        InvPot10[i] = binpow(Pot10[i], phi - 1);
    }
    build(0);
    cout<<ans<<'\n';




    return 0;
}