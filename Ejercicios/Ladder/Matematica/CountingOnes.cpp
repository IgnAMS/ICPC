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


ll ones(ll x) {
    ll ans = 0;
    rep(i, 63) {
        ll bit = 0;
        ll b = (x - ((1LL << i) - 1)) / (1LL << (i + 1));
        bit = b * (1LL<<i) + min((1LL<<i), max(0LL, x - (b * (1LL<<(i + 1)) + (1LL<<i) - 1)));
        // cerr<<b<<' '<<min((1LL<<i), max(0LL, x - (b * (1LL<<(i + 1)) + (1LL<<i) - 1)))<<'\n';
        // cerr<<bit<<'\n';
        ans += bit;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll a, b; 
    while(cin>>a>>b) {
        cout<<ones(b) - ones(a - 1)<<'\n';
    }
    return 0;
}