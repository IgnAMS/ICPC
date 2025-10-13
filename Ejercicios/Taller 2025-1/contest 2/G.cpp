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
    for(auto c: s) mp[c] += 1;
    ll difx = x2 - x1, dify = y2 - y1;
    ll dist = abs(difx) + abs(dify);
    ll suma = mp['L'] * (difx < 0) + mp['R'] * (difx > 0) + mp['U'] * (dify > 0) + mp['D'] * (dify < 0);
    suma *= 2;
    if(suma == 0) {
        cout<<"-1\n";
        return 0;
    }

    ll cont = 0;
    ll ans = ((dist + suma - 1) / suma) * n;
    rep(i, n) {
        if(s[i] == 'L' and difx < 0) cont += 2;
        if(s[i] == 'R' and difx > 0) cont += 2;
        if(s[i] == 'U' and dify > 0) cont += 2;
        if(s[i] == 'D' and dify < 0) cont += 2;
        // dist <= cont + suma * steps
        // (dist - cont) / suma <= steps
        ll steps = max(0LL, (dist - cont + suma - 1) / suma);
        // cout<<i + 1<<' '<<cont<<' '<<suma<<' '<<steps<<'\n';
        ans = min(ans, i + 1 + steps * n);
    }
    cout<<(ans == 1e17? -1: ans)<<'\n';



    return 0;
}