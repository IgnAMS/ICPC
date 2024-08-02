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

ll minv(ll x) {
    return binpow(x, MOD - 2);
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;

    ll F[100005];
    F[0] = 1;
    repx(i, 1, 100005) F[i] = ll(i) * F[i - 1] % MOD;

    while(t--) {
        int n; cin>>n;
        string s; cin>>s;
        ll cnt1 = 0, cnt0 = 0;
        rep(i, n) {
            if(s[i] == '0') cnt0++;
            if(i + 1 < n and s[i] == '1' and s[i + 1] == '1') cnt1++, i++;
        }
        ll ans = F[cnt1 + cnt0];
        ans = (ans * minv(F[cnt1])) % MOD;
        ans = (ans * minv(F[cnt0])) % MOD;
        cout<<ans<<'\n';
    }

    return 0;
}