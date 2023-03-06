#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define ar array
#define rep(i, n) for(int i = 0; i<(int)n; ++i)

const int mxN = 305, M = 1e9+7;
ll dp[mxN], f[mxN], p;
vector<int> primes;
bool a[mxN];
ll cnt = 0;
int n;

int main(){
    memset(dp, 0, sizeof(dp));
    cin >> n;
    ll val = -1;
    for(int i = 2; i<mxN; ++i){
        if(!a[i]){
            primes.push_back(i);
            if(i == n) val = cnt;
            f[cnt++] = i;
            for(int j = i; j<mxN; j+=i){
                a[j] = true;
            }
        }
    }
    dp[0] = 1;
    for(int i = 1; i<n; ++i){
        for(int j = i-1; j>=0 && (f[i]-f[j] <= 14); --j){
            dp[i] += dp[j];
        }
    }
    cout << dp[val] <<'\n';
}