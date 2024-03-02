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
 
ll dist(P& a, P& b) {
    return (a - b) * (a - b);
}
 
vector<P> Px;
 
bool lessx(P& a, P& b) {
    return a.x < b.x or (a.x == b.x and a.y <= b.y);
}
bool lessy(P& a, P& b) {
    return a.y < b.y or (a.y == b.y and a.x <= b.x);
}
 
ll bruteforce(vector<P>& Py) {
    ll ans = 8e18 + 10;
    rep(i, Py.size()) repx(j, i + 1, Py.size()) ans = min(ans, dist(Py[i], Py[j]));
    return ans;
}
 
 
ll DivAndConq(vector<P>& Py, int l, int r) {
    if(r - l  + 1 <= 100) {
        return bruteforce(Py);
    }
 
    int m = (l + r) / 2;
    vector<P> PL, PR;
    rep(i, Py.size()) {
        if(lessx(Py[i], Px[m])) PL.pb(Py[i]);
        else PR.pb(Py[i]);
    }
 
    ll dl = DivAndConq(PL, l, m);
    ll dr = DivAndConq(PR, m + 1, r);
    ll d = min(dl, dr);
 
    vector<P> S;
    rep(i, Py.size()) if((Py[i].x - Px[m].x) * (Py[i].x - Px[m].x) < d) S.pb(Py[i]);
    rep(i, S.size()) {
        repx(j, i + 1, S.size()) {
            if((S[i].y - S[j].y) * (S[i].y - S[j].y) > d) break;
            d = min(d, dist(S[i], S[j]));
        }
    }
    return d;
}
 
 
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<P> Pol(n);
    rep(i, n) cin>>Pol[i].x>>Pol[i].y;
    
    vector<P> Py;
    rep(i, n) {
        Px.pb(Pol[i]);
        Py.pb(Pol[i]);
    }
    
    sort(Px.begin(), Px.end(), [&](const P a, const P b) {
        return a.x < b.x or (a.x == b.x and a.y < b.y);
    });
 
    sort(Py.begin(), Py.end(), [&](const P a, const P b) {
        return a.y < b.y or (a.y == b.y and a.x < b.x);
    });
    cout<<DivAndConq(Py, 0, n - 1)<<'\n';
 
 
    return 0;
}