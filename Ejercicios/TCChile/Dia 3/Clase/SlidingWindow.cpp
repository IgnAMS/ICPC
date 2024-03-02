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
    int n, k; cin>>n>>k;
    rep(i, n) cin>>A[i];
    ll l = 0, r = k, curr = 0;
    rep(i, k) curr += A[i]; 
    ll ans = -1e10; 
    for(int i = k; i < n; i++) {
        curr += A[i] - A[l];
        l++;
        ans = max(ans, curr);
    }
    cout<<ans<<'\n';

    return 0;
}