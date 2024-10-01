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
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

vector<vi> G;
ll ans;
bool dfs(int u, int p, bool impar) {
    ll contimp = 0, contpar = 0;
    for(auto v: G[u]) if(v != p) {
        ll x = dfs(v, u, !impar);
        contimp += x, contpar += 1 - x;
    }
    if(!impar) {
        ans -= contpar - 1 + bool(contimp);
        return bool(contimp);
    }
    ans -= contimp - 1 + bool(contpar);
    return 1 - bool(contpar);
}




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        G.assign(n, vi());
        rep(i, n - 1) {
            int u, v; cin>>u>>v; u--, v--;
            G[u].push_back(v); G[v].push_back(u);
        }
        ans = 0;
        dfs(0, -1, 0);
        cout<<ans<<'\n';
    }


    return 0;
}