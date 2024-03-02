#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;

#define rep(i, n) for(int i = 0; i<(int)n; ++i)

const int mxN = 50;

int n, dp[mxN][2][2], a[mxN];

int main(){
    memset(dp, 0, sizeof(dp)); 
    cin >> n;
    int sum = 0;
    rep(i, n){
        cin >> a[i];
        sum += a[i];
    }
    dp[0][0][1] = a[0];
    int fff = a[0];
    for(int i = 1; i<n; ++i){
        fff += a[i];
        rep(who, 2){
            dp[i][who][1] = max(dp[i-1][who][0], fff-dp[i-1][who^1][1]) + a[i];
            dp[i][who][0] = max(dp[i-1][who][0], fff-dp[i-1][who^1][1]);
        }
    }
    cout << max(dp[n-1][0][1], dp[n-1][0][0]) << " " << sum - max(dp[n-1][0][1], dp[n-1][0][0]);

}


// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 G.cpp && time ./a.out <input.txt> output.txt
