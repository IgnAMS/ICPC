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


const ll MOD = 998244353;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll A[n]; rep(i, n) cin>>A[i];
    ll B[n]; rep(i, n) cin>>B[i];

    int m; cin>>m;
    ll C[m]; rep(i, m) cin>>C[i];
    ll D[m]; rep(i, m) cin>>D[i];

    set<ll> S;
    rep(i, n) S.insert(A[i]);
    rep(i, m) S.insert(C[i]);

    
    map<ll, ll> mp1, mp2;
    rep(i, n) mp1[A[i]] = B[i];
    rep(i, m) mp2[C[i]] = D[i];

    
    ll ans = 1;
    rep(i, m) if(!mp1.count(C[i]) or mp1[C[i]] < mp2[C[i]]) ans = 0;
    for(auto u: S) {
        if(!mp2.count(u)) ans = ans * 2;
        else if(mp1[u] != mp2[u]) ans = ans * 2;
        if(ans >= MOD) ans -= MOD;
    }
    cout<<ans<<'\n';

    return 0;
}