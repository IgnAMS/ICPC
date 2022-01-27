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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b; cin>>n>>m>>a>>b;
    vector<set<int>> G(n);
    rep(i, m) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].insert(v); G[v].insert(u);
    }

    set<ii> S;
    rep(u, n) S.insert({G[u].size(), u});
    int size = n;
    ll cont = 0;
    while(!S.empty() and ((*S.begin()).ff < a or S.size() - (*S.rbegin()).ff - 1 < b)) {
        int u, d1; tie(d1, u) = *S.begin();
        int v, d2; tie(d2, v) = *S.rbegin();
        if(d1 < a) {
            for(auto x: G[u]) {
                S.erase(S.find(ii(G[x].size(), x)));
                S.insert(ii(G[x].size() - 1, x)); 
                G[x].erase(u);
            }
            S.erase(S.find(ii(d1, u)));
        }
        else if(S.size() - d2 - 1 < b) {
            for(auto x: G[v]) {
                S.erase(S.find(ii(G[x].size(), x)));
                S.insert(ii(G[x].size() - 1, x)); 
                G[x].erase(v); 
            }
            S.erase(S.find(ii(d2, v)));
        }
    }

    cout<<S.size()<<'\n';





    return 0;
}