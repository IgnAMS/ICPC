#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<iostream>
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
// g++ -std=c++17 A.cpp -o a && ./a <input.txt> output.txt   
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

const int mxN = 1e5+5;
int n, m;
vector<array<ll, 3>> E;
vector<pll> G[mxN];
vl P(mxN, -1), D(mxN, -1);
const ll INF = 1e17;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i, m) {
        ll u, v, w; cin>>u>>v>>w; u--, v--;
        G[u].pb({v, w});
        E.pb({u, v, w});
    }
    D[0] = 0;
    int x;
    rep(i, n) {
        x = -1;
        rep(ei, E.size()) {
            auto& [u, v, w] = E[ei];
            if (D[u] < INF && D[u] + w < D[v]) {
                D[v] = D[u] + w, P[v] = ei, x = v;
            }
        }
    }

    if(x == -1) {
        cout<<"NO\n";
        return 0;
    }

    cout<<"YES\n";
    rep(i, n) x = E[P[x]][0];
    vl X = {x};
    int curr = E[P[x]][0];
    while(curr != x) {
        X.pb(curr);
        curr = E[P[curr]][0];
    }
    X.pb(x);
    
    reverse(X.begin(), X.end());
    for(auto v: X) cout<<v + 1<<" "; cout<<"\n";


    return 0;
}