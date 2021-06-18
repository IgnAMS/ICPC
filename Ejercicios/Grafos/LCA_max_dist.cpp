struct LCA{
    int n, l;
    vector<vector<int>> up;
    vector<int> D;
    vector<vector<ll>> maxw;
    vector<vector<ii>> T;
    LCA(int n, vector<vector<ii>>& T): n(n), T(T) {
        l = log2(n) + 1;
        D.assign(n, -1); up.assign(n, vector<int>(l));
        maxw.assign(n, vector<ll>(l, 0));
        dfs(0,-1,0,0);
        for(int e = 1; e < l; e++) rep(u, n){
            int a = up[u][e-1];
            if(a != -1){
                up[u][e] = up[a][e-1];
                maxw[u][e] = max(maxw[a][e-1], maxw[u][e-1]);
            }
            else up[u][e] = -1;
        
        }
    }

    void dfs(int u, int p, int d, ll w){
        D[u] = d; up[u][0] = p; maxw[u][0] = w;
        for(auto& v : T[u]) if(v.ff != p) dfs(v.ff, u, d+1, v.ss);
    }

    ll maxi(int u, int v){
        if(D[u] > D[v]) swap(u,v);
        ll maxW=0;
        for(int e = l-1; e>=0; e--){
            if(up[v][e] != -1 && D[up[v][e]] >= D[u]){
                maxW=max(maxW,maxw[v][e]);
                v=up[v][e];
            }
        }
        if(v == u) return maxW;
        for(int e=l-1; e>=0;e--){
            if(up[u][e]!=up[v][e]){
                maxW=max({maxW,maxw[v][e],maxw[u][e]});
                v=up[v][e], u=up[u][e];
            }
        }
        maxW=max({maxw[u][0],maxw[v][0],maxW});
        return maxW;
    }
};