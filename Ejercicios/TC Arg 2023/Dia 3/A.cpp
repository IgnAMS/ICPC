#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i<(int)n; ++i)
#define repx(i, a, b) for(int i = a; i<(int)b; ++i)
#define ll long long
#define vl vector<ll>
#define ff first
#define ss second
#define pb push_back

const int mxN = 3e5+5;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll x, k;  cin>>x>>k;
    repx(i, 1, x) repx(j, i + 1, x) {
        ll g = __gcd(i, j);
        ll lcm = (i / g) * j;
        if(g + lcm == x) cout<<i<<' '<<j<<'\n';
    }




    return 0;
}