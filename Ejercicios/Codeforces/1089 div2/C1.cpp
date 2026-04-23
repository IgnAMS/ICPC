#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<iostream>
#include <algorithm>
#include <numeric>
#include<set>
#include<array>
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
// g++ -std=c++17 A.cpp -o a && ./a <input.txt> output.txt   
// ulimit -s 1000000
// g++ -std=c++17 -O2 C1.cpp && time ./a.out <input.txt> output.txt

const int mxN = 2e5+10;
int n, A[mxN], B[mxN];

void solve() {
    cin>>n;
    rep(i, n) cin>>A[i];
    rep(i, n) cin>>B[i];
    
    ll ans = 0;
    rep(i, n) {
        int gcd_left = 1, gcd_right = 1;
        if(i > 0) gcd_left = gcd(A[i-1], A[i]); 
        if(i+1 < n) gcd_right = gcd(A[i], A[i+1]); 
        ll aux = 1LL * gcd_left * gcd_right / gcd(gcd_left, gcd_right);
        if(aux != A[i]) ans++;
    }
    cout<<ans<<"\n";
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();    

    return 0;
}