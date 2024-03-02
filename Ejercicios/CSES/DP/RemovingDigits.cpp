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


ll n;
const ll mxN = 1e6+5;
ll DP[mxN];

ll Pot[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 }; 

ll dp(ll x) {
    if(x == 0) return 0;
    if(DP[x] != -1) return DP[x];
    DP[x] = mxN;
    rep(i, 7) {
        ll aux = (x / Pot[i]) % 10;
        // cerr<<aux<<'\n';
        if(aux == 0) continue;
        DP[x] = min(DP[x], dp(x - aux) + 1);
    } 
    return DP[x];
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i, mxN) DP[i] = -1;
    DP[0] = 0;
    repx(x, 1, mxN) {
        DP[x] = mxN;
        rep(i, 7) {
            ll aux = (x / Pot[i]) % 10;
            // cerr<<aux<<'\n';
            if(aux == 0) continue;
            DP[x] = min(DP[x], DP[x - aux] + 1);
        }
    }
    
    cout<<DP[n]<<'\n';


    return 0;
}