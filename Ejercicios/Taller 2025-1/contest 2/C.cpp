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
    ll n, k; cin>>n>>k;
    ll A[n]; rep(i, n) cin>>A[i];
    ll B[n]; rep(i, n) cin>>B[i];

    ll l = 0, r = 2e9;
    while(l < r) {
        ll m = (l + r + 1) / 2;
        ll faltan = 0;
        rep(i, n) {
            faltan += max(0LL, m * A[i] - B[i]);
            if(faltan > k) break;
        }
        if(faltan <= k) l = m;
        else r = m - 1;
    }
    cout<<l<<'\n';

    return 0;
}