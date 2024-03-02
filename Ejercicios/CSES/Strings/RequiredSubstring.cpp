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

vl KMP(string& p) {
    int n = p.size();
    vl L(n);
    L[0] = 0;
    rep(j, n - 1) {
        int i = L[j];
        while(p[i] != p[j + 1] && i) i = L[i - 1];
        L[j + 1] = (p[i] == p[j + 1] ? i + 1 : 0);
    }
    return L;
}

const int MOD = 1e9+7;
int DP[1001][26][100][2];
int n, m; 
string s;
vl L;

int dp(int i, int c, int j, int b) {
    if(i == n and b == 1) return 1;
    if(i == n) return 0;
    
    int &ans = DP[i][c][j][b];
    if(ans != -1) return ans;
    
    ans = 0;
    rep(c2, 26) {
        if(b == 0 and c2 != s[j] - 'A') {
            int j2 = j;
            while(s[j2] - 'A' != c2 and j2) j2 = L[j2 - 1];
            if(c2 == s[j2] - 'A') ans += dp(i + 1, c2, j2 + 1, b);
            else ans += dp(i + 1, c2, 0, b);
        }
        else if(b == 0 and c2 == s[j] - 'A' and j == m - 1) {
            ans += dp(i + 1, c2, 0, 1);
        }
        else if(b == 0 and c2 == s[j] - 'A') {
            ans += dp(i + 1, c2, j + 1, b);
        }
        else ans += dp(i + 1, c2, 0, b);

        if(ans >= MOD) ans -= MOD;
    }
    return ans;
}




int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    cin>>s;
    m = s.length();
    L = KMP(s);
    memset(DP, -1, sizeof(DP));
    
    int ans = 0;
    rep(c2, 26) {
        if(c2 != s[0] - 'A') {
            ans += dp(1, c2, 0, 0);
        }
        else if(c2 == s[0] - 'A' and 0 == m - 1) {
            ans += dp(1, c2, 0, 1);
        }
        else if(c2 == s[0] - 'A') {
            ans += dp(1, c2, 1, 0);
        }
        if(ans >= MOD) ans -= MOD;
    }
    cout<<ans<<'\n';

    return 0;
}