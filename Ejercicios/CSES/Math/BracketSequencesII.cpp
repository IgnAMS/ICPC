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

ll mod = 1e9+7;
ll binpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll inv(ll a) { return binpow(a, mod - 2); }


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    if(n & 1) {
        cout<<"0\n";
        return 0;
    }
    string s; cin>>s;
    int k = s.length();
    ll count = 0;
    for(auto u: s) {
        count += (u=='('? 1: -1);
        if(count < 0) break;
    }
    if(count < 0 or n - k < count or (n - k - count) % 2 != 0) {
        cout<<"0\n";
        return 0;
    }

    ll sobra = (n - k - count);
    int Fact[2000002]; 
    Fact[0] = 1;
    repx(i, 1, 2000002) Fact[i] = int(((ll)Fact[i - 1] * (ll)i) % mod);
    ll ans = (count + 1) * inv(sobra/2 + count + 1) % mod;
    ans = ans * Fact[sobra + count] % mod;
    ans = ans * inv(Fact[sobra/2]) % mod * inv(Fact[sobra/2 + count]) % mod;
    cout<<ans<<'\n';

    return 0;
}