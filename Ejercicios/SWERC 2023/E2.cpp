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
    vl A(n); rep(i, n) cin>>A[i];

    pll ans = {0, 1};
    rep(_, 2) {
        // cout<<"iteracion "<<_<<'\n';
        vector<pll> S;
        S.pb({1000000, -1});
        vl L(n, -1);
        rep(i, n) {
            while(S.back().ff < A[i]) S.pop_back();
            L[i] = S.back().ss;
            S.pb({A[i], i});

            if(L[i] != -1 and A[i] > A[i - 1]) {
                pll curr = {(i - L[i]) * (A[L[i]] - A[L[i] + 1]) - (A[L[i]] - A[i]), A[L[i]] - A[L[i] + 1]};
                ll g = __gcd(curr.ff, curr.ss);
                curr.ff /= g, curr.ss /= g;
                if(curr.ff * ans.ss > curr.ss * ans.ff) ans = curr;
            }
            
            if(L[i] != -1 and A[i] == A[L[i]]) {
                pll curr = {i - L[i], 1};
                if(curr.ff * ans.ss > curr.ss * ans.ff) ans = curr;
            }
        }

        reverse(A.begin(), A.end());
    }
    if(ans.ss == 1) cout<<ans.ff<<'\n';
    else cout<<ans.ff<<'/'<<ans.ss<<'\n';

    return 0;
}
