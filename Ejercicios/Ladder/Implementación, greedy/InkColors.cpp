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

const int mxN = 1e5 + 5;
ll DP[mxN][4];
vl G[mxN];
ll Sz[] = {1, 3, 2};

ll dp(ll u, ll level) {
    if(level == 3) {
        return 0;
    }
    if(DP[u][level] != -1) return DP[u][level];
    
    ll ans = 0;
    // Si estoy en level 0 necesito que 
    // uno siga la rama y el resto sume + 1 o que todos se reseteen a 0
    // max(suma0s, suma0s + uno)

    // Si estoy en level 1 necesito tener al menos 3 nodos y que uno siga la rama
    // max(suma0s, suma0s + uno - suma0[i])
    
    // Si estoy en el level 2 necesito tener al menos 2 nodos y que ninguno siga la rama
    // max(suma0s) 

    ll query0[G[u].size()];
    ll query1[G[u].size()];
    ll suma0 = 0;
    for(int i = 0; i < G[u].size(); i++) {
        ll v = G[u][i];
        query0[i] = dp(v, 0);
        suma0 += query0[i];
        query1[i] = (G[u].size() >= Sz[level]? dp(v, level + 1): 0);
        // ans += dp(v, 0) + dp(v, level + 1) * (G[u].size() >= Sz[level]);
    }
    ans = suma0;
    if(G[u].size() >= 2 and level == 2) {
        // cout<<"Termino un arbol en "<<u<<'\n';
        ans++;
    }
    for(int i = 0; i < G[u].size(); i++) if(G[u].size() >= Sz[level]) {
        int prev = ans;
        ans = max(ans, suma0 + query1[i] - query0[i]);
        // ans = max(ans, suma0 + query1[i]);
        if(ans != prev) {
            // cout<<level<<'\n';
            // cout<<"el camino seguira por "<<G[u][i]<<'\n';
        }
    }
    cout<<u<<' '<<level<<' '<<ans<<'\n';
    return DP[u][level] = ans;
}

vl cnt(mxN, 0);
vl pos(mxN, 0), disp(mxN, 0);
ll dfs(int u) {
    cnt[u] = G[u].size();
    ll ans = 0;
    for(auto v: G[u]) ans += dfs(v);
    for(auto v: G[u]) if(cnt[v] >= 3 and pos[v]) {
        cnt[u] -= 1;
        cout<<"encontre una solucion en "<<u<<'\n';
        ans++;
    }
    for(auto v: G[u]) if(cnt[v] >= 2) pos[u] = 1;
    // cout<<u<<' '<<cnt[u]<<' '<<pos[u]<<'\n';
    return ans;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    memset(DP, -1, sizeof(DP));
    int n; cin>>n;
    rep(i, n - 1) {
        int p; cin>>p; p--;
        G[p].pb(i + 1);
    }
    // cout<<dp(0, 0)<<'\n';
    cout<<dfs(0)<<'\n';

    return 0;
}