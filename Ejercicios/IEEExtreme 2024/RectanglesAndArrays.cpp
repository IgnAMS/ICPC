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


ll n, x; 
ll A[1000005];


ll calculate_area() {
    vector<pll> X = {{-1, -1}};
    ll L[n], R[n];
    rep(i, n) {
        while(X.back().ff >= A[i]) X.pop_back();
        L[i] = X.back().ss + 1;
        X.pb({A[i], i});
    }
    X.clear();
    X.push_back({-1, n});
    for(int i = n - 1; i >= 0; i--) {
        while(X.back().ff >= A[i]) X.pop_back();
        R[i] = X.back().ss - 1;
        X.pb({A[i], i});
    }

    ll area = 0;
    rep(i, n) area = max(area, (R[i] - L[i] + 1) * A[i]);
    return area;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    cin>>x;
    rep(i, n) cin>>A[i];

    ll ans = calculate_area();
    rep(i, n) if(A[i] < x) {
        ll prev = A[i];
        A[i] = x;
        ll area = calculate_area();
        ans = max(ans, area);
        A[i] = prev;
    }
    cout<<ans<<'\n';

    return 0;
}