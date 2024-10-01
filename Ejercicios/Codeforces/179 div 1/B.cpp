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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll D[n][n]; rep(i, n) rep(j, n) cin>>D[i][j];
    vl X(n); 
    rep(i, n) {
        cin>>X[i];
        X[i]--;
    }
    reverse(X.begin(), X.end());
    
    vl Ans;
    rep(k, n) {
        rep(i, n) rep(j, n) {
            D[i][j] = min(D[i][j], D[i][X[k]] + D[X[k]][j]);
        }
        ll curr = 0;
        rep(i, k + 1) rep(j, k + 1) {
            curr += D[X[i]][X[j]];
        }
        Ans.pb(curr);
    }
    reverse(Ans.begin(), Ans.end());
    for(auto u: Ans) cout<<u<<' '; cout<<'\n';


    return 0;
}