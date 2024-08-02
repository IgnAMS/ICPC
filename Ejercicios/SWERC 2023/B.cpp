#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define repx(i, a, b) for(int i = int(a); i < int(b); i++)
#define rep(i, n) repx(i, 0, n)
typedef vector<ll> vl;
typedef double db;
#define ff first
#define ss second


int main() {
    int n, m; cin>>n>>m;
    vector<db> F(101, 0.);
    vector<vl> A(n, vl());
    rep(i, n) {
        int k; cin>>k;
        A[i].assign(k, 0);
        rep(j, k) {
            cin>>A[i][j];
            A[i][j]--;

            F[A[i][j]] += 1.0 / db(k);
        }
    }

    vector<pair<db, int>> I(m);
    rep(i, m) I[i] = {-F[i], i};

    sort(I.begin(), I.end());

    ll ans = n;
    vl X(101, 0);
    rep(i, m) {
        // cout<<I[i].ff<<' '<<I[i].ss<<'\n';
        ll cont = 0;
        X[I[i].ss] = 1;
        rep(j, n) {
            bool pos = 1;
            for(auto& x: A[j]) if(X[x] == 0) pos = 0;
            cont += pos;
        }

        ans = min(ans, ll(i + 1) + (n - cont));
     }
     cout<<ans<<'\n';

    return 0;
}