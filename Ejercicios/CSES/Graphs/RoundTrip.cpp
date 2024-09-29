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

vl G[100001];
int V[100001];
int P[100001];
int s = -1, t;
void dfs(int u) {
    // cout<<"entro a visitar a "<<u<<" con padre "<<P[u]<<'\n';
    V[u] = 1;
    for(auto v: G[u]) {
        if(V[v] and v != P[u]) s = u, t = v;
        if(V[v] and v == P[u]) continue;
        if(!V[v]) {
            P[v] = u;
            dfs(v);
        }
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    rep(i, m) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v); G[v].pb(u);
    }
    rep(u, n) if(!V[u]) dfs(u);

    if(s == -1) cout<<"IMPOSSIBLE\n";
    else {
        vl Ans;
        Ans.pb(s);
        while(t != s) Ans.pb(t), t = P[t];
        Ans.pb(s);
        cout<<Ans.size()<<'\n';
        for(auto u: Ans) cout<<u + 1<<' '; cout<<'\n';
    }

    return 0;
}   