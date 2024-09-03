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
    P operator+(const P& p) const { return P(x + p.x, y + p.y); }
    P operator-(const P& p) const { return P(x - p.x, y - p.y); }
    P operator*(ll c) const { return P(c * x, y * x); }
    P operator/(ll c) const { return P(x / c, y / c); }
    ll operator*(const P& p) const { return x * p.x + y * p.y; }
    ll operator^(const P& p) const { return x * p.y - y * p.x; }
    bool operator<(const P &p) const {
        return p.x != x? p.x > x : p.y > y;
    }
    ll norm1() { return abs(x) + abs(y); }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, const P &p)     {
    return s << '(' << p.x << ", " << p.y << ')';
}

ll turn(P a, P b, P c) { return (b - a) ^ (c - a); }

vector<P> convexHull(vector<P>& p) {
    int n = p.size(), k = 0;
    vector<P> H(2 * n); 
    sort(p.begin(), p.end());
    rep(i, n) {
        while(k >= 2 and turn(H[k - 2], H[k - 1], p[i]) <= 0) k--;
        H[k++] = p[i];
    }
    for(int i = n - 2, t = k + 1; i >= 0; i--) {
        while(k >= t and turn(H[k - 2], H[k - 1], p[i]) <= 0) k--;
        H[k++] = p[i];
    }
    H.resize(k - 1);
    return H;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<P> p(n);
    rep(i, n) cin>>p[i];
    
    vector<P> CH = convexHull(p);
    ll ans = 0;
    ll n2 = CH.size();
    
    if(n == 1) {
        cout<<"4\n";
        return 0;
    }
    if(n2 == 2) {
        if(CH[0].x == CH[1].x or CH[0].y == CH[1].y) ans += 4;
        else if(abs(CH[0].x - CH[1].x) == abs(CH[0].y - CH[1].y)) ans += 3;
        else ans += 2;
        
        P dir = CH[0] - CH[1];
        // cout<<dir<<", ";
        // cout<<max(abs(dir.x), abs(dir.y))<<'\n';
        if(dir.x == 0 or dir.y == 0) ans += 2 * max(abs(dir.x), abs(dir.y));
        else ans += 2 * (max(abs(dir.x), abs(dir.y)) + 1);
        cout<<ans<<'\n';
        return 0;
    }

    // Caso contrario n2 >= 3
    vector<P> p2;
    vector<P> Dir = {P(1, 1), P(1, -1), P(-1, 1), P(-1, -1)};
    ll Mx[4];
    rep(i, 4) Mx[i] = 0;
    rep(i, n2) {
        rep(j, 4) {
            // cout<<Dir[j] * CH[i]<<'\n';
            Mx[j] = max(Mx[j], Dir[j] * CH[i]);
        }
        cout<<'\n';
    }

    ans += 4;
    rep(j, 4) ans += Mx[j];

    cout<<ans<<'\n';

    return 0;
}