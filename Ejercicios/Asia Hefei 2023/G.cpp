#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
typedef long long ll;
typedef pair<ll, ll> pll;


// DP[1][i][k] = 1 si es posible que los ultimos k's tengan tamaño mayor o igual len

int len;
string s;
const int mxN = 2e5+5;
const int INF = 2e6;
ll DP[3][mxN][6];
ll Pref[mxN];

ll dp(int b, int i, int k) {
    if(i < -1) return INF;
    if(i == -1 and k > 0) return INF;
    if(k == 0) return 0;

    if(DP[b][i][k] != -1) return DP[b][i][k];

    DP[b][i][k] = INF;

    if(b == 1 and ((i - len == -1) or (i - len >= 0 and s[i - len] == '0'))) {
        DP[b][i][k] = min(
            DP[b][i][k], 
            dp(0, i - len, k - 1) + Pref[i] - (i - len >= 0? Pref[i - len]: 0LL)
        );
    }
    else if(b == 0) {
        DP[b][i][k] = min(dp(1, i - 1, k), dp(0, i - 1, k));
    }
    return DP[b][i][k];
}


int main() {    
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin>>n>>m>>k;
    cin>>s;
    Pref[0] = (s[0] == '0');
    repx(i, 1, n) {
        Pref[i] = Pref[i - 1] + (s[i] == '0');
    }

    ll l = 0, r = n;
    while(l < r) {
        rep(b, 3) rep(i, n) rep(j, 6) DP[b][i][j] = -1;
        ll mid = (l + r + 1) / 2;
        len = mid;
        // cout<<"pruebo "<<mid<<'\n';
        ll v0 = dp(0, n - 1, k), v1 = dp(1, n - 1, k);
        // cout<<v0<<' '<<v1<<'\n';
        // cout<<"\n\n";
        if(min(dp(0, n - 1, k), dp(1, n - 1, k)) <= m) l = mid;
        else r = mid - 1;
    }

    if(l == 0) cout<<"-1\n";
    else cout<<l<<'\n';

    return 0;
}

