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
    int n, m; cin>>n>>m;
    vl X(n, 1), Y(n, 1);
    X[0] = X[n - 1] = Y[0] = Y[n - 1] = 0;

    rep(i, m) {
        int x, y; cin>>x>>y; x--, y--;
        X[x] = 0, Y[y] = 0;
    }

    ll ans = 0;
    if((n & 1) and (X[n / 2] or Y[n / 2])) {
        ans++;
        X[n / 2] = Y[n / 2] = 0;
    }

    rep(i, n) ans += X[i];
    rep(i, n) ans += Y[i];
    cout<<ans<<'\n';

    return 0;
}