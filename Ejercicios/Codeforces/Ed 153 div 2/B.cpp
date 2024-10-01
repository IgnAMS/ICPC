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
    int t; cin>>t;
    while(t--) {
        ll m, k, a1, ak; cin>>m>>k>>a1>>ak;
        if(a1 >= m or (ak * k >= m and m % k == 0)) {
            cout<<0<<'\n';
            continue;
        }
        if(ak >= (m / k) and a1 >= m - (m/k) * k) {
            cout<<0<<'\n';
            continue;
        }
        if(ak < (m / k) and a1 >= m - ak * k) {
            cout<<0<<'\n';
            continue;
        }
        // a1 + ak * k < m;
        // a1 + ak * k >= m pero a1 + (m / k) * k < m
        ll aux = min(ak, (m / k));
        ll x1 = (m - a1 - aux * k) / k;
        ll x2 = (m - a1 - (aux + x1) * k);
        ll ans = x1 + x2;
        if(a1 + x2 >= k) {
            ans = min(ans, x1 + (ak <= aux));
        }
        // cout<<x1<<' '<<x2<<'\n';
        
        cout<<ans<<'\n';
    }

    return 0;
}