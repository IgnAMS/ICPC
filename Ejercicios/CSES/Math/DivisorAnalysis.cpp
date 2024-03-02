#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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

const ll mod = 1e9+7;
const ll mod2 = 1e9+6;

ll binpow(ll a, ll b, ll M = mod) {
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    vl P(n), K(n); rep(i, n) cin>>P[i]>>K[i];
    ll div = 1, div2 = 1;
    ll flag = 0;
    rep(i, n) {
        div = (div * (K[i] + 1)) % mod;
        if(K[i] % 2 == 1 and !flag) {
            div2 = (div2 * (K[i] + 1) / 2) % mod2;
            flag = 1;
        }
        else div2 = (div2 * (K[i] + 1)) % mod2;
    }

    ll suma = 1;
    rep(i, n) {
        ll inv = binpow(P[i] - 1, mod - 2);
        ll x = ((binpow(P[i], K[i] + 1)-1+mod)%mod * inv) % mod;
        suma = (suma * x) % mod;
    }

    ll prod = 1;
    rep(i, n) {
        ll pot;
        if(flag) pot = (K[i] * div2 % mod2);
        else pot = (K[i]/2 * div2 % mod2);
        ll x = binpow(P[i], pot);
        prod = (prod * x) % mod;
    }

    cout<<div<<' '<<suma<<' '<<prod<<'\n';

    return 0;
}