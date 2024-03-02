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

ll mod = 1e9+7;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll n; cin>>n;
        ll lcm = 1;
        ll g = 1;
        ll ans = 0;
        for(ll i = 2; n > 0; i++) {
            ll y = i / __gcd(i, lcm);
            // cout<<n<<' '<<i<<' '<<y<<'\n';
            lcm = i * lcm / __gcd(i, lcm);
            ans = (ans + max(0LL, i * (n - n / y))) % mod;
            n /= y;
        }
        cout<<ans<<'\n';
    }

    return 0;
}