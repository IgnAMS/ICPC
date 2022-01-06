#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
#define ff first
#define ss second

const double PI = acos(-1.0L);
const double EPS = 1e-15;

typedef long double T;  // can be integer
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


double turn(P &a, P &b, P &c) { return (b - a) ^ (c - a); }

bool properInter(P &a, P &b, P &c, P &d, P &out)
{
    double ta = turn(c, d, a), tb = turn(c, d, b),
           tc = turn(a, b, c), td = turn(a, b, d);
    out = (a * tb - b * ta) / (tb - ta);
    return (ta * tb < 0 && tc * td < 0);
}
bool inDisk(P &a, P &b, P &p) { return (a - p) * (b - p) <= 0; }

bool onSegment(P &a, P &b, P &p)
{
    return abs(turn(a, b, p)) < EPS && inDisk(a, b, p);
}

set<P> inter(P &a, P &b, P &c, P &d)
{
    P out;
    if (properInter(a, b, c, d, out)) return {out};
    set<P> ans;
    if (onSegment(c, d, a)) ans.insert(a);
    if (onSegment(c, d, b)) ans.insert(b);
    if (onSegment(a, b, c)) ans.insert(c);
    if (onSegment(a, b, d)) ans.insert(d);
    return ans;
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int w, p; cin>>w>>p;
    P target;
    cin>>target.x>>target.y;
    vector<pair<P,P>> lines;
    rep(i,w){
        long double a,b,c,d; cin>>a>>b>>c>>d;
        pair<P,P> aux= {{a,b},{c,d}};
        lines.emplace_back(aux);
    }

    vector<pair<P,P>> r; //puntos
    rep(i,p) {
        P aux,auxr; cin>>aux.x>>aux.y>>auxr.x>>auxr.y;
        r.emplace_back(aux,auxr);
    }
    
    for(auto& u: r){
        bool flag=true;
        //reviso si es que esta dentro del alcance
        if(!((target-u.ff).norm2()<=(u.ss-u.ff).norm2()+EPS && ((target-u.ff)*(u.ss-u.ff)) > -EPS)){
            cout<<"not visible\n";
            continue;
        }

        for(auto& v: r){
            if(u.ff == v.ff) continue;
            //colineales y en rango
            /*
            if((target-u.ff)*(v.ff-u.ff) > -EPS && ((u.ff-target)*(v.ff-target)) > -EPS 
                && fabs((target-u.ff)^(v.ff-u.ff)) < EPS){
                cout<<"not visible\n";
                flag=false; break;
            }
            */
            if(onSegment(u.ff,target,v.ff)) {
                cout<<"not visible\n";
                flag=false; break;
            }
        }

        if(!flag) continue;

        for(auto& v: lines){
            set<P> s=inter(u.ff,target,v.ff,v.ss);
            if(!s.empty()){
                cout<<"not visible\n";
                flag=false; break;
            }
        }

        if(!flag) continue;
        cout<<"visible\n";
    }


    return 0;
}