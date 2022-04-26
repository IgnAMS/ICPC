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

const db PI = acos(-1.0L);
const db EPS = 1e-12;

typedef ll T; struct P {
    T x, y;
    P() {} P(T x, T y) : x(x), y(y) {}

    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const db &c) const { return P(x * c, y * c); }
    P operator/(const db &c) const { return P(x / c, y / c); }
    T operator^(const P &p) const { return x * p.y - y * p.x; }
    T operator*(const P &p) const { return x * p.x + y * p.y; }
    bool operator==(const P &p) const
    {
        return abs(x - p.x) + abs(y - p.y) < EPS;
    }
    bool operator!=(const P &p) const {
        return x != p.x or y != p.y;
    }
    bool operator<(const P &p) const
    {
        return abs(x - p.x) > EPS ? p.x - x > EPS : p.y - y > EPS;
    }
};

istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, const P &p) {
    return s << '(' << p.x << ", " << p.y << ')';
}

T turn(P &a, P &b, P &c) { return (b - a) ^ (c - a); }

bool inDisk(P &a, P &b, P &p) { return (a - p) * (b - p) <= 0; }

bool onSegment(P &a, P &b, P &p) {
    return abs(turn(a, b, p)) < EPS && inDisk(a, b, p); 
}


bool above(P &a, P &p) { return p.y >= a.y; }

bool crossesRay(P &a, P &p, P &q) {
    return (above(a, q) - above(a, p)) * turn(a, p, q) > 0;
}

bool inPolygon(vector<P> &p, P &a, bool strict = true) {
    int c = 0, n = p.size();
    rep(i, n) {
        if(onSegment(p[i], p[(i + 1) % n], a)) return !strict;
        c += crossesRay(a, p[i], p[(i + 1) % n]);
    }
    return c & 1;
}



bool inPols(vector<vector<P>>& Ps, P p) {
    for(auto& P: Ps) if(inPolygon(P, p, 1)) return 1;
    return 0;
}

void bloquear(P &a, P &b, P &p, P &d, vector<bool> &V) {
    bool border = 1;
    P perp = (d.y != 0? P(1, 0): P(0, 1));
    P p1 = p + perp, p2 = p - perp;
    // cout<<"Segmento: "<<a<<' '<<b<<", puntos: "<<p<<' '<<p1<<' '<<p2<<'\n';
    if(onSegment(a, b, p1)) {
        if(d.y != 0) V[2] = 0;
        else V[0] = 0;
    }
    else border = 0;
    if(onSegment(a, b, p2)) {
        if(d.y != 0) V[3] = 0;
        else V[1] = 0;
    }
    else border = 0;

    if(border) {
        if(d.y == 1) V[1] = 0;
        if(d.y == -1) V[0] = 0;
        if(d.x == 1) V[3] = 0;
        if(d.x == -1) V[2] = 0;
    }
}

void bloquear2(P &d, vector<bool> &V) {
    if(d.y == 1) V[1] = 0;
    if(d.y == -1) V[0] = 0;
    if(d.x == 1) V[3] = 0;
    if(d.x == -1) V[2] = 0;
}

void bloquear22(P &d, vector<bool> &V) {
    if(d.y == 1) V[3] = 0, V[2] = 0;
    if(d.y == -1) V[2] = 0, V[3] = 0;
    if(d.x == 1) V[1] = 0, V[0] = 0;
    if(d.x == -1) V[0] = 0, V[1] = 0;
}

void bloquear3(P& d, vector<bool>& V) {
    if(d.x > 0) V[1] = 0;
    if(d.x < 0) V[0] = 0;
    if(d.y > 0) V[2] = 0;
    if(d.y < 0) V[3] = 0;
} 


P ref(P &d, P & p1, P &p2) {
    if(d.x == 1) {
        if(p1.x < p2.x) return p1;
        return p2;
    }
    if(d.x == -1) {
        if(p1.x < p2.x) return p2;
        return p1;
    }
    if(d.y == 1) {
        if(p1.y < p2.y) return p1;
        return p2;
    }
    // d.y == -1
    if(p1.y < p2.y) return p2;
    return p1;
}
// N, S, E, W
vector<P> Dif = { P(0, 1), P(0, -1), P(1, 0), P(-1, 0) };

bool inrange(P &p) { return 0 <= p.x and p.x <= 100 and 0 <= p.y and p.y <= 100; }

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
    int n; cin>>n;
    vector<vector<P>> Ps(n, vector<P>());
    vector<P> Dir(n);
    rep(i, n) {
        char c; cin>>c;
        if(c == 'N') Dir[i] = P(0, 1); 
        if(c == 'S') Dir[i] = P(0, -1);
        if(c == 'E') Dir[i] = P(1, 0);
        if(c == 'W') Dir[i] = P(-1, 0);
        int v; cin>>v;
        Ps[i].resize(v);
        rep(j, v) cin>>Ps[i][j].x>>Ps[i][j].y;
    }

    vector<vi> D(202, vi(202, -1));
    D[x1][y1] = 0;
    vector<vector<P>> S(20004, vector<P>());
    int t = 0;
    S[0].push_back(P(x1, y1));
    while(t < 20004 and !S[t].empty()) {
        // cout<<"tiempo: "<<t<<'\n';
        for(auto& u: S[t]) {
            // cout<<"visito a: "<<u.x<<' '<<u.y<<'\n';
            if(inPols(Ps, u)) { 
                S[t + 1].push_back(u);
                continue;
            }

            // marco los que no puedo visitar
            vector<bool> V(4, 1);
            rep(i, n) { 
                auto& Pol = Ps[i];
                rep(j, Pol.size()) {
                    P &p1 = Pol[j], &p2 = Pol[(j + 1) % Pol.size()];
                    P &p3 = Pol[(j + 2) % Pol.size()], p0 = Pol[(j - 1 + Pol.size()) % Pol.size()];
                    P aux = p2 - p1;
                    P perp = (Dir[i].x != 0? P(0, 1): P(1, 0));
                    if(onSegment(p1, p2, u) and (aux ^ Dir[i]) > 0) {
                        // cout<<"intersecto en un segmento: "<<p1<<' '<<p2<<"\n";
                        bloquear(p1, p2, u, Dir[i], V);
                        // cout<<"bloqueo1: "<<V[0]<<' '<<V[1]<<' '<<V[2]<<' '<<V[3]<<'\n';
                    }
                    P px = u - Dir[i];
                    if(p1 != px and p2 != px and onSegment(p1, p2, px) and (aux ^ Dir[i]) > 0) {
                        // cout<<"intersecto en el segmento: "<<p1<<' '<<p2<<'\n';
                        bloquear2(Dir[i], V);
                        // cout<<"bloqueo21: "<<V[0]<<' '<<V[1]<<' '<<V[2]<<' '<<V[3]<<'\n';
                    }
                    if((px == p1 or u == p1) and (aux ^ Dir[i]) == 0 and (Dir[i] ^ (p1 - p0)) < 0 and ((p2 - p1) ^ (p1 - p0)) < 0) {
                        // cout<<"entre aca para "<<u<<" en el tiempo "<<t<<'\n';
                        bloquear2(Dir[i], V);
                        if(u == p1) bloquear22(Dir[i], V);
                    }
                    if((px == p2 or u == p2) and (aux ^ Dir[i]) == 0 and (Dir[i] ^ (p3 - p2)) < 0 and ((p2 - p1) ^ (p3 - p2)) > 0) {
                        bloquear2(Dir[i], V);
                        if(u == p2) bloquear22(Dir[i], V);
                    }
                    
                    if(u != ref(Dir[i], p1, p2) and onSegment(p1, p2, u) and (aux ^ Dir[i]) == 0) {
                        // cout<<"entre al bloqueo 3\n";
                        bloquear3(aux, V);
                        // cout<<"bloqueo3: "<<V[0]<<' '<<V[1]<<' '<<V[2]<<' '<<V[3]<<'\n';
                    }
                }
            }
            // cout<<"Habilitados: "<<V[0]<<' '<<V[1]<<' '<<V[2]<<' '<<V[3]<<'\n';
            bool nx = 0; // 0: no tengo vecinos por visitar, 1: tengo vecinos por visitar
            rep(i, 4) {
                P aux = u + Dif[i];
                if(inrange(aux)) {
                    if(V[i] == 0 and D[aux.x][aux.y] == -1) nx = 1;
                    else if(V[i] and D[aux.x][aux.y] == -1) { // visito al vecino
                        D[aux.x][aux.y] = t + 1;
                        S[t + 1].push_back(aux);
                    }
                }
            }
            if(nx) S[t + 1].push_back(u);
            // cout<<'\n';
        }
        // cout<<'\n';
        // avanza el tiempo
        rep(i, n) for(auto& p: Ps[i]) p = p + Dir[i];
        t++;
    }

    cout<<D[x2][y2]<<'\n';



    return 0;
}