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


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, x; cin>>n>>x;
    ll A[n]; rep(i, n) cin>>A[i];
    
    map<ll, ll> mp;
    mp[0] = 1;
    ll ans = 0, acc = 0;
    rep(i, n) {
        acc += A[i];
        ans += mp[acc - x];
        mp[acc]++;
    }
    cout<<ans<<'\n';


    return 0;
}