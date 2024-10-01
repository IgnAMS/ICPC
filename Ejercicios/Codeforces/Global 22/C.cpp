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
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int imp[102][102], par[102][102];
ll dp(int imps, int pars, int m) { // m = 1 quiero sacar impar
    if(imps < 0 or pars < 0) return 1; // no factible
    // cout<<"entre a "<<imps<<' '<<pars<<' '<<m<<'\n';
    if(m and imp[imps][pars] != -1) return imp[imps][pars];
    if(!m and par[imps][pars] != -1) return par[imps][pars];
    if(m) return imp[imps][pars] = max(
        min({
            dp(imps - 2, pars, 0),
            dp(imps - 1, pars - 1, 0), 
            ll(imps >= 2 or (imps >= 1 and pars >= 1)) // niniguno factible -> 0
        }), 
        min({
            dp(imps, pars - 2, 1),
            dp(imps - 1, pars - 1, 1), 
            ll(pars - 2 >= 0 or (pars >= 1 and imps >= 1))
        })
    );
    return par[imps][pars] = max(
        min({
            dp(imps - 2, pars, 1),
            dp(imps - 1, pars - 1, 1), 
            ll(imps >= 2 or (imps >= 1 and pars >= 1))
        }), 
        min({
            dp(imps, pars - 2, 0),
            dp(imps - 1, pars - 1, 0), 
            ll(pars >= 2 or (pars >= 1 and imps >= 1))
        })
    );
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    rep(i, 101) rep(j, 101) imp[i][j] = par[i][j] = -1;
    imp[0][0] = 0;
    par[0][0] = 1;
    imp[0][1] = 0, imp[1][0] = 1;
    par[0][1] = 1, par[1][0] = 0;
    
    ll x = dp(1, 4, 1), y = dp(2, 3, 1);
    // cout<<dp(0, 3, 0)<<' '<<(1, 2, 1)<<'\n';
    // cout<<(-5 % 2)<<' '<<(-4 % 2)<<'\n';
    while(t--) {
        int n; cin>>n;
        vi A(n); rep(i, n) cin>>A[i];
        ll imps = 0, pars = 0;
        rep(i, n) imps += (abs(A[i] % 2) == 1);
        rep(i, n) pars += (A[i] % 2 == 0);
        ll ans = dp(imps, pars, 0);
        cout<<(ans? "Alice\n": "Bob\n");
    }


    return 0;
}