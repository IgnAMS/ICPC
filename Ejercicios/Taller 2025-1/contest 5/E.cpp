// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<int> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

const int mxN = 2e5 + 5;
vl D(mxN, -1);
vl P(mxN, -1);
int Mx[mxN];

vl G[mxN];

void dist(ll u, ll d = 0, ll p = -1) {
    D[u] = d, P[u] = p;
    Mx[u] = D[u];
    for(auto v: G[u]) if(v != p)  {
        dist(v, d + 1, u);
        Mx[u] = max(Mx[u], Mx[v]);
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x; cin>>n>>x; x--;
    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v); G[v].pb(u);
    }

    dist(0);

    int curr = x;
    vl X = {curr};
    rep(i, (D[x] - 1) / 2) {
        curr = P[curr];
        X.pb(curr);
    }

    int ans = 0;
    for(auto v: X) {
        // cout<<v + 1<<' '<<Mx[v]<<'\n';
        ans = max(ans, 2 * Mx[v]);
    }
    cout<<ans<<'\n';


    return 0;
}