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
// g++ -O2 I.cpp && time ./a.out <input.txt> output.txt


ll generate_random() {
    ll num = 0;
    ll pot = 1;
    rep(i, 11) {
        ll d = rand() % 10;
        num += d * pot;
        pot *= 10;
    }
    return num;
}

const ll MOD = 1e9+7;
ll binpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    vl A(n), B(n);
    rep(i, n) cin>>A[i];
    rep(i, n) cin>>B[i];

    map<ll, ll> mp;
    set<ll> S;
    srand(time(0));
    rep(i, n) {
        if(!mp.count(A[i])) {
            ll val = generate_random();
            while(S.count(val)) val = generate_random();
            mp[A[i]] = val;
            S.insert(val);
        }
    }
    
    map<ll, ll> cont;
    ll H1 = 0, H2 = 0;
    rep(i, n) {
        if(!cont.count(H1 - H2)) cont[H1 - H2] = 0;
        cont[H1 - H2]++;
        H1 += mp[A[i]], H2 += mp[B[i]];
    }
    ll ans = 0;
    for(auto& [a, b]: cont) {
        ans += (binpow(2, b) - b - 1 + MOD) % MOD;
        if(ans >= MOD) ans -= MOD;
    }
    cout<<ans<<'\n';

    return 0;
}