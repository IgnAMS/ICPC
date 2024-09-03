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
    P(ll x, ll y): x(x), y(y) {}
    P operator+(const P& p) const { return P(x + p.x, y + p.y); }
    P operator-(const P& p) const { return P(x - p.x, y - p.y); }
    P operator*(ll c) const { return P(c * x, y * x); }
    P operator/(ll c) const { return P(x / c, y / c); }
    ll operator*(const P& p) const { return x * p.x + y * p.y; }
    ll operator^(const P& p) const { return x * p.y - y * p.x; }
    bool operator<(const P &p) const {
        return p.x != x? p.x > x : p.y > y;
    }
    ll norm1() { return abs(x) + abs(y); }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, const P &p)     {
    return s << '(' << p.x << ", " << p.y << ')';
}

ll turn(P a, P b, P c) {
    return (b - a) ^ (c - a);
}

bool half(P &p) { return p.y > 0 || (p.y == 0 && p.x > 0); }

void polarSort(vector<P> &v) {
    sort(v.begin(), v.end(), [](P &p1, P &p2) {
        int h1 = half(p1), h2 = half(p2);
        if(h1 != h2) return h1 > h2;
        if((p1 ^ p2) != 0) return (p1 ^ p2) > 0;
        // Collinear case
        return (p1 * p1) > (p2 * p2);
    });
}

const int mxN = 1e5+5;
struct ST {
    ll T[4 * mxN];
    void update(ll i, ll x, ll l = 0, ll r = mxN, ll u = 0) {
        if(l == r) T[u] = x;
        else {
            ll m = (l + r) / 2;
            if(i <= m) update(i, x, l, m, 2 * u + 1);
            else update(i, x, m + 1, r, 2 * u + 2);
            T[u] = T[2 * u + 1] + T[2 * u + 2];
        }
    }
    ll query(ll i, ll j, ll l = 0, ll r = mxN, ll u = 0) {
        if(i <= l and r <= j) return T[u];
        if(r < i or j < l) return 0;
        ll m = (l + r) / 2;
        return query(i, j, l, m, 2 * u + 1) + query(i, j, m + 1, r, 2 * u + 2);
    }
} st;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    P s, e; cin>>s>>e;
    int n; cin>>n;
    vector<P> ps[2];
    ll cont1 = 0, cont2 = 0;

    rep(i, n) {
        P p; cin>>p;
        // Colineal con la (s, e)
        if(turn(p, s, e) == 0) {
            if(p < s) cont1++;
            else cont2++;
            continue;
        }
        if(turn(s, p, e) > 0) ps[0].pb(p);
        else ps[1].pb(p);
    }

    ll ans = 0;
    ans += cont1 * (cont1 - 1) / 2;
    ans += cont2 * (cont2 - 1) / 2;
    
    rep(b, 2) {
        n = ps[b].size();
        // Ordeno e indexo respecto a s
        vector<P> ps_s(n);

        // Quiero que esten sobre la linea 
        rep(i, n) ps_s[i] = ps[b][i] - s;
        polarSort(ps_s);
        map<P, ll> mp;
        rep(i, n) mp[ps_s[i] + s] = i;
        cout<<"ordenados respecto a "<<s<<":\n";
        rep(i, n) cout<<ps_s[i] + s<<' '<<mp[ps_s[i] + s]<<", "; cout<<'\n';


        // Ordeno respecto a e
        vector<P> ps_e(n);
        rep(i, n) ps_e[i] = ps[b][i] - e;
        polarSort(ps_e);
        cout<<"ordenados respecto a "<<e<<":\n";
        rep(i, n) cout<<ps_e[i] + e<<' '<<mp[ps_e[i] + e]<<", "; cout<<'\n';

        // Cuento las inversiones
        vl Id(n);
        rep(i, n) Id[i] = mp[ps_e[i] + e];
        rep(i, n) {
            ans += st.query(Id[i], n);
            st.update(Id[i], 1);
        }
        rep(i, n) st.update(i, 0);
    } 

    cout<<ans<<'\n';


    return 0;
}