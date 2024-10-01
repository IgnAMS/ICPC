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
// g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

vector<vi> G;
vi C;
vi X, L, R;
void dfs(int u, int p) {
    L[u] = X.size();
    X.push_back(C[u]);
    for(auto v: G[u]) if(v != p) dfs(v, u);
    R[u] = X.size() - 1;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    G.assign(n, vi()); L.resize(n); R.resize(n);
    C.assign(n, 0); rep(i, n) cin>>C[i];
    rep(i, n - 1) {
        ll u, v; cin>>u>>v; u--, v--;
        G[u].push_back(v); G[v].push_back(u);
    }

    vector<vi> E;
    int sqr = sqrt(n);
    dfs(0, -1);
    rep(i, m) {
        ll v, k; cin>>v>>k; v--;
        E.push_back({L[v] / sqr, L[v], R[v], k, i});
    }
    sort(E.begin(), E.end(), [](const auto& a, const auto& b){
        return (a[0] != b[0]? a[1] < b[1]: a[2] < b[2]);
    });
    
    vi Ans(m, 0);
    vi F(100002, 0), Q(n + 2, 0); 
    int l = 0, r = 0;
    F[X[0]]++; Q[F[X[0]]]++;
    rep(i, m) {
        while(l > E[i][1]) l--, F[X[l]]++, Q[F[X[l]]]++;
        while(r < E[i][2]) r++, F[X[r]]++, Q[F[X[r]]]++;
        while(l < E[i][1]) Q[F[X[l]]]--, F[X[l]]--, l++;
        while(r > E[i][2]) Q[F[X[r]]]--, F[X[r]]--, r--;
        // cout<<l<<' '<<r<<'\n';
        // for(auto u: Q) cout<<u<<' '; cout<<'\n';
        if(E[i][3] <= n) Ans[E[i][4]] = Q[E[i][3]];
    }
    rep(i, m) cout<<Ans[i]<<'\n';
    





    return 0;
}