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

struct DSU {
    vl p, acc, tol, left, right; 
    DSU(int N) : p(N, -1), acc(N, 0), tol(N, 0), left(N), right(N) {}
    int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -p[get(x)]; }
    void unite(int x, int y) {
        if ((x = get(x)) == (y = get(y))) return;
        if (p[x] > p[y]) swap(x,y);
        p[x] += p[y], p[y] = x;
        tol[x] = min(tol[x], tol[y]);
        acc[x] += acc[y];
        // cerr<<"uno a "<<x<<" con "<<y<<", la tolerancia queda en "<<tol[x]<<" y el acc en "<<acc[x]<<'\n';
        if(sameSet(x, right[x])) right[x] = right[y];
        if(sameSet(x, left[x])) left[x] = left[y];
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll s[n]; rep(i, n) cin>>s[i];


    ll l = 0, r = 1e13;
    while(l < r) {
        ll m = (l + r) / 2;
        // cerr<<"pruebo con "<<l<<' '<<m<<' '<<r<<'\n';

        DSU dsu(n);
        rep(i, n) {
            dsu.tol[i] = dsu.acc[i] = s[i];
            dsu.left[i] = (i - 1 + n) % n, dsu.right[i] = (i + 1) % n;
        }
        rep(i, n) if(dsu.get(i) == i and s[i] <= m) {
            ll right_same = !dsu.sameSet(i, dsu.right[dsu.get(i)]);
            ll left_same = !dsu.sameSet(i, dsu.left[dsu.get(i)]);
            ll right_tol = dsu.tol[dsu.right[dsu.get(i)]] <= dsu.acc[dsu.get(i)] + m;
            ll left_tol = dsu.tol[dsu.left[dsu.get(i)]] <= dsu.acc[dsu.get(i)] + m;
                
            while(
                (right_same and right_tol) or (left_same and left_tol)
            ) {
                if(right_same and right_tol) 
                    dsu.unite(i, dsu.right[dsu.get(i)]);
                if(left_same and left_tol)
                    dsu.unite(i, dsu.left[dsu.get(i)]);
                right_same = !dsu.sameSet(i, dsu.right[dsu.get(i)]);
                left_same = !dsu.sameSet(i, dsu.left[dsu.get(i)]);
                right_tol = dsu.tol[dsu.right[dsu.get(i)]] <= dsu.acc[dsu.get(i)] + m;
                left_tol = dsu.tol[dsu.left[dsu.get(i)]] <= dsu.acc[dsu.get(i)] + m;
                // cout<<right_same<<' '<<right_tol<<' '<<left_same<<' '<<left_tol<<'\n';
                // cerr<<((right_same and right_tol) or (left_same and left_tol))<<'\n';
            }
            // cerr<<"el right de "<<i<<" es "<<dsu.right[dsu.get(i)]<<'\n';
            // cerr<<"el left de "<<i<<" es "<<dsu.left[dsu.get(i)]<<'\n';
        }

        if(dsu.p[dsu.get(0)] == -n) r = m;
        else l = m + 1;
    }
    cout<<l<<'\n';


    return 0;
}