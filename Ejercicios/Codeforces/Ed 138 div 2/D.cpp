#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(ll i=a; i<b; i++)
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

ll n, m;
const ll MOD = 998244353;

ll binpow(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while(b) {
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    ll ans = 0;
    repx(i, 1, n + 1) {
        ans += binpow(m % MOD, i);
        ans %= MOD;
    }
    
    vl P(300005, 1);
    for(ll i = 2; i <= 300004; i++) {
        if(!P[i]) continue;
        for(ll j = 2 * i; j <= 300004; j += i) P[j] = 0;
    } 
    
    ll aux = 1;
    ll div = 1;
    for(ll i = 1; i <= n; i++) {
        if(P[i]) div = (i * div);
        if(div > m) break;
        aux = (aux * ((m / div) % MOD)) % MOD;
        ans = ((ans - aux) % MOD + MOD) % MOD;
    }
    cout<<ans<<'\n';
    





    return 0;
}