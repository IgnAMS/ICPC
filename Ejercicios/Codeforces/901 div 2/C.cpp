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


ll solve(ll n, ll m) {
    if(n == 1) return m - 1;
    // cout<<"resuelvo "<<n<<' '<<m<<'\n';
    ll ans = 0;
    ll g = __gcd(n, m);
    rep(i, 30) {
        if(n & (1LL<<i)) {
            ll g = __gcd(n & (1LL<< i), m);
            ans += solve((n & (1LL<<i)) / g, m / g) * g;
        }
    } 
    return ans;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll n, m; cin>>n>>m;
        ll g = __gcd(n, m);
        n = n / g, m = m / g;
        if(m == 1) {
            cout<<"0\n";
            continue;
        }
        ll numdivs = 0, div = 1;
        rep(i, 30) {
            if(m & (1LL<<i)) numdivs++, div = i;
        }
        if(numdivs > 1) {
            cout<<"-1\n";
            continue;
        }
        n %= m;
        // cout<<n<<' '<<m<<'\n';
        cout<<solve(n, m) * g<<'\n';


    }


    return 0;
}