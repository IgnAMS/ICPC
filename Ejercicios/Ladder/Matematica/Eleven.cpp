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

const int mxn = 110;
ll C[mxn][mxn];
ll mod = 1e9 + 7;
void init_C() {
    C[0][0] = 1;
    repx(i, 1, mxn) {
        C[i][0] = C[i][i] = 1;
        repx(j, 1, i) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
}


ll F[10];
ll DP[10][11][55][55];
// 10 * 11 * 50 * 50 = 250000
ll dp(int d, int m, int pos, int neg) {
    if(d == 10 and m == 0 and pos == 0 and neg == 0) return 1;
    if(pos < 0 or neg < 0 or d == 10) return 0;
    if(DP[d][m][pos][neg] != -1) return DP[d][m][pos][neg];
    DP[d][m][pos][neg] = 0;
    rep(i, F[d] + 1) {
        ll j = F[d] - i;
        ll aux = (C[pos][i] * C[neg][j]) % mod;
        aux = (aux * dp(d + 1, (m + (i - j) * d + 1100) % 11, pos - i, neg - j)) % mod;
        DP[d][m][pos][neg] = (DP[d][m][pos][neg] + aux) % mod; 
    }
    return DP[d][m][pos][neg];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    memset(C, 0, sizeof(C));
    init_C();
    string s; 
    while(cin>>s) {
        int n = s.length();
        rep(i, 10) F[i] = 0;
        for(auto c: s) F[c - '0']++;

        memset(DP, -1, sizeof(DP));
        ll ans = dp(0, 0, n / 2, (n + 1) / 2);
        if(F[0]) {
            memset(DP, -1, sizeof(DP));
            F[0]--;
            ans = (ans - dp(0, 0, n / 2, (n - 1) / 2) + mod) % mod;
        }
        cout<<ans<<'\n';
    }

    return 0;
}