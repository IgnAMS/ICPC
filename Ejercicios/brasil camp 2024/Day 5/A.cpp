#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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


bool check3(ll u, ll p) {
    V[u] = 1;
    for(auto v: G[u]) if(v != p) {
        if(p != -1 and G[p].count(u)) return false;
        if(!V[v]) dfs(v, u);
    }
    return true;
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll A[n], C[n];
    rep(i, n) {
        cin>>A[i]>>C[i];
    }

    set<vl> S;
    rep(i, n) {
        S.insert({A[i], 0, i});
        S.insert({A[i] + C[i], 1, i});
    }
    for(auto u: S) cout<<u[2] + 1<<' '<<u[0]<<' '<<u[1]<<'\n';
    


    return 0;
}