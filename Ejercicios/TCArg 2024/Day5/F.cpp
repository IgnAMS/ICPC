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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vl Ans(n + 1, 0);
    
    vector<vl> X(m, vl());
    rep(i, n) {
        ll s, r; cin>>s>>r; s--;
        X[s].pb(r);
    }
    rep(i, m) {
        sort(X[i].begin(), X[i].end());
        ll acc = 0;
        rep(j, X[i].size()) {
            acc += X[i][X[i].size() - j - 1];
            Ans[j] += max(acc, 0LL);
        }
    }
    ll ans = 0;
    rep(i, n) ans = max(ans, Ans[i]);
    cout<<ans<<'\n';



    return 0;
}