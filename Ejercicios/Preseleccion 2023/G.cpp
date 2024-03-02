#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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

// i pasos, me quedan 
ll DP[49][36][36][36][36]; 
string A;


set<vector<ll>> S = {{9, 12, 15, 12}, {15, 6, 21, 6}, {0, 18, 6, 18}};
bool inmat(int u, int r, int d, int l) {
    if(u % 3 == 0 and r % 6 == 0) return 1;
    // if(S.count({u, r, d, l})) return 1;
    return 0;
}

// 0 <= r - l <= 7
// 0 <= d - u <= 7
ll dp(int i, int u, int r, int d, int l) {
    if(i == 48 and d - u == 6 and r - l == 0 and inmat(u, r, d, l)) return 1;
    else if(i == 48) return 0;
    // cout<<i<<' '<<u<<' '<<r<<' '<<d<<' '<<l<<' '<<A[i]<<'\n';
    if(DP[i][u][r][d][l] != -1) return DP[i][u][r][d][l];
    if(A[i] != '?') {
        if(A[i] == 'L' and r - l >= 1 and l < 18) DP[i][u][r][d][l] = dp(i + 1, u, r, d, l + 1);
        else if(A[i] == 'L') return 0;

        if(A[i] == 'R' and r - l < 7 and r < 18) DP[i][u][r][d][l] = dp(i + 1, u, r + 1, d, l);
        else if(A[i] == 'R') return 0;
        
        if(A[i] == 'U' and d - u >= 1 and u < 18) DP[i][u][r][d][l] = dp(i + 1, u + 1, r, d, l);
        else if(A[i] == 'U') return 0;
        
        if(A[i] == 'D' and d - u < 7 and l < 18) DP[i][u][r][d][l] = dp(i + 1, u, r, d + 1, l);
        else if(A[i] == 'D') return 0;
    }
    else {
        DP[i][u][r][d][l] = 0;
        // Me puedo mover a la derecha <-> r - l < 7
        if(r - l < 7 and r < 18) DP[i][u][r][d][l] += dp(i + 1, u, r + 1, d, l);
        // Me ouedo mover a la izquierda <-> r - l > 1
        if(r - l >= 1 and l < 18) DP[i][u][r][d][l] += dp(i + 1, u, r, d, l + 1);
        // Me puedo mover para arriba <-> d - u > 1
        if(d - u >= 1 and u < 18) DP[i][u][r][d][l] += dp(i + 1, u + 1, r, d, l);
        // Me puedo mover para la abajo <-> d - u < 7  
        if(d - u < 7 and d < 18) DP[i][u][r][d][l] += dp(i + 1, u, r, d + 1, l);
    }
    return DP[i][u][r][d][l];
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>A;
    rep(i, 49) rep(a, 36) rep(b, 36) rep(c, 36) rep(d, 36) DP[i][a][b][c][d] = -1;
    cout<<dp(0, 0, 0, 0, 0)<<'\n';

    return 0;
}