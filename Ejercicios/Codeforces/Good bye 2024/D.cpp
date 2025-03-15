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
    int t; cin>>t;
    while(t--) {
        ll n, q; cin>>n>>q;
        vl A(n), B(n);
        rep(i, n) cin>>A[i];
        rep(i, n) cin>>B[i];

        vl SA(n), SB(n);
        rep(i, n) SA[i] = A[i], SB[i] = B[i];
        sort(SA.begin(), SA.end());
        sort(SB.begin(), SB.end());
        
        multiset<pll> X1, X2;
        rep(i, n) X1.insert({SA[i], SB[i]}), X2.insert({SB[i], SA[i]});

        ll ans = 1;
        rep(i, n) {
            ans = ans * min(SA[i],  SB[i]) % MOD;
        }
        cout<<ans<<' '; 
        while(q--) {
            ll o, x; cin>>o>>x; x--;
            if(o == 2) swap(X1, X2), swap(A, B);
            auto it = X1.lower_bound({A[x] + 1, 0});
            it--;
            auto [a, b] = *it;
            X1.erase(X1.find({a, b}));
            X2.erase(X2.find({b, a}));
            ans = ans * minv(min(a, b)) % MOD;
            ans = ans * min(a + 1, b) % MOD;
            X1.insert({a + 1, b});
            X2.insert({b, a + 1});
            A[x]++;
            if(o == 2) swap(X1, X2), swap(A, B);
            cout<<ans<<' ';
        }
        cout<<'\n';
    }


    return 0;
}