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
    int n; cin>>n;
    ll C[n]; rep(i, n) cin>>C[i];

    const ll mxN = 100005;
    ll DP[mxN];
    rep(i, mxN) DP[i] = mxN;
    DP[0] = 0;

    rep(i, n) {
        for(int w = mxN - 1; w >= C[i]; w--) {
            DP[w] = min(DP[w], DP[w - C[i]] + 1);
        }
    }
    vl A; 
    rep(i, mxN) if(i) {
        if(DP[i] < mxN) A.pb(i);
    }

    cout<<A.size()<<'\n';
    for(auto u: A) cout<<u<<' '; cout<<'\n';


    return 0;
}