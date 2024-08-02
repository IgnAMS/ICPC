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

class Dinic{
public:

    struct Edge { int to, rev; ll f, c; };
    int n, t_; vector<vector<Edge>> G;
    vl D; vector<int> q, W;
    bool bfs(int s, int t){
        W.assign(n, 0); D.assign(n, -1); D[s] = 0;
        int f = 0, l = 0; q[l++] = s;
        while (f < l){
            int u = q[f++];
            for (const Edge &e : G[u]) if (D[e.to] == -1 && e.f < e.c)
                D[e.to] = D[u] + 1, q[l++] = e.to;
        }
        return D[t] != -1;
    }
    ll dfs(int u, ll f){
        if (u == t_) return f;
        for (int &i = W[u]; i < (int)G[u].size(); ++i){
            Edge &e = G[u][i]; int v = e.to;
            if (e.c <= e.f || D[v] != D[u] + 1) continue;
            ll df = dfs(v, min(f, e.c - e.f));
            if (df > 0) { e.f += df, G[v][e.rev].f -= df; return df; }
        }
        return 0;
    }

    Dinic(int N) : n(N), G(N), D(N), q(N) {}
    void addEdge(int u, int v, ll cap){
        G[u].push_back({v, (int)G[v].size(), 0, cap});
        G[v].push_back({u, (int)G[u].size() - 1, 0, 0}); // cap if bidirectional
    }
    ll maxFlow(int s, int t){
        t_ = t; ll ans = 0;
        while (bfs(s, t)) while (ll dl = dfs(s, LLONG_MAX)) ans += dl;
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll g, l; cin>>g>>l;
    string S[g], Ans[g];

    vector<vl> G(l, vl(26, 0)), Y(l, vl(26, 0)), B(l, vl(26, 0));
    rep(i, g - 1) {
        cin>>S[i]>>Ans[i];
        rep(j, l) {
            if(Ans[i][j] == 'G') G[j][S[i][j] - 'a'] = 1;
            if(Ans[i][j] == 'Y') Y[j][S[i][j] - 'a'] = 1;
            if(Ans[i][j] == 'B') B[j][S[i][j] - 'a'] = 1;
        }
    }

    ll Min[26], Max[26];
    ll all_min = 0;
    rep(c, 26) {
        ll all_green = 0;
        rep(j, l) if(G[j][c] == 1) all_green++;
        Min[c] = all_green;
        Max[c] = l;
        rep(i, g - 1) {
            ll curr_yellow = 0, curr_green = 0, curr_black = 0;
            rep(j, l) {
                if(S[i][j] - 'a' == c and Ans[i][j] == 'G') curr_green++;
                if(S[i][j] - 'a' == c and Ans[i][j] == 'Y') curr_yellow++;
                if(S[i][j] - 'a' == c and Ans[i][j] == 'B') curr_black++;
            }

            Min[c] = max(Min[c], curr_green + curr_yellow);
            if(curr_black > 0) Max[c] = min(Max[c], curr_green + curr_yellow);
        }
        all_min += Min[c];
    }
    // cout<<all_min<<'\n';
    rep(c, 26) {
        Max[c] = min(Max[c], l - (all_min - Min[c]));
        // cout<<char(c + 'a')<<' '<<Min[c]<<' '<<Max[c]<<'\n';
    }

    ll cont = 0;
    ll source = cont++;
    ll Letter[26];
    rep(c, 26) Letter[c] = cont++;
    ll Position[l];
    rep(i, l) Position[i] = cont++;
    ll target = cont++;

    Dinic dinic(cont + 5);
    rep(c, 26) {
        dinic.addEdge(source, Letter[c], Min[c]);
    }

    rep(i, l) {
        rep(c, 26) {
            bool pos = 1;
            rep(c2, 26) if(c2 != c and G[i][c2] == 1) pos = 0;
            // ya hay un green y debo saltar
            if(!pos) continue;
            // Tengo un yellow o un black en la posicion, por lo que salto
            if(Y[i][c] == 1 or B[i][c] == 1) continue;

            // El green soy yo y debo asignar o no hay ningun green en esta posicion
            // o no hay yellow ni black en esta posicion
            dinic.addEdge(Letter[c], Position[i], 1);
        }
        dinic.addEdge(Position[i], target, 1);  
    }

    dinic.maxFlow(source, target);
    rep(c, 26) {
        dinic.addEdge(source, Letter[c], Max[c] - Min[c]);
    }
    dinic.maxFlow(source, target);
    
    char realAns[l];
    rep(c, 26) {
        for(auto e: dinic.G[Letter[c]]) {
            // if(e.f > 0) cout<<e.f<<' '<<e.to<<'\n';
            if(e.to >= Position[0] and e.f >= 1) {
                realAns[e.to - Position[0]] = char(c + 'a'); 
            }
        }
    }
    rep(i, l) cout<<realAns[i]; cout<<'\n';

    return 0;
}