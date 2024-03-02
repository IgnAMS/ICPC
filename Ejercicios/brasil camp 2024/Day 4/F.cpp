#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(ll i=a; i<b; i++)
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

const int mxN = 100005;
vector<pll> Px;

ll dist(pll x, pll y) {
    return (x.ff - y.ff) * (x.ff - y.ff) + (x.ss - y.ss) * (x.ss - y.ss); 
}

ll min3(ll l, ll r) {
    ll d = 1e17;
    for(int i = l; i <= r; i++) {
        for(int j = i + 1; j <= r; j++) {
            d = min(d, dist(Px[i], Px[j]));
        }
    }
    return d;
}

ll DD(int l, int r, vector<pll> &Py) {
    if(r - l + 1 <= 3) {
        return min3(l, r);
    }

    int m = (l + r) / 2;
    vector<pll> Pyl, Pyr;
    // if Py[i].x <= mid.x -> Pyl += Py[i]
    for(auto u: Py) {
        if(u.ff <= Px[m].ff) Pyl.pb(u);
        else Pyr.pb(u);
    }

    ll dl = DD(l, m, Pyl);
    ll dr = DD(m + 1, r, Pyr);
    ll d = min(dl, dr);

    vector<pll> Pclose;
    for(auto u: Py) {
        if(abs(u.ff - Px[m].ff) < d) Pclose.pb(u);
    }
    
    rep(i, Pclose.size()) {
        repx(j, i + 1, Pclose.size()) {
            if(abs(Pclose[j].ss - Pclose[i].ss) >= d) break;
            d = min(d, dist(Pclose[i], Pclose[j]));
        }
    }
    return d;
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll A[n]; rep(i, n) cin>>A[i];
    
    ll acc = 0;
    vector<pll> Py(n);
    Px.resize(n);

    rep(i, n) {
        acc += A[i];
        Px[i] = {i, acc};
        Py[i] = {acc, i};
    }
    sort(Py.begin(), Py.end());
    rep(i, n) Py[i] = { Py[i].ss, Py[i].ff };

    cout<<DD(0, n - 1, Py)<<'\n';

    return 0;
}