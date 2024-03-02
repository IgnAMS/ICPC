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


struct Point {
    ll x, y;
    Point(ll x, ll y): x(x), y(y) {}
    Point() {}
    Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
    Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
    Point operator*(const ll &c) const { return Point(c * x, c * y); } 
    Point operator/(const ll &c) const { return Point(x / c, y / c); }
    ll operator*(const Point &p) const { return x * p.x + y * p.y; }
    ll operator^(const Point &p) const { return x * p.y - y * p.x; }
    bool operator<(const Point &p) const {
        return abs(x - p.x) > 0 ? p.x - x > 0 : p.y - y > 0;
    }
    
};

ostream &operator<<(ostream &s, const Point &p) {
    return s << '(' << p.x << ", " << p.y << ')';
}

ll turn(Point &a, Point &b, Point &c) { return (b - a) ^ (c - a); }

bool inDisk(Point &a, Point &b, Point &p) { return (a - p) * (b - p) <= 0; }

bool onSegment(Point &a, Point &b, Point &p) {
    return abs(turn(a, b, p)) == 0 && inDisk(a, b, p); 
}

bool properInter(Point &a, Point &b, Point &c, Point &d, Point &out) {
    ll ta = turn(c, d, a), tb = turn(c, d, b),
      tc = turn(a, b, c), td = turn(a, b, d);
    if(tb - ta == 0) return false;
    out = (a * tb - b * ta);
    if(abs(out.x) % abs(tb - ta) != 0 or abs(out.y) % abs(tb - ta)) return false;
    out = out / (tb - ta);
    // if(ta * tb < 0 and tc * td < 0) cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<out<<'\n';
    return (ta * tb < 0 && tc * td < 0);
}

set<Point> inter(Point &a, Point &b, Point &c, Point &d) {
    Point out;
    if (properInter(a, b, c, d, out)) return {out};
    set<Point> ans;
    if(onSegment(c, d, a)) ans.insert(a);
    if(onSegment(c, d, b)) ans.insert(b);
    if(onSegment(a, b, c)) ans.insert(c);
    if(onSegment(a, b, d)) ans.insert(d);
    return ans;
}




Point dir[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    Point X[n];
    ll D[n]; 
    rep(i, n) {
        cin>>X[i].x>>X[i].y>>D[i];
    }

    // Tengo 4 segmento
    // (X[0], Y[0] + D[0]) a (X[0] + D[0], Y[0])
    // (X[0] + D[0], Y[0]) a (X[0], Y[0] - D[0])
    // (X[0], Y[0] - D[0]) a (X[0] - D[0], Y[0])
    // (X[0] - D[0], Y[0]) a (X[0], Y[0] + D[0])
    

    // Para cada segmento quiero ver con que cosas nuevas intersectan
    // Tengo dos tipos de intersecciones, la primera es la perpendicular
    // Y la segunda es la colineal
    // En la perpendicular debo revisar 
    

    
    vector<pair<Point, Point>> Seg[4];
    rep(h, 4) {
        Seg[h].pb({X[0] + dir[h] * D[0], X[0] + dir[(h + 1) % 4] * D[0]});
        if(Seg[h][0].ff.x > Seg[h][0].ss.x) swap(Seg[h][0].ff, Seg[h][0].ss);
        // cout<<seg[h][0].ff.x<<' '<<seg[h][0].ff.y<<", "<<seg[h][0].ss.x<<' '<<seg[h][0].ss.y<<'\n';
    }

    repx(i, 1, n) {
        // Quiero guardar diagonales del tipo x+y, x-y, y-x, -x-y
        vector<pair<Point, Point>> NSeg[4];
        rep(j, 4) {
            pair<Point, Point> nwseg = {X[i] + dir[j] * D[i], X[i] + dir[(j + 1) % 4] * D[i]};
            if(nwseg.ff.x > nwseg.ss.x) swap(nwseg.ff, nwseg.ss);
            rep(k, 4) {
                // Caso paralelos
                for(auto seg: Seg[k]) {
                    if((j & 1) == (k & 1)) {
                        // Paralelos que no coinciden en la misma recta
                        // if(abs(turn(seg.ff, seg.ss, nwseg.ff)) > 0) {
                        //     // cout<<seg.ff<<' '<<seg.ss<<" vs "<<nwseg.ff<<' '<<nwseg.ss<<'\n';
                        //     // cout<<"Son paralelos pero no coinciden\n";
                        //     break;
                        // }  
                        auto puntos = inter(seg.ff, seg.ss, nwseg.ff, nwseg.ss);
                        cout<<seg.ff<<' '<<seg.ss<<' '<<nwseg.ff<<' '<<nwseg.ss<<' '<<puntos.size()<<'\n';
                        if(puntos.size() == 1) {
                            NSeg[k].pb({*puntos.begin(), *puntos.begin()});
                        }
                        else if(puntos.size() == 2) {
                            cout<<(*puntos.begin())<<' '<<(*puntos.rbegin())<<'\n';
                        }
                        else if(puntos.size() != 0) {
                            cout<<puntos.size()<<'\n';
                        }
 
                    }
                    // Casos que no son paralelos, son perpendiculares
                    else {
                        auto puntos = inter(seg.ff, seg.ss, nwseg.ff, nwseg.ss);
                    }
                }
                
            }
        }


    }





    return 0;
}