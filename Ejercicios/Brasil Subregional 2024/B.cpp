#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define pb push_back

int n, m;
vector<pll> G[100];
ll X[100][100];

const ll INF = 1e8;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    vl Actores_Pelis[m];
    rep(i, n) {
        int k; cin>>k;
        rep(j, k) {
            ll u; cin>>u, u--;
            Actores_Pelis[u].pb(i);
        }
    }

    
    rep(i, m) {
        
        rep(j, Actores_Pelis[i].size()) {
            repx(k, j + 1, Actores_Pelis[i].size()) {
                ll u = Actores_Pelis[i][j], v = Actores_Pelis[i][k];
                if(X[u][v] == 0) {
                    // cout<<"conecto a "<<u<<" con "<<v<<" a traves del actor "<<i<<'\n';
                    G[u].pb({v, i});
                    G[v].pb({u, i});
                    X[u][v] = X[u][v] = 1;
                }
            }
        }
    }



    
    int D[n][n];
    rep(i, n) {
        deque<int> q;
        q.push_back(i);
        rep(j, n) D[i][j] = INF; 
        D[i][i] = 0;
        while(!q.empty()) {
            auto u = q.front(); q.pop_front();
            for(auto [v, a]: G[u]) if(D[i][v] > D[i][u] + 1) {
                D[i][v] = D[i][u] + 1;
                q.push_back(v);
            }
        }
        // cout<<"distancais de "<<i<<'\n';
        // rep(j, n) cout<<D[i][j]<<' '; cout<<'\n';
    }

    ll q; cin>>q;
    while(q--) {
        int a1, a2; cin>>a1>>a2; a1--, a2--;
        if(Actores_Pelis[a1].size() == 0 or Actores_Pelis[a2].size() == 0) {
            cout<<"-1\n";
            continue;
        }
        ll u = Actores_Pelis[a1][0], v = Actores_Pelis[a2][0];
        for(auto w: Actores_Pelis[a1]) for(auto z: Actores_Pelis[a2]) {
            if(D[u][v] > D[w][z]) u = w, v = z;
        } 
        if(D[u][v] == INF) {
            cout<<"-1\n";
            continue;
        }

        ll x = v;
        vector<pll> Ans;
        while(x != u) {
            for(auto [w, a]: G[x]) if(D[u][x] == D[u][w] + 1) {
                Ans.pb({a, x});
                x = w;
                break;
            }
        }
        reverse(Ans.begin(), Ans.end());        
        
        cout<<Ans.size() + 2<<'\n';
        cout<<a1 + 1<<' '<<u + 1<<' ';
        for(auto [a, b]: Ans) cout<<a + 1<<' '<<b + 1<<' ';
        cout<<a2 + 1<<'\n';
    }

    


    return 0;
}