#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define repx(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;
typedef double db;
#define pb push_back
 
const db PI = acos(-1.0L);
const db EPS = 1e-12;
 
// POINT 2D
 
typedef ll T; struct P
{
    T x, y;
    P() {} P(T x, T y) : x(x), y(y) {}
 
    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const db &c) const { return P(x * c, y * c); }
    P operator/(const db &c) const { return P(x / c, y / c); }
    T operator^(const P &p) const { return x * p.y - y * p.x; }
    T operator*(const P &p) const { return x * p.x + y * p.y; }
    bool left2(P p, P q){return ((q-p)^(*this-p))>0;}
    bool operator==(const P &p) const {
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
 
T turn(P &a, P &b, P &c) { return (b - a) ^ (c - a); }
 
 
void normalize(vector<P>& p) { // Normalize respect to the leftmost point
    int n = p.size();
    if(turn(p[0], p[1], p[2]) > 0) reverse(p.begin(), p.end());
    // int pi = min_element(p.begin(), p.end()) - p.begin();
    // vector<P> s(n);
    // rep(i, n) s[i] = p[(pi + i) % n];
    // p.swap(s);
}

bool inConvexPol(vector<P>& p, P& q) {
    if(turn(p[0], p[1], q) > 0 or turn(p.back(), p[0], q) > 0) return 0;
    int l = 1, r = p.size() - 2;
    while(l < r) {
        ll m = (l + r + 1) / 2;
        if(turn(p[0], p[m], q) <= 0) l = m;
        else r = m - 1;
    }
    return turn(p[l], p[l + 1], q) <= 0;
}



void normalize1(vector<P> &p){
	int n=p.size();
	if(p[2].left2(p[0],p[1]))reverse(p.begin(), p.end());
	int pi=min_element(p.begin(),p.end())-p.begin();
	vector<P> s(n);
	repx(i,0,n) s[i] = p[(pi+i)%n];
	p.swap(s);
}



bool haslog(vector<P> &p, P q){
	if(q.left2(p[0],p[1]) || q.left2(p.back(),p[0])) {
        return 0;
    }
    int a = 1, b = p.size() - 1;
	while(b - a > 1){
		int c = (a + b) / 2;
		if(!q.left2(p[0], p[c]))a=c;
		else b=c;
	}
	return !q.left2(p[a],p[a+1]);
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    vector<P> Points(n); 
    rep(i,n) cin>>Points[i];
    vector<P> Points2;
    rep(i, n) {
        if(Points2.empty()) Points2.pb(Points[i]);
        else {
            // cout<<i<<" "<<(Points2.back() - Points[i]) * (Points[(i+1)%n] - Points[i])<<' '<<turn(Points2.back(), Points[i], Points[(i + 1)%n])<<'\n';
            if(((Points2.back() - Points[i]) * (Points[(i+1)%n] - Points[i])) < 0 and turn(Points2.back(), Points[i], Points[(i+1)%n]) == 0) {
                continue;
            }
            else Points2.pb(Points[i]);
        }
        
    }
    // for(auto p: Points2) cout<<p<<'\n';

    vector<P> X = Points2, Y = Points2;
    normalize(X);
    normalize1(Y);
    // for(auto p: X) cout<<p<<", "; cout<<'\n';
    // for(auto p: Y) cout<<p<<", "; cout<<'\n';
    
    rep(_, q){
        P m; cin>>m;
        // ll res1 = inConvexPol(X, m), res2 = haslog(Y, m);
        // cout<<res1<<" "<<res2<<'\n';
        
        // if(haslog(Y, m)) cout<<"D\n";
        if(inConvexPol(X, m)) cout<<"D\n";
        else cout<<"F\n"; 
        // cout<<(flag? "D\n": "F\n");
    }
 
    return 0;
} 

