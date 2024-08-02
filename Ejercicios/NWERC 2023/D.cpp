#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef double db;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define ff first
#define pb push_back

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string mat[7];
    rep(i, 7) cin>>mat[i];
    
    int d, h; cin>>d>>h;
    ll ans = 0;
    rep(mask, (1<<7)) {
        vl X;
        rep(i, 7) if(mask & (1<<i)) {
            X.pb(i);
        }
        if(X.size() != d) continue;
        // for(auto u: X) cout<<u<<' '; cout<<'\n';

        ll DP[24][25];
        rep(i, 24) rep(j, 25) DP[i][j] = 0;

        vl F(25, 0);
        rep(i, d) rep(j, 24) {
            if(mat[X[i]][j] == '.') F[j]++;
        }

        rep(i, 24) for(int j = h; j >= 1; j--) {
            if(i) DP[i][j] = max({DP[i][j], DP[i - 1][j - 1] + F[i], DP[i - 1][j]});
            else if(j == 1) DP[i][j] = max(DP[i][j], DP[i][j - 1] + F[i]);
        }
        // rep(i, 24) cout<<DP[i][h]<<' '; cout<<'\n';
        rep(i, 24) ans = max(ans, DP[i][h]);
    }
    cout<<setprecision(8)<<fixed<<db(ans) / db(d * h)<<'\n';
}