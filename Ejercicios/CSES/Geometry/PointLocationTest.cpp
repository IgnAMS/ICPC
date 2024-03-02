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



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        vector<P> Points(3);
        rep(i, 3) {
            ll x, y; cin>>x>>y;
            Points[i] = P(x, y);
        }
        ll val = turn(Points[0], Points[1], Points[2]);
        if(val > 0) cout<<"LEFT\n";
        else if(val < 0) cout<<"RIGHT\n";
        else cout<<"TOUCH\n";
    }





    return 0;
}