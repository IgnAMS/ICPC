#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt


vector<vector<vi>> G1; // punto que esta en i, j -> {{distancia,  }, {distancia, recta}}....
vector<vi> D;
vector<vector<ii>> Pares;
vector<ii> I; // stack, voy
// x * p.y - y * p.x == 0
struct P {
    ll x, y;
    P() {}
    P(ll x, ll y): x(x), y(y) {}
    ll operator^(const P& p) const { return x * p.y - y * p.x; }
    P operator+(const P& p) const { return P(x + p.x, y + p.y); }
    P operator-(const P& p) const { return P(x - p.x, y - p.y); }
    ll operator*(const P& p) const { return x * p.x + y * p.y; }
    ll norm2() const { return x * x + y * y; }
};
db turn(P& a, P& b, P& c) { return (a - b) ^ (c - b); }



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    P p1, p2; cin>>p1.x>>p1.y>>p2.x>>p2.y; 
    if(p1.x == p2.x and p1.y == p2.y) { cout<<"0\n"; return 0; }
    pair<P, int> L = {P(p1.y - p2.y, p2.x - p1.x), -((p1.y - p2.y) * p1.x + (p2.x - p1.x) * p1.y)};
    
    int n; cin>>n;
    vector<pair<P, int>> Points(n);
    rep(i, n) cin>>Points[i].ff.x>>Points[i].ff.y>>Points[i].ss;
    ll ans = 0;
    rep(i, n) {
        ll t1 = (Points[i].ff * p1) + Points[i].ss; t1 /= abs(t1);
        ll t2 = (Points[i].ff * p2) + Points[i].ss; t2 /= abs(t2);
        ans += (t1 * t2 < 0);
    }
    cout<<ans<<'\n';



    return 0;
}