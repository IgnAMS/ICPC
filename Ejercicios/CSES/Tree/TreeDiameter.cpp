#pragma GCC optimize("Ofast")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2")
#include<iostream>
#include<vector>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
typedef vector<int> vi;
#define ff first
#define ss second
#define pb push_back
const int mxN = 2e5 + 10;
vector<int> G[mxN];
int n;
ll D[mxN];

void dfs(int u, int d, int p) {
    D[u] = d;
    for(auto v: G[u]) if(v != p) {
        dfs(v, d + 1, u);
    } 
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i, n) D[i] = 1e7;
    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    dfs(0, 0, -1);
    ll lejano = 0;
    rep(i, n) if(D[lejano] < D[i]) lejano = i;
    dfs(lejano, 0, -1);

    rep(i, n) if(D[lejano] < D[i]) lejano = i;
    cout<<D[lejano]<<"\n";
 

    return 0;
}
