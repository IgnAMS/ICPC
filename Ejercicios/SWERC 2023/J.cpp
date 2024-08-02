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

vl G[100005];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, p; cin>>n>>p;
    rep(i, n - 1) {
        int u, v; cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    } 

    ll hojas = 0;
    rep(u, n) if(G[u].size() == 1) hojas++;

    if(hojas == 0) cout<<p<<'\n';
    else if(p % hojas >= 2) cout<<2 * ((p / hojas) + 1);
    else if(p % hojas == 1) cout<<(p / hojas) + (p / hojas) + 1<<'\n';
    else cout<<2 * (p / hojas)<<'\n';


    return 0;
}