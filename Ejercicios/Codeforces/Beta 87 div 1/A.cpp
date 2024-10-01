#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

vector<vi> G;
vi V;
ll dfs(int u, int p, int d) {
    // cerr<<u<<' '<<p<<' '<<d<<'\n';
    V[u] = 1;
    ll ans = d;
    for(auto v: G[u]) if(v != p and !V[v]) ans = max(ans, dfs(v, u, d + 1));
    return ans; 
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    G.resize(n, vi()); V.resize(n, 0);
    vi P(n); 
    rep(i, n) {
        cin>>P[i]; 
        if(P[i] != -1) P[i]--;
        if(P[i] != -1) G[P[i]].push_back(i);
    }
    ll ans = 1;
    rep(i, n) if(P[i] == -1) ans = max(ans, dfs(i, -1, 1));
    cout<<ans<<'\n';
    


    return 0;
}