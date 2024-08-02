#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repx(i, a, b) for(int i = a; i < b; i++)
#define pb push_back

long double dp[2][105][10005];
long double comb[105][105];

long double calc(int n, int k){
    long double res = 1;
    for(int i = 2; i<=n-k; ++i){
        res /= (long double)i;
    }
    for(int i = 2; i<=k; ++i){
        res /= (long double)i;
    }
    for(int i = 2; i<=n; ++i){
        res *= (long double)i;
    }
    return res;
}

int main() {
    int n;
    long double x;
    cin >> n >> x;
    vector<ll> a(n);
    memset(dp, 0, sizeof(dp));
    ll tot_sum = 0;
    for(int i = 0; i<n; ++i){
        cin >> a[i];
        tot_sum += a[i];
    }
    for(int i = 1; i<105; ++i){
        for(int j = 1; j<105; ++j){
            comb[i][j] = calc(i, j);
        }
    }
    dp[0][0][0] = 1;

    for(int i = 0; i < n; i++) {
        for(int k = n; k >= 1; k--) {
            for(int ss = tot_sum; ss >= 0; ss--) {
                if(a[i] <= ss) {
                    dp[0][k][ss] += dp[0][k - 1][ss - a[i]]
                }
            }
        }
    }

    // for(int k = n; k>=1; k--){ 
    //     for(int ss = tot_sum; ss >= 0; --ss){
    //         dp[1][k][ss] = dp[0][k][ss];
    //         for(int i = 0; i < n; ++i){
    //             if(a[i] <= ss){
    //                 dp[1][k][ss] += dp[0][k-1][ss-a[i]];
    //             }
    //         }
    //     }
    //     for(int ss = 0; ss<=tot_sum; ++ss){
    //         dp[0][k][ss] = dp[1][k][ss];
    //     }
    // 
    // }
    
    long double ans = 0;
    for(int i = 1; i<=n; ++i){
        for(int sum = 1; sum<=tot_sum; ++sum){
            cout << i << " " << sum << " val dp " << ((long double)dp[0][i][sum])/comb[n][i] << "    p1 : " << (long double)(tot_sum - sum)/(long double)(n-i) << "    p2 : " << ((long double)n / (long double)(n-i)) * (long double) x/2.0 + (long double) x / 2.0 << "\n";
            ans += (((long double)dp[0][i][sum])/comb[n][i]) * min((long double)(tot_sum - sum)/(long double)(n-i), ((long double)n / (long double)(n-i+1)) * (long double) x/2.0 + (long double) x / 2.0);
        }
    }
    cout << ans << "\n";


}

//(((long double)dp[0][i][sum])/comb[n][i]) * min((long double)(tot_sum - sum)/(long double)(n-i), ((long double)n / (long double)(n-i)) * (long double) x/2.0 + (long double) x / 2.0)