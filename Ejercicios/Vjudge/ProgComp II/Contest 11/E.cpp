#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
const double PI = acos(-1.0L);
const double EPS = 1e-12;
#define ff first
#define ss second

// POINT 2D

typedef double T; struct P
{
    T x, y;
    P() {} P(T x, T y) : x(x), y(y) {}

    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const double &c) const { return P(x * c, y * c); }
    P operator/(const double &c) const { return P(x / c, y / c); }
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
    double norm() const { return sqrt(norm2()); }
    double ang()
    {
        double a = atan2(y, x);
        if (a < 0) a += 2. * PI;
        return a;
    }
    P unit() { return (*this) / norm(); }
    P perp() { return P(-y, x); }
    P rot(P r) { return P((*this) ^ r, (*this) * r); }
    P rot(double a){ return rot(P(sin(a), cos(a))); }
};
typedef pair<int,P> ip;

P polar(double r, double a) { return P(r * cos(a), r * sin(a)); }

istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

bool half(P &p) { return p.y > 0 || (p.y == 0 && p.x > 0); }

void polarSort(vector<ip> &v){
    sort(v.begin(), v.end(), [](ip &P1, ip &P2){
        P p1=P1.ss, p2=P2.ss; 
        int h1 = half(p1), h2 = half(p2);
        return h1 != h2 ? h1 > h2 : (p1 ^ p2) > 0;
    });
}


T turn(P &a, P &b, P &c) { return (b - a) ^ (c - a); }
bool above(P &a, P &p) { return p.y >= a.y; }
bool crossesRay(P &a, P &p, P &q){
    return (above(a, q) - above(a, p)) * turn(a, p, q) > 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int p,v;
    while(cin>>p>>v){
        cerr<<p<<" "<<v<<"\n";
        vector<P> plant(p),fence(v);
        vector<pair<int,P>> E,faux;
        //0 -> plant    1 -> fence
        rep(i,p) { cin>>plant[i]; E.emplace_back(i,plant[i]); }
        rep(i,v) { cin>>fence[i]; faux.emplace_back(1,fence[i]); E.emplace_back(0,fence[i]); }
        polarSort(E);
        polarSort(faux);
        P last= (*faux.rbegin()).ss;
        P next= (*faux.rbegin()).ss;

        ll ans=0;
        for(auto& u: E){
            cout<<u.ff<<" "<<u.ss.x<<" "<<u.ss.y<<"\n";
            if(u.ff=0)
                P aux=next, next=u.ss, last=aux;

            else{
                // c += crossesRay(a, p[i], p[(i + 1) % n]);
                int c=0;
                P O={0,0};
                c+=crossesRay(u.ss,last,next);
                c+=crossesRay(u.ss,next,O);
                c+=crossesRay(u.ss,O,last);
                if(!(c&1)) ans+=u.ff;
            }
        }
        cout<<ans<<"\n";
    }



    return 0;
}