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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string a, b; cin>>a>>b;
    ll n = a.length();
    ll m = b.length();

    vl A;
    rep(i, n) if(a[i] != a[i + 1]) A.pb(i);
    

    ll p = 0; 
    ll ans = 0;
    rep(i, m) if(a[i] != b[i]) p = 1 - p;
    if(p == 0) ans++;
    ll l = 0, r = 0;
    rep(i, m) if(r < A.size() and A[r] <= i) r++;
    for(int i = m; i < n; i++) {
        if((r - l) % 2 == 1) p = 1 - p; // cambio la paridad 
        // cout<<l<<' '<<r<<' '<<p<<'\n';
        ans += (1 - p);
        if(l < A.size() and A[l] < i - m + 1) l++;
        if(r < A.size() and A[r] <= i) r++;
    }
    cout<<ans<<'\n';


    return 0;
}