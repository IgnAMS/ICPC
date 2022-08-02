#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int, int> ii;
typedef double db;
typedef vector<int> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt


int n, k, m;
vector<vector<ii>> G;
int mat[82][82];
int DP[2][82][82][82][2]; // u: side, k: profundidad, l: left, r: right
int dp(bool lft, int k_, int l, int r, bool type) {
    int &ans = DP[lft][k_][l][r][type];
    if(ans != -1) return ans;
    if(k_ == 1) return 0;
    
    ans = 1e8;
    // cout<<(lft? l: r)<<' '<<k_<<", rango: "<<l<<' '<<r<<", type: "<<type<<'\n';

    if(type) { // hacia afuera
        ans = dp(lft, k_, l, r, !type); // busco hacia adentro
        if(lft) {
            rep(i, l) if(mat[l][i] != 1e8) 
                ans = min(ans, dp(1, k_ - 1, i, l, type) + mat[l][i]);
        }
        else {
            repx(i, r + 1, n + 1) if(mat[r][i] != 1e8) 
                ans = min(ans, dp(0, k_ - 1, r, i, type) + mat[r][i]);
        }
    }

    else { // hacia adentro
        repx(i, l + 1, r) {
            if(lft and mat[l][i] != 1e8) {
                ans = min(ans, dp(0, k_ - 1, l, i, type) + mat[l][i]);
                ans = min(ans, dp(1, k_ - 1, i, r, type) + mat[l][i]);
            }
            if(!lft and mat[r][i] != 1e8) {
                ans = min(ans, dp(0, k_ - 1, l, i, type) + mat[r][i]);
                ans = min(ans, dp(1, k_ - 1, i, r, type) + mat[r][i]);
            }
        }
    }

    return ans;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k>>m;
    G.assign(n + 2, vector<ii>());
    rep(a, 2) rep(b, 82) rep(c, 82) rep(d, 82) rep(e, 2) DP[a][b][c][d][e] = -1;
    rep(u, 82) rep(v, 82) mat[u][v] = 1e8;
    rep(i, m) {
        int u, v, w; cin>>u>>v>>w;
        mat[u][v] = min(mat[u][v], w);
    }
    // rep(i, n + 1) rep(j, n + 1) cout<<mat[i][j]<<" \n"[j == n]; 
    int ans = 1e8;
    rep(i, n + 1) ans = min({ans, dp(1, k, i, i, 1), dp(0, k, i, i, 1)});
    rep(i, n + 1) ans = min({ans, dp(1, k, i, n + 1, 0), dp(0, k, 0, i, 0)});
    cout<<(ans == 1e8? -1: ans)<<'\n';

    return 0;
}