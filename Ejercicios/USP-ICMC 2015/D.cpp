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


// DP[i][last] = max(
//      DP[i + 1][0] + V[i] if last >= 3
//      DP[i + 1][min(last + 1, 3)]
// )


int n; 
ll DP[1000001][4];
ll V[1000001];
ll dp(ll i, ll last) {
    if(i == n) return 0;
    if(DP[i][last] != -1) return DP[i][last];   
    DP[i][last] = dp(i + 1, min(last + 1, 3LL));
    if(last >= 3) DP[i][last] = max(DP[i][last], dp(i + 1, 1) + V[i]);
    // cout<<i<<' '<<last<<' '<<DP[i][last]<<'\n';
    return DP[i][last];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i, n) cin>>V[i];
    rep(i, n) rep(b, 4) DP[i][b] = -1;
    cout<<dp(0, 3)<<'\n';


    return 0;
}