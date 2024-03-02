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
    ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
    ll dist = abs(x1 - x2) + abs(y1 - y2);
    
    int n; cin>>n;
    string s; cin>>s;
    ll Dir[4][n + 1];
    memset(Dir, 0, sizeof(Dir));
    rep(i, n) {
        rep(j, 4) Dir[j][i + 1] = Dir[j][i];
        if(s[i] == 'U') Dir[0][i + 1]++;
        if(s[i] == 'D') Dir[1][i + 1]++;
        if(s[i] == 'L') Dir[2][i + 1]++;
        if(s[i] == 'R') Dir[3][i + 1]++;
    }

    ll l = 0, r = (n + 3) * dist;
    while(l < r) {
        ll m = (l + r) / 2;
        ll util = 0;
        ll dx = Dir[3][m % n] + Dir[3][n] * (m / n) - Dir[2][m % n] - Dir[2][n] * (m / n);
        ll dy = Dir[0][m % n] + Dir[0][n] * (m / n) - Dir[1][m % n] - Dir[1][n] * (m / n);
        ll i1 = abs(x2 - dx - x1);
        ll i2 = abs(y2 - dy - y1);
        if(i1 + i2 <= m) r = m;
        else l = m + 1;
    }
    if(l == (n + 3) * dist) cout<<"-1\n";
    else cout<<l<<'\n';


    return 0;
}