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
    // a + b + prefx + prefy >= difx + dify
    // Mas formalmente

    ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
    ll n; cin>>n;
    string s; cin>>s;
    map<char, ll> mp;
    rep(i, n) {
        mp[s[i]] += 1;
    }

    ll difx = x2 - x1, dify = y2 - y1;
    ll dist = abs(difx) + abs(dify);

    // cout<<(1e5 * 2e9)<<'\n';
    ll num = (n + 3) * dist;
    ll l = 0, r = num;
    while(l < r) {
        ll m = (l + r) / 2;
        ll dx = (mp['R'] - mp['L']) * (m / n);
        ll dy = (mp['U'] - mp['D']) * (m / n);
        rep(i, (m % n)) {
            if(s[i] == 'L') dx -= 1;
            if(s[i] == 'R') dx += 1;
            if(s[i] == 'U') dy += 1;
            if(s[i] == 'D') dy -= 1;
        }

        ll aux = abs(x2 - dx - x1) + abs(y2 - dy - y1);
        if(aux <= m) r = m;
        else l = m + 1;
    }
    cout<<(l == num? -1: l)<<'\n';


    return 0;
}