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

ll sign(ll x) { 
    if(x == 0) return 0;
    if(x > 0) return 1;
    return -1;
}

bool properInter(P& a, P& b, P& c, P& d) {
    ll ta = turn(a, c, d), tb = turn(b, c, d), 
        tc = turn(c, a, b), td = turn(d, a, b);
    if(sign(ta) * sign(tb) < 0 and sign(tc) * sign(td) < 0) return true;

    return false;
}

bool pointInter(P& a, P& b, P& c) {
    return turn(a, b, c) == 0 and ((a - c) * (b - c)) <= 0;  
}

bool inter(P& a, P& b, P& c, P& d) {
    if(properInter(a, b, c, d)) return true; 
    if(pointInter(a, b, c)) return true;
    if(pointInter(a, b, d)) return true;
    if(pointInter(c, d, a)) return true;
    if(pointInter(c, d, b)) return true;
    return false;
}




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        P Points[4];
        rep(i, 4) {
            ll x, y; cin>>x>>y;
            Points[i] = P(x, y);
        }
        cout<<(inter(Points[0], Points[1], Points[2], Points[3])? "YES": "NO")<<'\n';
    }    

    return 0;
}