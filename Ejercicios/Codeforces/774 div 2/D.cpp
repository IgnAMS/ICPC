#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

vector<vi> G;
vector<vector<vi>> D;
vector<bool> V;
vi dfs(int u, int x, int p) {
    cerr<<u<<' '<<x<<'\n';
    if(D[u][x][0] != -1) return D[u][x];
    vi ans = { 0, 1000000 };
    ll cont = 0;
    for(auto v: G[u]) if(v != p) {
        vi d0 = dfs(v, 0, u), d1 = dfs(v, 1, u); 
        if(d0[0] > ans[0] or (d0[0] == ans[0] and d0[1] < ans[1])) ans = d0, cont++;
        if(!x and d1[0] > ans[0] or (d1[0] == ans[0] and d1[1] < ans[1])) ans = d1;
    }
    ans[0] += x, ans[1] += (x? G[u].size(): 1);
    return D[u][x] = ans;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    G.resize(n, vi()); D.resize(n, vector<vi>(2, vi(2, -1)));
    rep(i, n - 1){
        int u, v; cin>>u>>v; u--, v--;
        G[u].push_back(v); G[v].push_back(u);
    }
    vi d0 = dfs(0, 0, -1), d1 = dfs(0, 1, -1);
    if(d0[0] > d1[0] or (d0[0] == d1[0] and d0[1] < d1[1])) cout<<d0[0]<<' '<<d0[1]<<'\n';
    else cout<<d1[0]<<' '<<d1[1]<<'\n';


    return 0;
}