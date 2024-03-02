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
ll binpow(ll a, ll b, ll M = 1e9+7) {
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
    ll p1 = (n * n + 3) / 4;
    ll p2 = (n * (n - 1)) / 2 + (n + 1) / 2;
    ll p3 = p1;
    ll p4 = n * n;

    ll ans = (binpow(2, p1) + binpow(2, p2) + binpow(2, p3) + binpow(2, p4)) % mod;
    ans = (ans * binpow(4, mod - 2)) % mod;
    cout<<ans<<'\n';






    return 0;
}