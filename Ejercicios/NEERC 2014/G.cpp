#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define repx(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define rep(i, n) repx(i, 0, n)
#define pb push_back


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k; cin>>n>>k;
    vl A(n); rep(i, n) cin>>A[i];
    
    ll mn = 10000;
    rep(i, n) mn = min(mn, A[i]);
    vl S;
    ll acc = 0, ans = 0;
    rep(i, n) {
        acc += A[i] - (i >= k? A[i - k]: 0LL);
        if(A[i] != mn) S.pb(i);
        if(i >= k - 1) {
            while(acc >= 0) {
                int j = S.back(); S.pop_back();
                ll x = max(mn, A[j] - acc - 1);
                acc += x - A[j];
                ans += abs(x - A[j]);
                A[j] = x;
                if(A[j] > mn) S.pb(i);
            }
        }
    }
    cout<<ans<<'\n';
    rep(i, n) cout<<A[i]<<' '; cout<<'\n';
}