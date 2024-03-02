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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n; 
    ll mod = 1e9+7;
    ll i = 1;
    ll ans = 0;
    while(i <= n) {
        ll div = n / i;
        // quiero next tal que n / next < div = n / i
        ll l = i + 1, r = n + 1;
        while(l < r) {
            ll m = (l + r) / 2;
            if((n / m) < div) r = m;
            else l = m + 1;
        }
        ll next = l;
        // inclusive, exclusive
        // sumatoria de [i, next - 1]
        ll agregar = (((next - 1 + mod) % mod) * (next % mod) / 2) % mod - ((i%mod) * ((i - 1)%mod) / 2) % mod;
        agregar = (agregar + mod) % mod;
        agregar = ((div % mod) * agregar) % mod;
        ans = (agregar + ans) % mod;
        i = next;
    }
    cout<<ans<<'\n';

    return 0;
}