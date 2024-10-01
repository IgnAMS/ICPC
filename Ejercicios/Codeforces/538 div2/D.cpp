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

// DP[i][j][0] = minimum number of steps to have the range [i + 1, j - 1] with color C[i]
// DP[i][j][1] = minimum number of steps to have the range [i + 1, j - 1] with color C[j]

int n; 
int C[5001];
int DP[5003][5003][2];
const int INF = 1e6;

int dp(ll i, ll j, ll b) {
    // cerr<<i<<' '<<j<<' '<<n<<'\n';
    if(i == 0 and j == n + 1) return 0;
    if(DP[i][j][b] != -1) return DP[i][j][b];
    DP[i][j][b] = INF;

    // No hay cambio de color
    if(i != 0     and b == 0 and C[i] == C[i + 1]) DP[i][j][b] = min(DP[i][j][b], dp(i - 1, j, 0));
    if(i != 0     and b == 1 and C[i] == C[j - 1]) DP[i][j][b] = min(DP[i][j][b], dp(i - 1, j, 1));
    if(j != n + 1 and b == 1 and C[j] == C[j - 1]) DP[i][j][b] = min(DP[i][j][b], dp(i, j + 1, 1));
    if(j != n + 1 and b == 0 and C[j] == C[i + 1]) DP[i][j][b] = min(DP[i][j][b], dp(i, j + 1, 0));
    
    // Si hay cambio de color
    if(i != 0     and b == 0 and C[i] != C[i + 1]) DP[i][j][b] = min(DP[i][j][b], dp(i - 1, j, 0) + 1);
    if(i != 0     and b == 1 and C[i] != C[j - 1]) DP[i][j][b] = min(DP[i][j][b], dp(i - 1, j, 0) + 1);
    if(j != n + 1 and b == 1 and C[j] != C[j - 1]) DP[i][j][b] = min(DP[i][j][b], dp(i, j + 1, 1) + 1);
    if(j != n + 1 and b == 0 and C[j] != C[i + 1]) DP[i][j][b] = min(DP[i][j][b], dp(i, j + 1, 1) + 1);
    // cout<<"i, j, b, col: "<<i<<' '<<j<<' '<<C[b? j - 1: i + 1]<<' '<<DP[i][j][b]<<'\n';
    return DP[i][j][b];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i, n) cin>>C[i + 1];

    rep(i, 5003) rep(j, 5003) rep(b, 2) DP[i][j][b] = -1;
    int ans = INF;
    repx(i, 1, n + 1) ans = min(ans, dp(i - 1, i + 1, 0));
    cout<<ans<<'\n';


    return 0;
}