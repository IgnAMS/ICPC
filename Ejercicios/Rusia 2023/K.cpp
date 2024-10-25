#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

const db PI = 3.14159265359;
const db EPS = 1e-7;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll a, b, c, d; cin>>a>>b>>c>>d;

    pair<db, db> P[4] = {{0, 0}, {c, 0}, {0, d}, {c, d}};
    int mxiter = 50000000 / 4;
    bool pos = 0;
    for(int i = 0; i <= mxiter; i++) {
        db minx = 100000, miny = 100000, maxx = -100000, maxy = -100000;
        db ang = db(i) * PI / 2.0 / db(mxiter);
        rep(j, 4) {
            auto& [x, y] = P[j];
            pair<db, db> p = {
                cos(ang) * x - sin(ang) * y,
                sin(ang) * x + cos(ang) * y
            };
            minx = min(minx, p.ff);
            maxx = max(maxx, p.ff);
            
            miny = min(miny, p.ss);
            maxy = max(maxy, p.ss);
        }
        db lx = maxx - minx, ly = maxy - miny;
        // if(i % 10000 == 0) cout<<lx<<' '<<ly<<'\n';
        if((lx <= a + EPS and ly <= b + EPS) or (ly <= a + EPS and lx <= b + EPS)) {
            // cout<<"posible con el angulo "<<ang<<'\n';
            cout<<"YES\n";
            return 0;
        }
    }

    cout<<"NO\n";




    return 0;
}