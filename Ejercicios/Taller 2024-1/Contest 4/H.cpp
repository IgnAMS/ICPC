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

const ll INF = 1e16;
ll n, m, p, q;

struct Edge {
    ll i, j, d;
    bool operator>(const Edge& e) const {
        return d > e.d;
    }
};

// Right, Left, Down, Up
ll dr[] = {0, 0, 1, -1};
ll dc[] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>p>>q;
    
    string mat[n];
    rep(i, n) cin>>mat[i];

    ll D[n][m];
    ll C[n][m];
    ll ind = 0;
    vector<pll> P;
    rep(i, n) rep(j, m) D[i][j] = INF, C[i][j] = -1;

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    rep(i, n) rep(j, m) {
        if(mat[i][j] == '.') {
            D[i][j] = 0, C[i][j] = ind++;
            P.pb({i, j});
            pq.push({i, j, 0});
        }
    }
    map<char, pll> dif;
    dif['U'] = {1, 0}, dif['D'] = {-1, 0}, dif['L'] = {0, 1}, dif['R'] = {0, -1};

    while(!pq.empty()) {
        auto [i, j, d] = pq.top(); pq.pop();
        if(D[i][j] < d) continue;
        rep(h, 4) {
            int di = i + dr[h], dj = j + dc[h];
            if(0 <= di and di < n and 0 <= dj and dj < m and mat[di][dj] != '#') {
                ll w = 0;

                if(h <= 1 and (mat[di][dj] == 'L' or mat[di][dj] == 'R')) w = q;
                else if(h <= 1) w = p;
                if(h > 1 and (mat[di][dj] == 'L' or mat[di][dj] == 'R')) w = p;
                else if(h > 1) w = q;

                di += dif[mat[di][dj]].ff, dj += dif[mat[di][dj]].ss;

                if(D[di][dj] > d + w) {
                    C[di][dj] = C[i][j];
                    D[di][dj] = d + w;
                    pq.push({di, dj, D[di][dj]});
                }
            }
        }
    }

    ll ans = INF;
    rep(i, n) rep(j, m) {
        rep(h, 4) {
            int di = i + dr[h], dj = j + dc[h];
            if(0 <= di and di < n and 0 <= dj and dj < m and mat[di][dj] != '#' and D[di][dj] < INF) {
                int id1 = C[i][j], id2 = C[di][dj];
                if(id1 == id2) continue;
                ll dx = abs(P[id1].ff - P[id2].ff), dy = abs(P[id1].ss - P[id2].ss);
                if(dx == 1 and dy == 1) continue;
                ans = min(ans, D[i][j] + D[di][dj]);
            }
        }
    }
    if(ans == INF) cout<<"-1\n";
    else cout<<ans<<'\n';


    return 0;
}