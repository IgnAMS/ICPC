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
vi D;
bool dfs(int u, int d) {
    D[u] = d;
    for(auto v: G[u]) {
        if(D[v] != -1 and (d - D[v]) % 2 == 0) return 1;
        else if(D[v] == -1 and dfs(v, d + 1)) return 1; 
    }
    return 0;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    D.resize(n, -1); G.resize(n, {});
    rep(i, m) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].push_back(v); G[v].push_back(u);
    }
    bool oc = 0;
    rep(i, n) if(D[i] == -1) oc |= dfs(i, 0);
    if(oc) cout<<"-1\n";
    else{
        ll conta = 0, contb = 0;
        rep(i, n) conta += (D[i] % 2 == 0), contb += D[i] % 2;
        cout<<contb<<'\n';
        rep(i, n) if(D[i] % 2) cout<<i + 1<<' '; cout<<'\n';
        cout<<conta<<'\n';
        rep(i, n) if(!(D[i] % 2)) cout<<i + 1 <<' '; cout<<'\n';
    } 




    return 0;
}