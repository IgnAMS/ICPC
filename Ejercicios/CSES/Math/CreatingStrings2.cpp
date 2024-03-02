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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    vl S(27, 0);
    for(auto c: s) S[c - 'a']++;
    ll Fact[1000007]; 
    Fact[0] = 1;
    repx(i, 1, 1e6 + 2) Fact[i] = (Fact[i - 1] * ll(i)) % mod;
    ll ans = Fact[s.size()];
    rep(i, 27) {
        ans = (ans * binpow(Fact[S[i]], mod - 2)) % mod;
    }
    cout<<ans<<'\n';

    return 0;
}