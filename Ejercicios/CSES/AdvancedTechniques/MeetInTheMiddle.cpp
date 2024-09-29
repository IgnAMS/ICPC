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

unordered_map<ll, ll> mp1;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, x; cin>>n>>x;
    ll A[n]; rep(i,n) cin>>A[i];
    mp1.reserve(1000000);

    rep(mask, (1<<(n/2))) {
        ll suma = 0;
        rep(j, n/2) if(mask & (1LL<<j)) suma += A[j];
        mp1[suma]++;
    }

    ll ans = 0;
    rep(mask, (1<<((n+1)/2))) {
        ll suma = 0;
        rep(j, (n+1)/2) if(mask & (1LL<<j)) suma += A[n/2 + j];
        ans += mp1[x - suma];
    }
    cout<<ans<<'\n';

    return 0;
}