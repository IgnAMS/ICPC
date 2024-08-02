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
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll minv(ll x) {
    return binpow(x, MOD - 2);
}

const int mxN = 100005;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vl Div[mxN];
    for(ll i = 1; i < mxN; i++) {
        for(ll j = i; j < mxN; j += i) {
            Div[j].pb(i);
        }
    }
    
    vl lpf(mxN), mob(mxN);
    rep(i, mxN) lpf[i] = 0;
    for(int i = 2; i < mxN; i++) if(!lpf[i]) {
        for(int j = i; j < mxN; j += i) {
            if(!lpf[j]) lpf[j] = i;
        }
    }
    
    for(int i = 1; i < mxN; i++) {
        if(i == 1) mob[i] = 1; 
        else {
            if(lpf[i / lpf[i]] == lpf[i]) mob[i] = 0;
            else mob[i] = -1 * mob[i / lpf[i]];
        }
    }

    vl sumcoprime(mxN, 0);
    for(int x = 2; x < mxN; x++) {
        for(auto g: Div[x]) {
            ll y = x / g;
            sumcoprime[x] = (sumcoprime[x] + mob[g] * (y - 1) + MOD) % MOD;
        }
    }
    int n; cin>>n;
    ll ans = 0;
    for(auto g: Div[n]) {
        ll x = n / g;
        for(ll c = 1; c <= x - 2; c++) {
            for(auto g2: Div[x - c]) {
                if(__gcd(g2, c) != 1) continue;
                ll y = (x - c) / g2;
                if(y <= 1) continue;
                ll aux = (c * g2) % MOD;
                aux = (aux * g) % MOD;
                aux = (aux * sumcoprime[y]) % MOD;
                
                ans += aux;
                ans %= MOD;
            }
        }
    }
    cout<<ans<<'\n';


    return 0;
}