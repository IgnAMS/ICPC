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

const int mxN = 2e5+5;
vl G[mxN];
deque<ll> Ans[mxN];
ll A[mxN];


ll ans = 0, best_time = 1, cont = 0;

void dfs(int u, int p) {
    Ans[u] = {A[u]};
    for(auto v: G[u]) if(v != p) {
        dfs(v, u);
        Ans[v].push_front(0);
        
        // Ans[u] siempre tiene el mayor tamano
        if(Ans[v].size() > Ans[u].size()) swap(Ans[u], Ans[v]);

        rep(i, Ans[v].size()) {
            cont++;
            Ans[u][i] += Ans[v][i];
            if(Ans[u][i] > ans or (Ans[u][i] == ans and best_time > i + 1)) {
                best_time = i + 1;
                ans = Ans[u][i];
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    repx(i, 1, n) {
        cin>>A[i];
        ans = max(ans, A[i]);
    }
    
    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v);
        G[v].pb(u);
    }

    for(auto u: G[0]) {
        dfs(u, 0);
    }
    cout<<ans<<' '<<best_time<<'\n';

    return 0;
}