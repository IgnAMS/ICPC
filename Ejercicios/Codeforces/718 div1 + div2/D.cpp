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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // 400 * 500 * 500 ~ 10^8
    
    int n, m, k; cin>>n>>m>>k;
    ll H[n][m], V[n][m];
    rep(i, n) rep(j, m - 1) cin>>H[i][j];
    rep(i, n - 1) rep(j, m) cin>>V[i][j];
    if(k & 1 == 1) {
        rep(i, n) {
            rep(j, m) cout<<"-1 "; cout<<'\n';
        }
        return 0;
    }

    k /= 2;
    ll D[n][m][k + 1];
    rep(i, n) rep(j, m) rep(l, k + 1) D[i][j][l] = 1e17;
    priority_queue<array<ll, 4>, vector<array<ll, 4>>> pq;
    rep(i, n) {
        rep(j, m) {
            pq.push({0, i, j, 0});
            D[i][j][0] = 0;
        }
    }
    
    // 10 * 500 * 500 ~ 10^7
    while(!pq.empty()) {
        auto [d, x, y, step] = pq.top(); pq.pop();
        if(step >= k) {
            continue;
        }
        if(-d > D[x][y][step]) continue;

        if(x + 1 < n and D[x + 1][y][step + 1] > D[x][y][step] + V[x][y]) {
            D[x + 1][y][step + 1] = D[x][y][step] + V[x][y];
            if(step + 1 < k) pq.push({-D[x + 1][y][step + 1], x + 1, y, step + 1});
        }
        
        if(x >= 1 and D[x - 1][y][step + 1] > D[x][y][step] + V[x - 1][y]) {
            D[x - 1][y][step + 1] = D[x][y][step] + V[x - 1][y];
            if(step + 1 < k) pq.push({-D[x - 1][y][step + 1], x - 1, y, step + 1});
        }
        
        if(y + 1 < m and D[x][y + 1][step + 1] > D[x][y][step] + H[x][y]) {
            D[x][y + 1][step + 1] = D[x][y][step] + H[x][y];
            if(step + 1 < k) pq.push({-D[x][y + 1][step + 1], x, y + 1, step + 1});
        }
        
        if(y >= 1 and D[x][y - 1][step + 1] > D[x][y][step] + H[x][y - 1]) {
            D[x][y - 1][step + 1] = D[x][y][step] + H[x][y - 1];
            if(step + 1 < k) pq.push({-D[x][y - 1][step + 1], x, y - 1, step + 1});
        }
    }
    rep(i, n) { 
        rep(j, m) cout<<2 * D[i][j][k]<<' '; cout<<'\n';
    }





    return 0;
}