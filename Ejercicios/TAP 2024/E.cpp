#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef double db;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define pb push_back
#define ar array


const int mxN = 1e5+5;
ll dp[mxN][205];

void solve(){
    for(int life = 0; life < mxN; ++life){
        for(int i = 0; i< 205; ++i){
            dp[life][i] = 0;
        }
    }
    ll n, P;
    cin >> n >> P;
    vector<ar<ll, 3>> a(n);
    rep(i, n){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    for(int life = 1; life <= P; ++life){
        for(int i = 0; i<n; ++i){
            dp[life][i] = max(dp[life][i], dp[life][i-1]);
            ll actual = (life-a[i][1])/a[i][0];
            if(actual >= 0){
                dp[life][i] = max(dp[life][i], dp[actual][i-1] + a[i][2]);
            }
        }
    }
    ll ans = 0;
    for(int life = 0; life<=P; ++life){
        for(int i = 0; i<n; ++i){
            ans = max(ans, dp[life][i]);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    solve();

    

    return 0;
}

