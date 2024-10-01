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
    int t; cin>>t;
    while(t--) {
        map<ll, ll> mp;
        ll n, m; cin>>n>>m;
        ll A[n];
        rep(i, n) cin>>A[i];
        rep(i, n) cin>>mp[A[i]];
        ll ans = 0;
        
        for(auto [coin, cont]: mp) {
            ll k1 = min(m / coin, mp[coin]);
            ans = max(ans, k1 * coin);
            if(mp.count(coin + 1)) {
                ll k2 = min((m - k1 * coin) / (coin + 1), mp[coin + 1]);
                // x cambio de k2 a k1, se elige el menor entre 
                // lo que me sobra
                // los que me sobran de k2
                // lo que use en k1
                ll x = min({
                    m - k1 * coin - k2 * (coin + 1), 
                    mp[coin + 1] - k2, 
                    k1
                });
                k1 -= x;
                k2 += x;
                ans = max(ans, k1 * coin + k2 * (coin + 1));
            }
        }
        cout<<ans<<'\n';
    }






    return 0;
}