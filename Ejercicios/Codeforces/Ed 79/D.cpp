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

const ll MOD = 998244353;

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



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // cout<<(5LL * minv(8) % MOD)<<'\n';
    int n; cin>>n;
    vector<vl> A(n);
    map<ll, ll> mp;
    rep(i, n) {
        int k; cin>>k;
        rep(j, k) {
            ll x; cin>>x;
            A[i].pb(x);
            if(!mp.count(x)) mp[x] = 0;
            mp[x]++;
        }
    }

    ll ans = 0;
    rep(i, n) {
        ll curr = 0;
        rep(j, A[i].size()) {
            ll val = mp[A[i][j]] * minv(n) % MOD;
            val = val * minv(A[i].size()) % MOD;
            curr += val;
            curr %= MOD;
        }
        ans += curr * minv(n) % MOD;
        ans %= MOD;
    }
    cout<<ans<<'\n';




    return 0;
}