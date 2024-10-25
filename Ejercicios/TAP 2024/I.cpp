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

int n, m, cont = 0;
ll S[1005][1005];
vector<pll> G[2005];
ll V[2000005];

vl X;
void dfs(int u) {
    while(!G[u].empty()) {
        auto [v, id] = G[u].back();
        G[u].pop_back();
        if(V[id]) continue;
        V[id] = 1;
        dfs(v);
    }
    X.pb(u);
}

bool euler_path() {
    cont = 0;
    rep(u, n) rep(v, m) if(S[u][v] == -1) {
        G[n + v].pb({u, cont});
        G[u].pb({n + v, cont++});
    }
    int first = -1;
    rep(i, n + m) if(G[i].size()) first = i;
    int v1 = -1, v2 = -1;
    rep(u, n + m) {
        if(G[u].size() & 1) {
            if(v1 == -1) v1 = u;
            else if(v2 == -1) v2 = u;
            else return 0;
        }
    }
    if(v1 != -1) G[v1].pb({v2, cont}), G[v2].pb({v1, cont++});
    dfs(first);
    // si es que hay alguno que no ha sido vistiado entonces devuelvo 0
    rep(i, cont) if(!V[i]) return 0;
    if(v1 != -1) {
        rep(i, X.size() - 1) {
            if((X[i] == v1 and X[i + 1] == v2) or (X[i] == v2 and X[i + 1] == v1)) {
                vl X2;
                repx(j, i + 1, X.size()) X2.pb(X[j]);
                repx(j, 1, i + 1) X2.pb(X[j]);
                X = X2;
                break;
            }
        }
    }

    rep(i, X.size() - 1) {
        ll u = X[i], v = X[i + 1];
        if(u >= n) swap(u, v);
        v -= n;
        S[u][v] = i + 1;
    }
    return 1;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i, n) rep(j, m) {
        string s; cin>>s;
        if(s == ".") S[i][j] = -1;
        else S[i][j] = 0;
    }
    if(euler_path()) {
        rep(i, n) {
            rep(j, m) cout<<S[i][j]<<' '; cout<<'\n';
        }
    }
    else cout<<"*\n";


    return 0;
}