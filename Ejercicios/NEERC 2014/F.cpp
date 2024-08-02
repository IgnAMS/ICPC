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
    int n, k; cin>>n>>k;
    vl A(n); rep(i, n) cin>>A[i];

    vl L(n, 0);
    ll acc = 0;
    rep(i, n) {
        if(i >= k) acc -= A[i - k];
        acc += A[i];
        L[i] = max(L[i], acc);
        if(i) L[i] = max(L[i], L[i - 1]); 
    }
    acc = 0;
    ll ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(i + k < n) acc -= A[i + k];
        acc += A[i];
        if(i == 0) ans = max(ans, acc);
        else ans = max(ans, acc + L[i - 1]);    
    }
    cout<<ans<<'\n';

}

