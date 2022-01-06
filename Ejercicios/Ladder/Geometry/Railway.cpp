#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;
typedef double db;

const db PI = acos(-1.0L);
const db EPS = 1e-12;

// POINT 2D

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

P polar(db r, db a) { return P(r * cos(a), r * sin(a)); }
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, const P &p)
{
    return s << '(' << p.x << ", " << p.y << ')';
}

db ang(db a)
{
    while (a >= 2. * PI) a -= 2. * PI;
    while (a < 0) a += 2. * PI;
    return a;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); 
    P m;
    while(cin>>m){
        int n; cin>>n;
        vector<P> Points(n+1); rep(i,n+1) cin>>Points[i];
        double ans = 1e10;
        P vec_ans;
        rep(i, n){
            P u = Points[i] - m, p = Points[i];
            P d = Points[i+1] - Points[i];
            if((p - m).norm() < ans){
                ans = (p-m).norm();
                vec_ans = p;
            }
            if(d*d < EPS) continue;
            double t = -1.0 * (u*d / (d*d));
            if(-EPS < t && t < 1 +EPS && (p+d*t - m).norm() < ans){
                ans = (p+d*t-m).norm();
                vec_ans = p+d*t;
            }
            
        }
        if((Points.back() - m).norm() < ans){
            ans = (Points.back()-m).norm();
            vec_ans = Points.back();
        }
        cout<<setprecision(4)<<fixed<<vec_ans.x<<"\n"<<vec_ans.y<<"\n";
    }
    





    return 0;
}