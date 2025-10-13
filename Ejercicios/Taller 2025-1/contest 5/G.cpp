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

const int mxN = 100002;
set<ll> G[mxN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;

    rep(i, m) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].insert(v);
        G[v].insert(u);
    }
    vector<vl> Ans;
    rep(u, n) {
        // cerr<<"analizo a "<<u<<' '<<G[u].size()<<'\n';
        while(G[u].size() > 0) {
            int v = *G[u].begin();
            // cerr<<"obtengo a "<<v<<" 1"<<'\n';
            G[v].erase(u);
            G[u].erase(v);
            if(G[v].size() == 0 and G[u].size() == 0) continue;
            int w;
            if(G[v].size() == 0) {
                w = *G[u].begin();
                Ans.pb({v + 1, u + 1, w + 1});
                G[u].erase(w);
                G[w].erase(u);
            }
            else {
                w = *G[v].begin();
                Ans.pb({u + 1, v + 1, w + 1});
                G[w].erase(v);
                G[v].erase(w);
            }
        }
    }
    
    cout<<Ans.size()<<'\n';
    for(auto u: Ans) cout<<u[0]<<' '<<u[1]<<' '<<u[2]<<'\n';


    return 0;
}