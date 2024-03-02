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


typedef ll T; 
struct P {
    T x, y;
    P() {} P(T x, T y) : x(x), y(y) {}

    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const ll &c) const { return P(x * c, y * c); }
    P operator/(const ll &c) const { return P(x / c, y / c); }
    T operator^(const P &p) const { return x * p.y - y * p.x; }
    T operator*(const P &p) const { return x * p.x + y * p.y; }
    bool operator==(const P &p) const {
        return abs(x - p.x) + abs(y - p.y) <= 0;
    }
    bool operator<(const P &p) const {
        return abs(x - p.x) > 0 ? p.x - x > 0 : p.y - y > 0;
    }
};

T turn(P &a, P &b, P &c) { return (b - a) ^ (c - a); }
bool inDisk(P &a, P &b, P &p) { return (a - p) * (b - p) <= 0; }

bool onSegment(P &a, P &b, P &p) {
    return abs(turn(a, b, p)) < 0 && inDisk(a, b, p); 
}

bool above(P &a, P &p) { return p.y >= a.y; }

bool crossesRay(P &a, P &p, P &q) {
    return (above(a, q) - above(a, p)) * turn(a, p, q) > 0;
}

bool inPolygon(vector<P> &p, P &a, bool strict = false) {
    int c = 0, n = p.size();
    rep(i, n) {
        if (onSegment(p[i], p[(i + 1) % n], a)) return !strict;
        if(p[i] == a) return !strict;
        c += crossesRay(a, p[i], p[(i + 1) % n]);
    }
    return c & 1;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        vector<P> R[2];
        vector<vl> E, E2;

        ll ans = 0;
        rep(i, 2) {
            ll x1, y1, x2, y2; 
            cin>>x1>>y1>>x2>>y2;
            R[i].pb(P(x1, y1));
            R[i].pb(P(x2, y1));
            R[i].pb(P(x2, y2));
            R[i].pb(P(x1, y2));
            ans = max(ans, (x2 - x1) * (y2 - y1));
            // entrada y salida
            E.pb({x1, 0, y1, y2});
            E.pb({x2, 1, y1, y2});
            E2.pb({y1, 0, x1, x2});
            E2.pb({y2, 1, x1, x2});
        }

        bool pos = 0;
        rep(i, 2) rep(j, 4) {
            if(inPolygon(R[i], R[i ^ 1][j], false)) pos = 1;
        }
        if(!pos) {
            cout<<ans<<'\n';
            continue;
        }


        sort(E.begin(), E.end());
        sort(E2.begin(), E2.end());

        multiset<ll> H;
        rep(i, E.size()) {
            auto curr = E[i];
            if(i and H.size() > 0) {
                auto prev = E[i - 1];
                ll low = *H.begin(), high = *H.rbegin();
                // cout<<prev[0]<<' '<<curr[0]<<' '<<low<<' '<<high<<'\n';
                ans = max(ans, (curr[0] - prev[0]) * (high - low));
            }
            if(curr[1] == 0) {
                H.insert(curr[2]);
                H.insert(curr[3]);
            }
            else {
                H.erase(H.find(curr[2]));
                H.erase(H.find(curr[3]));
            }
        }

        rep(i, E2.size()) {
            auto curr = E2[i];
            if(i and H.size() > 0) {
                auto prev = E2[i - 1];
                ll low = *H.begin(), high = *H.rbegin();
                // cout<<low<<' '<<high<<' '<<prev[0]<<' '<<curr[0]<<'\n';
                ans = max(ans, (curr[0] - prev[0]) * (high - low));
            }

            if(curr[1] == 0) {
                H.insert(curr[2]);
                H.insert(curr[3]);
            }
            else {
                H.erase(H.find(curr[2]));
                H.erase(H.find(curr[3]));
            }
        }
        cout<<ans<<'\n';
        
    }


    return 0;
}