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

int n;
ll A[200005];
vl G[200005];

// min{ max(D[l] + X[l]):  sum X[l] = A[i]}  -> actualizar las hojas


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    repx(i, 1, n) {
        int p; cin>>p; p--;
        G[p].pb(i); 
    }
    rep(i, n) cin>>A[i];

    ll C[n], S[n];
    ll ans = 0;
    for(int u = n - 1; u >= 0; u--) {
        S[u] = A[u], C[u] = (G[u].size() == 0);
        
        for(auto v: G[u]) S[u] += S[v], C[u] += C[v];
        ans = max(ans, (S[u] + C[u] - 1) / C[u]);
    }
    cout<<ans<<'\n';

    return 0;
}