#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define repx(i, a, b) for(int i = int(a); i < int(b); i++)
#define rep(i, n) repx(i, 0, n)
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<pair<ll, ll>> A(n);
    vl X[5];

    map<char, ll> mp;
    mp['S'] = 0, mp['W'] = 1, mp['E'] = 2, mp['R'] = 3, mp['C'] = 4;

    rep(i, n) {
        string s; cin>>s;
        A[i].ff = mp[s[0]];
        A[i].ss = 0;
        repx(j, 1, s.length()) A[i].ss = A[i].ss * 10 + (s[j] - '0');

        X[A[i].ff].pb(A[i].ss);
    }
    
    rep(i, 5) sort(X[i].begin(), X[i].end());

    vl I(4);
    rep(i, 4) I[i] = i;

    ll ans = n;
    do {
        vl B(n);
        ll Acc[5];
        Acc[0] = 0;
        rep(i, 4) Acc[i + 1] = Acc[i] + X[I[i]].size();
        
        ll inv[5];
        rep(i, 4) inv[I[i]] = i;
        inv[4] = 4;
        
        rep(i, n) {
            ll c = A[i].ff, val = A[i].ss;
            B[i] = Acc[inv[c]] +int(lower_bound(X[c].begin(), X[c].end(), val) - X[c].begin());
        }

        vl LIS(n + 3, 10000000);
        ll best = 0;
        rep(i, n) {
            int ind = lower_bound(LIS.begin(), LIS.end(), B[i]) - LIS.begin();
            // cout<<B[i]<<' '<<ind<<'\n';
            LIS[ind] = min(LIS[ind], B[i]);
            best = max(best, ll(ind + 1));
        }
        // cout<<best<<'\n';
        ans = min(ans, ll(n - best));

    } while(next_permutation(I.begin(), I.end()));
    cout<<ans<<'\n';


    return 0;
}
