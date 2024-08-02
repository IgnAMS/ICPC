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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, d, e; cin>>n>>d>>e;
    ll ans = 0;
    e *= 5;
    
    rep(i, n / d + 1) {
        ll x = n - ll(i) * d;
        ll y = x / e;
        ans = max(ans, i * d + y * e);
    }
    rep(i, n / e + 1) {
        ll x = n - ll(i) * e;
        ll y = x / d;
        ans = max(ans, i * e + y * d);
    }

    cout<<n - ans<<'\n';
    return 0;
}