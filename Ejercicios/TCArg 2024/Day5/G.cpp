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



ll DP[10][2][2];
ll Digits[10];
ll digits = 0;

ll dp(ll i, ll b, ll init) {
    if(i == -1) return 1;
    if(DP[i][b][init] != -1) return DP[i][b][init];
    if(b == 1) {
        DP[i][b][init] = 0;
        rep(d, Digits[i]) {
            DP[i][b][init] = max({
                DP[i][b][init], 
                dp(i - 1, 0, init or (d > 0)) * ((init or d > 0)? d: 1LL)
            });
        }
        DP[i][b][init] = max(DP[i][b][init], dp(i - 1, 1, 1) * Digits[i]);   
    }
    else {
        DP[i][b][init] = 0;
        rep(d, 10) {
            DP[i][b][init] = max(
                DP[i][b][init], 
                dp(i - 1, 0, init or (d > 0)) * ((init or d > 0)? d: 1LL)
            );
        }
    }
    return DP[i][b][init];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    while(n) {
        Digits[digits] = n % 10;
        n /= 10;
        rep(b, 2) rep(init, 2) DP[digits][b][init] = -1;
        digits++;
    }
    cout<<dp(digits - 1, 1, 0)<<'\n';

    return 0;
}