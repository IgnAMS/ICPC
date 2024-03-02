#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(ll i=a; i<b; i++)
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

vector<set<ll>> G;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    G.assign(n, set<ll>());
    rep(i, m) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].insert(v); G[v].insert(u);    
    }
    ll l = 0, r = n * n;
    int cont = 0;
    while(l < r and cont++ < n * n) {
        ll m = (l + r + 1) / 2;
        set<vl> S;
        vector<set<ll>> G2 = G;
        vector<set<ll>> NG2(n, set<ll>());
        rep(i, n) repx(j, i+1, n) {
            if(!G[i].count(j) and G[i].size() + G[j].size() >= m) {
                S.insert({ll(G[i].size() + G[j].size()), i, j});
            }
            else if(!G[i].count(j)) {
                NG2[i].insert(j); NG2[j].insert(i);
            }
        }
        // cout<<"pruebo con m: "<<m<<'\n';
        while(!S.empty()) {
            auto it = *S.rbegin();
            ll i = (it)[1], j = (it)[2];
            // cout<<"conecto "<<i<<' '<<j<<'\n';
            G2[i].insert(j); G2[j].insert(i);
            
            vl E;
            for(auto k: NG2[i]) if(G2[k].size() + G2[i].size() >= m) {
                S.insert({ll(G2[k].size() + G2[i].size()), min(i,k), max(i,k)});
                E.pb(k);
            }
            for(auto u: E) NG2[i].erase(u);
            E.clear();

            for(auto k: NG2[j]) if(G2[k].size() + G2[j].size() >= m) {
                S.insert({ll(G2[k].size() + G2[j].size()), min(j,k), max(j,k)});
                E.pb(k);
            }

            for(auto u: E) NG2[j].erase(u);
            S.erase(it);
        }
        bool oc = 1;
        rep(i, n) if(G2[i].size() < n - 1) oc = 0;
        if(!oc) r = m - 1;
        else l = m;
    }   
    cout<<l<<'\n';





    return 0;
}