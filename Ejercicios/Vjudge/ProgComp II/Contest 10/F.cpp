#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

const double PI = acos(-1.0L);
const double EPS = 1e-12;

typedef double T;  // can be integer
struct P
{
    T x, y;
    P() {}
    P(T x, T y) : x(x), y(y) {}

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



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    double x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
    P a= {x1,y1};
    P b= {x2,y2};
    int q; cin>>q;
    rep(i,q){
        double xi,yi; cin>>xi>>yi;
        P c={xi,yi};
        if(((b-a)^(c-a))>0) cout<<"I\n";
        if(abs((b-a)^(c-a)) == 0) cout<<"C\n";
        if(((b-a)^(c-a))<0) cout<<"D\n";
        //cout<< ((b-a)^(c-a))<<"\n";
    }

    return 0;
}