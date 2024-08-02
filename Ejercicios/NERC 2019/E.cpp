#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repx(i, a, b) for(int i = a; i < b; i++)
#define pb push_back


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    ll A[m][n];
    rep(i, m) rep(j, n) cin>>A[i][j];

    vl Suma(n, 0);
    vector<vector<pll>> Dif(n, vector<pll>());
    rep(i, m) {
        rep(j, n - 1) {
            Suma[j] += A[i][j] - A[i][n - 1];
            Dif[j].pb({A[i][j] - A[i][n - 1], i});
        }
    }

    // Calculo la respuesta para cada i
    ll ans = m;
    vector<ll> Ans;
    rep(i, n) Ans.pb(i);

    rep(i, n - 1) {
        sort(Dif[i].begin(), Dif[i].end());
        if(Suma[i] >= 0) {
            if(ans > 0) {
                ans = 0;
                Ans.clear();
                break;
            }
        }
        rep(j, m) {
            Suma[i] -= Dif[i][j].first;
            if(Suma[i] >= 0 and ans > j + 1) {
                ans = j + 1;
                Ans.clear();
                rep(k, j + 1) Ans.pb(Dif[i][k].second);
                break;
            }
        }
    }
    cout<<ans<<'\n';
    for(auto u: Ans) cout<<u + 1<<' '; cout<<'\n';
}