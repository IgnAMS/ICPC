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

vector<vi> T;
vi D, maxD;
vi L; // hojas
ll dfs(int u, int p, int d) {
    maxD[u] = d;
    D[u] = d;
    for(auto v: T[u]) if(v != p) maxD[u] = max(maxD[u], dfs(v, u, d + 1));
    if(T[u].size() == 1 and u != 0) L.push_back(D[u]);
    return maxD[u];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        T.assign(n, vi()); D.resize(n); L.clear(); maxD.resize(n);
        rep(i, n - 1) {
            int u, v; cin>>u>>v; u--, v--; 
            T[u].push_back(v); T[v].push_back(u);
        }
        dfs(0, -1, 0);
        sort(L.begin(), L.end());
        for(auto u: maxD) cout<<u<<' '; cout<<'\n';
        // for(auto x: L) cout<<x<<' '; cout<<'\n';
        repx(x, 1, n + 1) {
            ll ans = L.back();
            rep(i, n) ans = min(ans, max(maxD[i] - x, D[i]));
            ll d1 = L.back(), d2 = (L.size() == 1? 0: L[L.size() - 2]);
            cout<<min(max((d1 - x) / 2 + x, d2), L.back())<<' ';
        }
        cout<<'\n';
    }



    return 0;
}