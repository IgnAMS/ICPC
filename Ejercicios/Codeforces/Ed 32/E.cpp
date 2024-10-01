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
    ll n, m; cin>>n>>m;
    ll A[n]; rep(i, n) cin>>A[i];
    set<ll> S1, S2;
    ll ans = 0;
    rep(mask, 1<<(n/2)) {
        ll suma = 0;
        rep(j, n/2) if(mask & (1<<j)) suma += A[j];
        suma %= m;
        ans = max(ans, suma);
        S1.insert(suma);
    }
    rep(mask, 1<<((n+1)/2)) {
        ll suma = 0;
        rep(j, (n+1)/2) if(mask & (1<<j)) suma += A[n/2 + j];
        suma %= m;
        ans = max(ans, suma);
        S2.insert(suma);
    }

    S1.insert(0); S2.insert(0);
    for(auto u: S1) {
        auto it = S2.lower_bound(m - u);
        if(it != S2.begin()) {
            it--;
            ans = max(ans, u + *it);
        }
    }
    for(auto u: S2) {
        auto it = S1.lower_bound(m - u);
        if(it != S1.begin()) {
            it--;
            ans = max(ans, u + *it);
        }
    }
    cout<<ans<<'\n';

    return 0;
}