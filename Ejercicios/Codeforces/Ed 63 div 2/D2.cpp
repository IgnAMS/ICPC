#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt


vi kadane(vi A, int l, int r, ll x, bool Max) {
    ll mx = 0, curr = 0, lx = -1, rx = -1, n = A.size();
    rep(i, n) if(l <= i and i <= r) A[i] = A[i] * x;
    rep(i, A.size()) {
        if(Max and A[i] >= curr + A[i]) lx = i, curr = A[i];
        else if(Max) curr = curr + A[i];
        if(Max and curr >= mx) rx = i, mx = curr;

        if(!Max and A[i] <= curr + A[i]) lx = i, curr = A[i];
        else if(!Max) curr = curr + A[i];
        if(!Max and curr <= mx) rx = i, mx = curr;
    }
    return {mx, lx, rx};
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, x; cin>>n>>x;
    vi A(n); rep(i, n) cin>>A[i];
    ll ans = 0;
    vi mx = kadane(A, -1, -1, x, 1);
    vi mn = kadane(A, -1, -1, x, 0);
    ans = max({ans, kadane(A, mx[1], mx[2], x, 1)[0], kadane(A, mn[1], mn[2], x, 1)[0]});

    cout<<ans<<'\n';

    return 0;
}