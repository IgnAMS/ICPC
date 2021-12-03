#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

const db PI = acos(-1.0L);
const db EPS = 1e-12;


typedef db T; struct P
{
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
    bool operator<(const P &p) const
    {
        return abs(x - p.x) > EPS ? p.x - x > EPS : p.y - y > EPS;
    }

    T norm2() const { return x * x + y * y; }
    db norm() const { return sqrt(norm2()); }
    db ang()
    {
        db a = atan2(y, x);
        if (a < 0) a += 2. * PI;
        return a;
    }
    P unit() { return (*this) / norm(); }
    P perp() { return P(-y, x); }
    P rot(P r) { return P((*this) ^ r, (*this) * r); }
    P rot(db a){ return rot(P(sin(a), cos(a))); }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, const P &p)
{
    return s << '(' << p.x << ", " << p.y << ')';
}

T turn(P &a, P &b, P &c) { return (b - a) ^ (c - a); }

bool inDisk(P &a, P &b, P &p) { return (a - p) * (b - p) <= 0; }

db segPoint(P &a, P &b, P &p)
{
    if ((p - a) * (b - a) >= 0 && (p - b) * (a - b) >= 0)
        return abs(((b - a) ^ (p - a)) / (b - a).norm());
    return min((p - a).norm(), (p - b).norm());
}

bool onSegment(P &a, P &b, P &p)
{
    return abs(turn(a, b, p)) < EPS && inDisk(a, b, p); 
}

bool above(P &a, P &p) { return p.y >= a.y; }

bool crossesRay(P &a, P &p, P &q)
{
    return (above(a, q) - above(a, p)) * turn(a, p, q) > 0;
}

// if strict, returns false when a is on the boundary
bool inPolygon(vector<P> &p, P &a, bool strict = true)
{
    int c = 0, n = p.size();
    rep(i, n)
    {
        if (onSegment(p[i], p[(i + 1) % n], a)) return !strict;
        c += crossesRay(a, p[i], p[(i + 1) % n]);
    }
    return c & 1;
}

vector<vector<int>> G;  // Grafo
vector<vector<P>> Cicles;   // Ciclos 
vector<pair<P, int>> C;
vector<int> D, F;

void dfs(int u, int p, int d) {
    D[u] = d;
    F[u] = p;
    for(auto v: G[u]) if(v != p) {
        if(D[v] != -1) { // ciclo encontrado
            vector<int> c1, c2;
            int x = u, y = v;
            bool oc = 0;
            while(x != y){
                while(D[x] > D[y]) { c1.push_back(x); x = F[x]; }
                while(D[y] > D[x]) { c2.push_back(y); y = F[y]; }
                while(x != y and D[x] == D[y]){
                    c1.push_back(x); c2.push_back(y);
                    x = F[x], y = F[y];
                }
            }
            c1.push_back(x);
            vector<P> cicle;
            rep(i, c1.size()) cicle.push_back(C[c1[i]].ff);
            for(int i = c2.size() - 1; i>=0; i--) cicle.push_back(C[c2[i]].ff);
            Cicles.push_back(cicle);
        }
        else dfs(v, u, d + 1);   
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int b, n, m;
    int test = 0;
    while(cin>>b and b){
        Cicles.clear();
        vector<P> B(b); rep(i, b) cin>>B[i]; // Border
        cin>>n;
        vector<P> I(n); rep(i, n) cin>>I[i]; // Informers
        cin>>m;
        C.resize(m); rep(i, m) cin>>C[i].ff>>C[i].ss; // Circunferencias
        
        G.assign(m, vector<int>()); D.assign(m, -1); F.assign(m, -1);
        rep(i, m) repx(j, i+1, m){ // creo el grafo
            double dx = C[i].ff.x - C[j].ff.x, dy = C[i].ff.y - C[j].ff.y;
            if(dx*dx + dy*dy - EPS <= (C[i].ss + C[j].ss) * (C[i].ss + C[j].ss)){
                G[i].push_back(j); G[j].push_back(i);
            }
        }
        rep(i, m) if(D[i] == -1) dfs(i, -1, 0);
        
        vector<bool> Pos(n, 1);
        rep(i, n) {
            rep(j, m) if((I[i] - C[j].ff).norm2() - EPS <= C[j].ss * C[j].ss) Pos[i] = 0;
            rep(j, Cicles.size()) if(inPolygon(Cicles[j], I[i])) Pos[i] = 0;
        }
        int ind = -1; db ans = 0;
        rep(i, n) if(Pos[i]) {
            double mindist = 10000000;
            rep(j, b) {
                mindist = min(mindist, segPoint(B[j], B[(j+1)%b], I[i]));
            }
            if(ans < mindist) ans = mindist, ind = i;
        }
        if(ind == -1) cout<<"Mission impossible\n";
        else cout<<"Contact informer "<<ind + 1<<'\n';
        
    }

    return 0;
}