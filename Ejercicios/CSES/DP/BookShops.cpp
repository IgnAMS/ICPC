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
    ll n, x; cin>>n>>x;
    ll H[n], S[n]; 
    rep(i, n) cin>>H[i];
    rep(i, n) cin>>S[i];

    ll DP[x + 1];
    DP[0] = 0;
    rep(i, x + 1) DP[i] = 0; 


    rep(i, n) {
        for(int j = x; j >= H[i]; j--) {
            DP[j] = max(DP[j], DP[j - H[i]] + S[i]);
        } 
    } 

    cout<<DP[x]<<'\n';



    return 0;
}