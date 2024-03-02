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
 
ll turn(P& a, P& b, P& c) {
    return (b - a) ^ (c - a);
}

vector<P> CH(vector<P>& Poly) {
    sort(Poly.begin(), Poly.end(), [&](const P a, const P b){
        return a.x < b.x or (a.x == b.x and a.y < b.y);
    });

    int n = Poly.size();
    vector<P> uph;
    rep(i, n) {
        while(uph.size() >= 2 and turn(uph[uph.size() - 2], uph.back(), Poly[i]) > 0) uph.pop_back();
        uph.pb(Poly[i]);
    }
    vector<P> dh;
    for(int i = n - 1; i >= 0; i--)  {
        while(dh.size() >= 2 and turn(dh[dh.size() - 2], dh.back(), Poly[i]) > 0) dh.pop_back();
        dh.pb(Poly[i]);
    }
    uph.pop_back(); dh.pop_back();
    vector<P> ch;
    for(auto& u: uph) ch.pb(u);
    for(auto& u: dh) ch.pb(u);
    
    return ch;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<P> Poly(n);
    rep(i, n) cin>>Poly[i].x>>Poly[i].y;
    vector<P> ch = CH(Poly);
    cout<<ch.size()<<'\n';
    for(auto u: ch) cout<<u.x<<' '<<u.y<<'\n';


    return 0;
}