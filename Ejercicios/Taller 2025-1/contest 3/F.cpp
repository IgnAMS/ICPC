#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll A[n]; rep(i, n) cin>>A[i];

    vector<pll> S = {{-1, -1}};
    ll L[n + 1], R[n + 1];
    rep(i, n) {
        while(S.back().ff >= A[i]) S.pop_back();
        L[i] = S.back().ss;
        S.pb({A[i], i});
    }
    S = {{-1, n}};
    for(int i = n - 1; i >= 0; i--) {
        while(S.back().ff >= A[i]) S.pop_back();
        R[i] = S.back().ss;
        S.pb({A[i], i});
    }

    ll ans = 0;
    rep(i, n) {
        // cout<<L[i]<<' '<<R[i]<<'\n';
        ll largo = R[i] - L[i] - 1;
        ans = max(ans, A[i] * largo);
    }
    cout<<ans<<'\n';


    return 0;
}