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

const int mxN = 3e5 + 5;
int Next[mxN][10];
int DP[12][mxN];
int A[15], B[15];
int m;

int dp(int i, int pos) {
    // cerr<<i<<' '<<pos<<'\n';
    if(i == m) return 0;
    if(DP[i][pos] != -1) return DP[i][pos];
    if(Next[pos][A[i]] == -1) return DP[i][pos] = 1;
    if(Next[pos][B[i]] == -1) return DP[i][pos] = 1;
    DP[i][pos] = 0;
    repx(j, A[i], B[i] + 1) {
        if(Next[pos][j] == -1) return DP[i][pos] = 1;
        DP[i][pos] = max(DP[i][pos], dp(i + 1, Next[pos][j]));
    }
    // DP[i][pos] = max(dp(i + 1, Next[pos][A[i]]), dp(i + 1, Next[pos][B[i]]));
    return DP[i][pos];
} 

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    memset(Next, -1, sizeof(Next));
    memset(DP, -1, sizeof(DP));
    while(t--) {
        string s; cin>>s;
        int n = s.length();
        // 3 * 10^5 * log2(3 * 10^5) * 10
        vector<vl> L(10, vl());
        rep(i, n) {
            int d = s[i] - '0';
            L[d].pb(i + 1);
        }
        rep(i, n + 1) {
            rep(j, 10) {
                auto it = upper_bound(L[j].begin(), L[j].end(), i);
                if(it != L[j].end()) Next[i][j] = *it;
            }
        }
    
        cin>>m;
        string sA, sB; cin>>sA>>sB;
        rep(i, m) A[i] = sA[i] - '0', B[i] = sB[i] - '0';
        cout<<(dp(0, 0)? "YES": "NO")<<'\n';
        rep(i, n + 2) rep(j, 12) Next[i][j] = -1, DP[j][i] = -1;
    }

    return 0;
}