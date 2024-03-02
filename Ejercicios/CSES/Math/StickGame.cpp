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

ll DP[1000001];
vl P;
ll dp(ll i) {
    if(DP[i] != -1) return DP[i];
    ll pos = 0;
    for(auto u: P) if(i - u >= 0) pos = pos or !dp(i - u);
    return DP[i] = pos;
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    P.assign(k,0); rep(i, k) cin>>P[i];
    memset(DP, -1, sizeof(DP));
    repx(i, 1, n + 1) cout<<(dp(i)? 'W': 'L'); cout<<'\n';


    return 0;
}