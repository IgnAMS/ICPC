#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<ll> vl;
#define rep(i, n) for(int i = 0; i < n; i++)

const int mxN = 105;
int dp[mxN][mxN][mxN];
pair<char, array<int, 3>> go[mxN][mxN][mxN];



int main() {
    string s1, s2 , v;
    cin >> s1 >> s2 >> v;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    reverse(v.begin(), v.end());
    s1 += " ";
    s2 += " ";
    v += " ";
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    reverse(v.begin(), v.end());
    int n = s1.size();
    int m = s2.size();
    int k = v.size();
    memset(dp, 0x0c, sizeof(dp));
    memset(go, -1, sizeof(go));
    rep(i, n){
        rep(j, m){
            rep(t, k){
                if(i && dp[i][j][k] < dp[i-1][j][k]){
                    dp[i][j][k] = dp[i-1][j][k];
                    go[i][j][k] = {"", {-1, 0, 0}};
                }
                if(dp[i][j][k] < dp[i][j-1][k]){
                    dp[i][j][k] = dp[i][j-1][k];
                    go[i][j][k] = {"", {0, -1, 0}};
                }
                if(s1[i] == s2[j]){
                    
                }
                if(i && j && dp[i][j][k] < dp[i-1][j-1][])
            }
        }
    }

    rep(i, k-1){

    }
    if(dp[n-1][m-1][k-1])
}