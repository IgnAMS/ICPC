#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll; 
typedef vector<ll> vl; 
typedef pair<ll, ll> pll; 
#define rep(i, n) for(int i = 0; i < n; i++) 
#define repx(i, a, b) for(int i = a; i < b; i++) 
#define ff first 
#define ss second 
 
vector<vl> G; 
vl val, who; 
 
vector<vector<pll>> G2, G3; 
ll comps = 0; 
vl value; 
vl D, L, I; stack<int> S; 
int id; 
 
void dfs(int u) 
{ 
    D[u] = L[u] = id++, I[u] = 1; S.push(u); 
    for (int v : G[u]) 
    { 
        if (D[v] == -1) { dfs(v); L[u] = min(L[v], L[u]); } 
        else if (I[v]) L[u] = min(L[v], L[u]); 
    } 
    if (L[u] == D[u])  
    { 
        while (1) // SCC FOUND 
        { 
            int x = S.top(); S.pop(); I[x] = 0; 
            who[x] = comps; 
             
            if (x == u) break; 
        } 
         comps++; 
    } 
} 
 
ll memo[1000001]; 
ll dp(int v) 
{ 
    //cout << v << endl; 
    if(memo[v] != -1) return memo[v]; 
    ll ans = val[v], maxi = 0; 
 
    for(auto u : G3[v]) 
    { 
        maxi = max(maxi, dp(u.ff) + u.ss); 
    } 
 
    return memo[v] = ans + maxi; 
} 
 
int main() { 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    value.push_back(0); 
     
 
    memset(memo, -1, sizeof(memo)); 
    int n, m; 
    cin >> n >> m; 
    vl acc(100002, 0); 
    repx(i,1,  100001) 
    { 
        ll v = i; 
        acc[i] = acc[i-1] + v * (v+1)/2; 
        //cout << acc[i]<< "\n"; 
     } 
 
    G.assign(n, vl()); 
 
    L.assign(n, 0); 
    D.assign(n , -1); 
    G2.assign(n, vector<pll>()); 
    G3.assign(n, vector<pll>()); 
    val.assign(n, 0); 
    who.assign(n, 0); 
 
    rep(i, m) 
    { 
        int a, b, w; 
        cin >> a >> b >> w; 
        G[a-1].push_back(b-1); 
        G2[a-1].push_back({b-1, w}); 
    } 
 
    D.assign(n, -1); L.resize(n); I.assign(n, 0); 
    id = 0; rep(u, n) if (D[u] == -1) dfs(u); 
 
    rep(i, n) 
    { 
        for(auto it : G2[i]) 
        { 
            ll v, w; 
            tie(v, w) = it; 
            if(who[i] == who[v]) 
            { 
                ll comp_val; 
                ll l = 1, r = 100000, res = 0; 
                while(l <= r) 
                { 
                    ll p = (l + r) / 2; 
 
                    ll resta = acc[p-1]; 
 
                    if(p*(p-1)/2 <= w){ 
                        res = w * p - resta;        
                        l = p+1; 
                    } 
                    else r = p-1; 
                } 
                val[who[i]] += res; 
            } 
            else{ 
                G3[who[i]].push_back({who[v], w}); 
            } 
        } 
    } 
    int s; 
    cin >> s; 
 
    cout << dp(who[s-1]) << "\n"; 
}