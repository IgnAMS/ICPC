#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define rep(i, n) for(int i = 0; i < n; i++)

int main() {
    ll n, t; cin>>n>>t;
    vl A(n); rep(i, n) cin>>A[i];
    ll curr = 0;
    ll l = 0;
    ll ans = 0;
    rep(i, n) {
        curr += A[i];
        while(curr > t) curr -= A[l], l++;
        ans = max(ans, i - l + 1);
    }
    cout<<ans<<'\n';


    return 0;
}