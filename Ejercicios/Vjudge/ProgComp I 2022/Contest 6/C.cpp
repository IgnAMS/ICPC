#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt


ll DP[101][101];
ll sum[101];
ll dp(ll l, ll r) {
    if(DP[l][r] != -1) return DP[l][r];
    if(l == r) return 0;
    DP[l][r] = 1000000000000LL;
    repx(i, l, r) {
        ll L = sum[i] - sum[l - 1], R = sum[r] - sum[i];
        DP[l][r] = min(DP[l][r], dp(l, i) + dp(i + 1, r) + ((sum[i] - sum[l - 1]) % 100) * ((sum[r] - sum[i]) % 100));
    } 
    return DP[l][r];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; 
    sum[0] = 0;
    while(cin>>n) {
        memset(DP, -1, sizeof DP);
        vi A(n); rep(i, n) cin>>A[i];
        rep(i, n) sum[i + 1] = sum[i] + A[i];
        cout<<dp(1, n)<<'\n';
    }    

    return 0;
}