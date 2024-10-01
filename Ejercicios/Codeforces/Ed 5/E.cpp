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

const ll MOD = 1e9+7;
ll binpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}
ll minv(ll a) {
    return binpow(a, MOD - 2);
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin>>n>>m;
    ll x = 1;
    ll ans = 0;
    for(; x * x <= n and x <= m; x++) {
        ans += n % x;
        ans %= MOD;
    }

    ll curr = x;
    // 100 / 17 = 5
    // 100 / 5 = 20
    ll minv2 = minv(2LL);
    ll iters = 0;
    while(curr <= n and curr <= m) {
        ll div = n / curr;
        ll next = n / div;
        if(next > m) next = m;
        // cout<<curr<<' '<<next<<' '<<div<<'\n';
        ll largo = (next - curr + 1) % MOD;
        // cout<<((n % curr) * largo - div * largo * (largo - 1) / 2)<<'\n';
        
        div = div % MOD;
        ll suma = ((n % curr) % MOD) * (largo % MOD) % MOD;
        ll resta = ((div * largo % MOD) * (((largo - 1 + MOD) * minv2) % MOD)) % MOD;
        ll val = (suma - resta + MOD) % MOD;
        // cout<<suma<<' '<<resta<<' '<<val<<'\n';
        
        ans += val;
        ans %= MOD;
        curr = next + 1;
    }

    // cout<<curr<<' '<<m<<' '<<n<<'\n';
    if(curr <= m) {
        ll val = ((m - n) % MOD) * (n % MOD);
        // cout<<(m - n) * n<<'\n';
        // cout<<val<<'\n';
        val %= MOD;
        ans += val;
        ans %= MOD;
    }

    // ll real_ans = 0;
    // repx(i, 1, m + 1) {
    //     real_ans += n % i;
    //     real_ans %= MOD;
    // }
    // cout<<real_ans<<'\n';
    
    cout<<ans<<'\n';

    return 0;
}