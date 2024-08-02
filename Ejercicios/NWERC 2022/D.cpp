#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define repx(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define rep(i, n) repx(i, 0, n)
#define ff first
#define ss second
typedef pair<ll, ll> pll;

const double PI = acos(-1.0L);


ll dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
ll dc[] = {0, 0, -1, 1, -1, 1, -1, 1};


struct Point {
    ll i, j;
    double d;
    Point(ll i, ll j, db d): i(i), j(j), d(d) {}
    bool operator<(const Point& p) const { return d < p.d; }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    string mat[n]; 
    rep(i, n) cin>>mat[i];
    
    db D[2 * n + 1][2 * m + 1];
    rep(i, 2 * n + 1) rep(j, 2 * m + 1) D[i][j] = 1e12;
    D[0][0] = 0;
    
    priority_queue<Point, vector<Point>> pq;
    pq.push(Point(0, 0, 0));

    while(!pq.empty()) {
        Point u = pq.top(); pq.pop();
        if(-u.d > D[u.i][u.j]) continue;
        rep(h, 4) {
            Point v = Point(u.i + dr[h], u.j + dc[h], u.d - 5);
            // no puedo ir al centro de una figura
            if((v.i % 2) == 1 and (v.j % 2) == 1) continue;
            if(0 <= v.i and v.i <= 2 * n and 0 <= v.j and v.j <= 2 * m and D[v.i][v.j] > -v.d) {
                D[v.i][v.j] = -v.d;
                pq.push(v);
            }
        }
        repx(h, 4, 8) {
            Point v = Point(u.i + dr[h], u.j + dc[h], u.d - PI * 2.5);
            // no puedo ir al centro de una figura
            if((v.i % 2) == 1 and (v.j % 2) == 1) continue;
            if(dr[h] == -1 and u.i == 0) continue;
            if(dc[h] == -1 and u.j == 0) continue;
            int ti = (u.i - (dr[h] == -1)) / 2, tj = (u.j - (dc[h] == -1)) / 2; 
            if(ti == n or tj == m) continue;
            
            if(mat[ti][tj] == 'X') continue;
            if(0 <= v.i and v.i <= 2 * n and 0 <= v.j and v.j <= 2 * m and D[v.i][v.j] > -v.d) {
                D[v.i][v.j] = -v.d;
                pq.push(v);
            }
        }
    }
    cout<<setprecision(16)<<fixed<<D[2 * n][2 * m]<<'\n';



    return 0;
}