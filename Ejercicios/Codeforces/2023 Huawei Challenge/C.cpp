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
    ll X[n], Y[n];
    set<pll> S;
    rep(i, n) {
        cin>>X[i]>>Y[i];
        S.insert({X[i], Y[i]});
    }
    ll ans = 0;
    rep(i, n) repx(j, i + 1, n) {
        ll x2 = X[i] + X[j];
        ll y2 = Y[i] + Y[j];
        if((x2 & 1) == 1 or (y2 & 1) == 1) continue;
        ans += S.count({x2 / 2, y2 / 2});
    }
    cout<<ans<<'\n';

    return 0;
}