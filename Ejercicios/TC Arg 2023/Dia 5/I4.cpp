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

db eps = 1e-7;

ll inRange(ll x, ll x1, ll x2, bool border=0) {
    if(!border) return (x1 <= x and x <= x2);
    return x1 < x and x < x2; 
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
    db l = 0, r = 1e10;
    rep(i, n) {
        ll x, y, vx, vy; cin>>x>>y>>vx>>vy;
        db currL = 1e10, currR = 0;
        if(inRange(x, x1, x2) and inRange(y, y1, y2)) currL = 0;
        
        if(vx != 0) {
            // Entradas
            if(x <= x1 and vx > 0) {
                db t = (x1 - x) / vx;
                db ny = db(y) + t * vy;
                if(inRange(ny, y1, y2)) 
            }
            if(x <= x2) {

            }
        }
    }





    return 0;
}