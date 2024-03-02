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
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin>>n>>m;
    int Fact[2000002];
    Fact[0] = 1;
    repx(i, 1, 2000002) Fact[i] = ((ll)Fact[i - 1] * ll(i)) % mod;
    // cout<<Fact[n + m - 1]<<' '<<Fact[n - 1]<<' '<<Fact[m]<<'\n';
    cout<<ll(Fact[n + m - 1]) * binpow(Fact[n - 1], mod - 2) % mod * binpow(Fact[m], mod - 2)% mod<<'\n'; 

    return 0;
}