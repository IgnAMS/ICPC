#pragma GCC target("popcnt")
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
    bitset<3000> X[n];

    rep(i, n) cin>>X[i];
    ll ans = 0;
    rep(i, n) repx(j, i + 1, n) {
        // 3000 * 3000 * 3000 / 64 ~ 
        ll cant = (X[i] & X[j]).count();
        ans += cant * (cant - 1) / 2;
    }
    cout<<ans<<'\n';

    return 0;
}