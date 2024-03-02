#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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




const int mxN = 2005;
ll D[mxN];
vl G[mxN];
ll MOD = 1e9+7;

ll dfs(ll u, ll L) {
    if(u >= L) return D[u] = 1;
    if(D[u] != -1) return D[u];

    D[u] = 0;
    for(auto v: G[u]) {
        D[u] += dfs(v, L);
        if(D[u] >= MOD) D[u] -= MOD;
    }
    return D[u];
} 



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, l; cin>>n>>l;
    rep(i, l) {
        int k; cin>>k;
        rep(j, k) {
            int x; cin>>x; x--;
            G[i].pb(x);
        }
    }
    rep(i, n) D[i] = -1;
    cout<<dfs(0, l)<<' ';

    ll cont = 0;
    repx(i, l, n) if(D[i] != -1) cont++;
    cout<<cont<<'\n'; 



    return 0;
}