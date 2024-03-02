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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<pll> x(n); 
    rep(i, n) cin>>x[i].ff>>x[i].ss;
    // rep(i, n) x[i].ss *= -1;
    sort(x.begin(), x.end());
    // rep(i, n) x[i].ss *= -1;
    
    vl LIS(n + 1, 1e10);
    ll ans = 0;
    rep(i, n) {
        ll ind = upper_bound(LIS.begin(), LIS.end(), x[i].ff - x[i].ss) - LIS.begin();
        if(LIS[ind] > x[i].ff + x[i].ss) LIS[ind] = x[i].ff + x[i].ss;
        // cout<<x[i].ff<<' '<<x[i].ss<<' '<<ind<<'\n';
        ans = max(ans, ind + 1);
    }
    cout<<ans<<'\n';
    return 0;
}