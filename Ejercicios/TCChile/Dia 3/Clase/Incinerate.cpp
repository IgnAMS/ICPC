#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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
    int t; cin>>t;
    while(t--) {
        ll n, k; cin>>n>>k;
        vector<pll> X(n);
        rep(i, n) cin>>X[i].ff;
        rep(i, n) cin>>X[i].ss;
        sort(X.begin(), X.end());
        vl Mn(n, 1e10);
        Mn[n - 1] = X[n - 1].ss;
        for(int i = n - 2; i >= 0; i--) Mn[i] = min(Mn[i + 1], X[i].ss);
        ll baseh = 0;
        while(k > 0) {
            baseh += k;
            auto it = upper_bound(X.begin(), X.end(), pll(baseh, 1e10));
            if(it == X.end()) break;
            ll pos = it - X.begin();
            k -= Mn[pos];
        }
        if(k > 0) cout<<"YES\n";
        else cout<<"NO\n";

    }


    return 0;
}