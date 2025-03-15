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

ll minv(ll x) { return binpow(x, MOD - 2); }

const int mxN = 1e6+6;

ll F[mxN];
ll good[mxN * 10];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll a, b, n; cin>>a>>b>>n;
    F[0] = 1;
    repx(i, 1, mxN) F[i] = 1LL * F[i - 1] * i % MOD;

    good[0] = 1;
    repx(i, 1, mxN * 10) {
        ll d = i % 10;
        if((d == a or d == b) and good[i / 10]) good[i] = 1;
    }


    ll ans = 0;
    rep(i, n + 1) {
        ll suma = a * i + b * (n - i);
        // cout<<suma<<' '<<good[suma]<<'\n';
        if(good[suma]) {
            ans += (F[n] * minv(F[n - i]) % MOD) * minv(F[i]) % MOD;
            ans %= MOD;
        }
    }
    cout<<ans<<'\n';


    return 0;
}