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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vl A(n); rep(i, n) cin>>A[i];
    sort(A.begin(), A.end());
    vl X(1000005, 0); 
    rep(i, n) X[A[i]] = 1;

    ll ans = 0;
    repx(i, 2, 1000005) {
        if(!X[i]) continue;
        for(ll j = i; j <= 1000000; j += i) {
            auto it = prev(lower_bound(A.begin(), A.end(), j + i));
            if(*it >= j) ans = max(ans, *it - j);
        }
    }
    cout<<ans<<'\n';

    return 0;
}