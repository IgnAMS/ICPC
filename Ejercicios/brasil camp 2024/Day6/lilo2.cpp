#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define ar array
#define rep(i, n) for(int i = 0; i<(int)n; ++i)

const int mxN = 5010, M = 1e9+7;
long double dp[mxN][2*mxN]; 
int n, k;

int main(){
#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", " w", stdout);
#endif
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    cout << fixed << setprecision(7);
    cin >> n >> k;
    vector<long double> a(n);
    rep(i, n) cin >> a[i];
    sort(a.rbegin(), a.rend());

    int f = 5005;
    memset(dp, 0, sizeof(dp));
    dp[0][f-1] = 1.0-a[0];
    dp[0][f+1] = a[0];
    for(int i = 1; i<n; ++i){
        for(int val = 1; val < 2 * f; ++val){
            dp[i][val] += dp[i-1][val-1]*a[i];
            dp[i][val] += dp[i-1][val+1]*(1.0-a[i]);
        }
    }
    long double ans = 0;
    rep(i, n){
        long double cnt = 0;
        for(int j = f+k; j<=f+i+1; ++j){
            cnt += dp[i][j];
        }
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
}