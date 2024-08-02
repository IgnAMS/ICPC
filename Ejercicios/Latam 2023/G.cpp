#pragma GCC optimize("Ofast")
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

struct P {
    ll x, y; 
    P(): x(0), y(0) {}
    P (ll x, ll y): x(x), y(y) {}
    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const ll c) const { return P(x * c, y * c); }
    P operator/(const ll c) const { return P(x / c, y / c); }
    ll operator*(const P &p) const { return x * p.x + y * p.y; }
    ll operator^(const P &p) const { return  x * p.y - y * p.x; }
    bool operator<(const P& p) const { return x < p.x or (x == p.x and y < p.y); }
    bool operator<=(const P& p) const { return x < p.x or (x == p.x and y <= p.y); }
    bool operator==(const P& p) const { return x == p.x and y == p.y; }
    ll norm2() { return x * x + y * y; }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, const P &p)
{
    return s << '(' << p.x << ", " << p.y << ')';
}

ll turn(P& a, P& b, P& c) {
    return (b - a) ^ (c - a);
}

bool inDisk(P &a, P &b, P &p) { return (a - p) * (b - p) <= 0; }

bool onSegment(P &a, P &b, P &p) {
    return abs(turn(a, b, p)) == 0 && inDisk(a, b, p); 
}

bool properInter(P &a, P &b, P &c, P &d, P &out) {
    ll ta = turn(c, d, a), tb = turn(c, d, b),
      tc = turn(a, b, c), td = turn(a, b, d);
    if(tb - ta == 0) return 0;
    
    out = (a * tb - b * ta) / (tb - ta);
    return (ta * tb < 0 && tc * td < 0);
}

set<P> inter(P &a, P &b, P &c, P &d) {
    P out;
    if(a == b) {
        if(onSegment(c, d, a)) return {a};
        return {};    
    }

    if (properInter(a, b, c, d, out)) return {out};
    set<P> ans;
    if (onSegment(c, d, a)) ans.insert(a);
    if (onSegment(c, d, b)) ans.insert(b);
    if (onSegment(a, b, c)) ans.insert(c);
    if (onSegment(a, b, d)) ans.insert(d);
    return ans;
}


const int mxN = 1e5+5;
ll X[mxN], Y[mxN], D[mxN];
int n;

ll check_zero(P& zero) {
    rep(i, n) {
        if(abs(X[i] - zero.x) + abs(Y[i] - zero.y) != D[i]) return 0;

    }
    return 1;
}



P dir[5] = {P(0, 1), P(-1, 0), P(0, -1), P(1, 0), P(0, 1)};
vector<pair<P, P>> Inter(pair<P, P>& par, int i) {
    vector<pair<P, P>> Segment;
    rep(h, 4) {
        // Creo el segmento 
        pair<P, P> seg_eval = {P(X[i], Y[i]) + dir[h] * D[i], P(X[i], Y[i]) + dir[h + 1] * D[i]};
        // Consigo la interseccion:
        set<P> S = inter(par.first, par.second, seg_eval.first, seg_eval.second);
        if(S.size() == 1) {
            Segment.pb({*S.begin(), *S.begin()});
        }
        if(S.size() == 2) {
            P p1 = *S.begin(), p2 = *S.rbegin();
            Segment.pb({p1, p2});
        }
    }

    sort(Segment.begin(), Segment.end(), [&](pair<P, P> a, pair<P, P> b){
        return a.first <= b.first;
    });
    
    vector<pair<P, P>> ans;
    P init(-100000, -100000), last(-100000, -100000);
    for(auto& u: Segment) {
        P &p1 = u.first, &p2 = u.second;
        if((p1 < last or p1 == last) and last < p2) last = p2;
        else if(last < p1) {
            if(init.x != -100000) ans.pb({init, last});
            init = p1, last = p2;
        }
    }
    if(init.x != -100000) ans.pb({init, last});
    return ans;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    P zero(-100000, -100000);
    rep(i, n) {
        cin>>X[i]>>Y[i]>>D[i];
        if(D[i] == 0) zero = P(X[i], Y[i]);
    }
    // Check zero
    if(zero.x != -100000) {
        if(check_zero(zero)) cout<<zero.x<<' '<<zero.y<<'\n';
        return 0;
    }
    
    // El caso del 0 ya fue manejado, ahora veremos solo para 
    // el primer rectangulo e intersectaremos
    vector<pair<P, P>> ans = {
        {P(X[0], Y[0] + D[0]), P(X[0] - D[0] + 1, Y[0] + 1)},
        {P(X[0] - D[0], Y[0]), P(X[0] - 1, Y[0] - D[0] + 1)},
        {P(X[0], Y[0] - D[0]), P(X[0] + D[0] - 1, Y[0] - 1)},
        {P(X[0] + D[0], Y[0]), P(X[0] + 1, Y[0] + D[0] - 1)}
    };

    for(auto& [p1, p2]: ans) {
        if(p2 < p1) swap(p1, p2);
    }

    repx(i, 1, n) {
        vector<pair<P, P>> new_ans;
        for(auto& line: ans) {
            vector<pair<P, P>> intersection = Inter(line, i);
            for(auto new_line: intersection) new_ans.pb(new_line);
            // cout<<"transformo la linea "<<line.ff<<" -> "<<line.ss<<" en: \n";
            // for(auto& [p1, p2]: intersection) cout<<p1<<" -> "<<p2<<"; \t"; cout<<'\n';
        }
        ans = new_ans;
    }

    // cout<<"respuesta:\n";
    vector<P> Pans;
    for(auto& [p1, p2]: ans) {
        P dir = p2 - p1;
        ll val = dir.x;
        if(dir.x != 0) dir = dir / abs(dir.x);
        rep(i, val + 1) {
            P pans = p1 + dir * i;
            Pans.pb(p1 + dir * i);
        }
    }
    sort(Pans.begin(), Pans.end());
    for(auto p: Pans) cout<<p.x<<' '<<p.y<<'\n';

    return 0;
}