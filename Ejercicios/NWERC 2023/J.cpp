#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
typedef pair<db, db> pdb;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

const int mxN = 12;
const db PI = acos(-1.0L);
db DP[1<<mxN][mxN];

int n;
pdb dir;
pdb X[mxN];
db INF = 1e10;

db cross(pdb p1, pdb p2) {
    return p1.ff * p2.ss - p2.ff * p1.ss;
}
db point(pdb p1, pdb p2) {  
    return p1.ff * p2.ff + p1.ss * p2.ss;
}


db dp(ll mask, ll last) {
    if(mask == (1<<n) - 1) return 0;
    if(DP[mask][last] > -0.5) return DP[mask][last];
    DP[mask][last] = INF;
    rep(i, n) if(!(mask & (1<<i))) {
        pdb dir2 = {X[i].ff - X[last].ff, X[i].ss - X[last].ss};
        db dx = cross(dir, dir2), dy = point(dir, dir2);
        db dist = fabs(dx) + fabs(dy);
        DP[mask][last] = min(
            DP[mask][last],
            dp(mask | (1<<i), i) + dist
        );
    }
    return DP[mask][last];
}




int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i, n) cin>>X[i].ff>>X[i].ss;

    db ans = INF;
    rep(i, n) repx(j, i + 1, n) {
        dir = {X[i].ff - X[j].ff, X[i].ss - X[j].ss};
        db dist = sqrt(dir.ff * dir.ff + dir.ss * dir.ss);
        dir.ff /= dist, dir.ss /= dist;
        // cout<<"evaluo con la direccion "<<dir.ff<<' '<<dir.ss<<'\n';
        // cout<<"norma2: "<<dir.ff * dir.ff + dir.ss * dir.ss<<'\n';
        
        rep(mask, (1<<n)) rep(k, n) DP[mask][k] = -1;
        rep(k, n) ans = min(ans, dp((1<<k), k));
    }

    cout<<setprecision(8)<<fixed<<ans<<'\n';

    return 0;
}