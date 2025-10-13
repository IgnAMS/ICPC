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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k, s; cin>>n>>m>>k>>s;
    vector<vl> G(n + k, vl());
    vl A(n); rep(i, n) cin>>A[i], A[i]--;

    rep(i, m) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v); G[v].pb(u);
        G[n + A[u]].pb(u);
        G[n + A[v]].pb(v);
    }

    vector<vl> D(k, vl(n, -1));
    rep(i, k) {
        vl D2(n, -1);
        deque<ll> q;
        rep(j, n) if(A[j] == i) {
            q.push_back(j);
            D2[j] = 0;
        }
        while(!q.empty()) {
            auto u = q.front();  q.pop_front();
            for(auto v: G[u]) if(D2[v] == -1) {
                D2[v] = D2[u] + 1;
                q.push_back(v);
            }
        }
        D[i] = D2;
    }

    rep(u, n) {
        vl X;
        rep(i, k) X.pb(D[i][u]);
        sort(X.begin(), X.end());
        ll suma = 0;
        rep(i, s) suma += X[i];
        cout<<suma<<' ';
    }
    cout<<'\n';


    return 0;
}