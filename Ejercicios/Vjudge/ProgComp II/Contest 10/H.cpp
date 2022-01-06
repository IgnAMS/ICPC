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
    cout.precision(7);
    set<double> s;
    double xi,yi;
    double t1,t2;
    P a1,a2,b1,b2;

    int n; cin>>n;
    map<double,P> m1;
    double t=0;
    cin>>xi>>yi;
    P a = {xi,yi};
    a1=a;
    rep(i,n-1){
        cin>>xi>>yi; P b={xi,yi};
        m1[t]=b;
        s.insert(t);
        t1=t;
        t+= (b-a).norm();
        a=b;
    }

    int m; cin>>m;
    map<double,P> m2;
    t=0;
    cin>>xi>>yi;
    a = {xi,yi};
    b1=a;
    rep(i,m-1){
        cin>>xi>>yi; P b={xi,yi};
        m2[t]=b;
        s.insert(t);
        t2=t;
        t+= (b-a).norm();
        a=b;
    }
    double ti=0;
    double mini= 1e9;
    for(auto& u: s){
        if(m1.count(u)) { a2=m1[u]; }
        if(m2.count(u)) { b2=m2[u]; }
        //cout<<"a1: "<<a1.x<<" "<<a1.y<<"\n";
       // cout<<"b1: "<<b1.x<<" "<<b1.y<<"\n";
        double tf= min((a1-a2).norm(),(b1-b2).norm());
        P va= (a2-a1)/(a2-a1).norm();
        P vb= (b2-b1)/(b2-b1).norm();
        P d1= a1-b1;
        P d2= va-vb;
        //cout<<(d2*d2)<<"\n";

        if(d2.norm2()!=0 && 0<= -(d1*d2)/(d2*d2) && -(d1*d2)/(d2*d2) <=tf){
            //cout<<"punto critico\n";
            double aux= -(d1*d2)/(d2*d2);
            mini = min(mini, (a1+va*aux-(b1+vb*aux)).norm());
        }
        
        mini=min({mini, (a1-b1).norm(), (a1+va*tf-(b1+vb*tf)).norm()});
        a1= a1+va*tf;
        b1= b1+vb*tf;
        //cout<<u<<" "<<mini<<"\n";
    }

    cout<<mini<<"\n";

    return 0;
}