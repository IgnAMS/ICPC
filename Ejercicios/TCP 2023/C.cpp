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

const int mxN = 1e5+5;
vl Ans(mxN, 1e10);
vl D(mxN, 1e10);
bool V[mxN];
ll A[mxN];
vl G[mxN];
void dfs(ll u) {
    V[u] = 1;
    int l = upper_bound(D.begin(), D.end(), A[u]) - D.begin();
    ll upd = -1;
    ll val = -1;
    if(D[l - 1] < A[u] and A[u] < D[l]) { 
        upd = l, val = D[l];
        D[l] = A[u];    
    }
    Ans[u] = prev(lower_bound(D.begin(), D.end(), 1e10)) - D.begin();
    for(auto v: G[u]) if(!V[v]) dfs(v);
    if(upd != -1) D[upd] = val;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i, n - 1) {
        int x; cin>>x; x--;
        G[x].pb(i + 1); G[i + 1].pb(x);
    }
    rep(i, n) cin>>A[i];
    D[0] = 0;
    dfs(0);
    rep(i, n - 1) cout<<Ans[i + 1]<<' '; cout<<'\n';

    return 0;
}