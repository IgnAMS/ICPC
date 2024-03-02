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


struct P {
    ll x, y; 
    P(): x(0), y(0) {}
    P(ll x, ll y): x(x), y(y) {}
    ll operator^(const P& p) const { return x * p.y - y * p.x; }
    ll operator*(const P& p) const { return x * p.x + y * p.y; }
    P operator+(const P& p) const { return P(x + p.x, y + p.y); }
    P operator-(const P& p) const { return P(x - p.x, y - p.y); }
    P operator*(const ll c) const { return P(x * c, y * c); }
    P operator/(const ll c) const { return P(x / c, y / c); }
};


ll gcd(ll a, ll b) {
    if(a == 0 or b == 0) return max(a, b);
    return __gcd(a, b);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<P> Poly(n);
    rep(i, n) cin>>Poly[i].x>>Poly[i].y;
    // pick theorem: A = i + b/2 - 1 -> 2 A = 2 i + b - 2 -> (2 * A - b - 2) / 2 = i
    // border = gcd(a, b)
    
    ll border = 0, area = 0;
    rep(i, n) {
        P dif = Poly[i] - Poly[(i + 1) % n];
        dif.x = abs(dif.x), dif.y = abs(dif.y);
        border += gcd(dif.x, dif.y);
        area += Poly[i] ^ Poly[(i + 1) % n];
    }
    area = abs(area);
    ll interior = (area - border + 2) / 2;

    cout<<interior<<' '<<border<<'\n';
    
    return 0;
}