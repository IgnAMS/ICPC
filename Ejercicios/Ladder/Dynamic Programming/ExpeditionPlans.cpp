#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#include<iostream>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
// typedef vector<ll> vl;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

const int mxN = 3e3+5;
ll DP[mxN][mxN][2];
ll D[mxN], F[mxN], S[mxN], Acc[mxN];

ll cost(int i, int j) { return Acc[j] - Acc[i]; }

int n;

ll ST[2][2][mxN][mxN * 4];
// ST[0][0]: from left to right and then right
// ST[0][1]: from left to right and then 
void set(int pos, ll x, ll *T, int l = 0, int r = mxN, int u = 0) {
    if(l == r) { T[u] = x; }
    else {
        int m = (l + r) / 2;
        if(pos <= m) set(pos, x, T, l, m, 2 * u + 1);
        else set(pos, x, T, m + 1, r, 2 * u + 2);
        T[u] = min(T[2 * u + 1], T[2 * u + 2]);
    }
}

ll query(int i, int j, ll *T, int l = 0, int r = mxN, int u = 0) {
    if(r < i or j < l) return 1e18;
    if(i <= l and r <= j) return T[u];
    ll m = (l + r) / 2;
    return min(query(i, j, T, l, m, 2 * u + 1), query(i, j, T, m + 1, r, 2 * u + 2));
}

void set0(int i, int j, ll x) {
    set(i, x + D[i] + (i + 1 >= j? Acc[i]: Acc[i + 1]), ST[0][0][j]); 
    set(i, x + D[i] - (i + 1 >= j? Acc[i]: Acc[i + 1]), ST[0][1][j]); 
    DP[i][j][0] = x;
}

void set1(int i, int j, ll x) {
    set(j, x + D[j] + Acc[i], ST[1][0][i]);
    set(j, x + D[j] - Acc[i], ST[1][1][i]); 
    DP[i][j][1] = x;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i, n - 1) cin>>S[i];
    rep(i, n) cin>>D[i];
    rep(i, n + 1) cin>>F[i];
    Acc[0] = 0;
    rep(i, n - 1) Acc[i + 1] = Acc[i] + S[i];
    Acc[n] = Acc[n - 1];
    D[n] = 0;
    rep(i, n + 1) rep(j, n + 1) rep(u, 2) DP[i][j][u] = -1; 
    for (int i = 0; i <= n; i++) {
        set0(i, i, F[i]);
        set1(i, i, F[i]);
    }
    repx(d, 1, n + 1) rep(i, n + 1 - d) {
        int j = i + d;
        int l = i, r = j - 1;
        while(l < r) {
            int m = (l + r) / 2;
            if(DP[i][m][1] > DP[m + 1][j][0]) r = m;
            else l = m + 1;
        }
        // DP[i][m][1] > DP[m + 1][j][0]
        cout<<i<<' '<<j<<' '<<l<<'\n';
        cout<<query(i, l, ST[0][0][j])<<' '<<query(l + 1, j, ST[1][0][i])<<'\n';
        cout<<query(i, l, ST[0][0][j]) - Acc[i]<<' '<<query(l, j, ST[1][0][i]) - Acc[i]<<"\n";
        cout<<query(i, l, ST[0][1][j]) + Acc[j]<<' '<<query(l, j, ST[1][1][i]) + Acc[j]<<"\n\n";
        
        set0(i, j, min(query(i, l, ST[0][0][j]), query(l, j - 1, ST[1][0][i])) - Acc[i]);
        set1(i, j, min(query(i, l, ST[0][1][j]), query(l, j - 1, ST[1][1][i])) + Acc[j]);
    }
    cout<<DP[0][n][0]<<'\n';
    // cout<<dp(0, n, 0)<<'\n';

    return 0;
}