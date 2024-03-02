#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define ff first
#define ss second
#define rep(i, n) for(int i = 0; i < n; i++)
#define repx(i, a, b) for(int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vector<vl> S(m, vl()); 
    rep(i, n) {
        ll p, c; cin>>p>>c; p--;
        S[p].push_back(c);
    }
    for(auto &vec: S) sort(vec.begin(), vec.end());

    ll ans = 1e17;
    rep(barra, n) {
        int sz = S[0].size();
        ll curr = 0;
        repx(i, 1, m) {
            for(int l = S[i].size(), j = 0; l > barra; l--, j++) {
                curr += S[i][j];
                sz++;
            }
        }
        vl S3;
        repx(i, 1, m) {
            rep(j, min((int)S[i].size(), barra)) S3.push_back(S[i][S[i].size() - j - 1]); 
        }
        sort(S3.begin(), S3.end());
        rep(i, barra - sz + 1)
            curr += S3[i];
        ans = min(ans, curr);
    }
    cout<<ans<<'\n';

    return 0;
}