#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int n;
vector<ll> S;
ll DP[2010][2010];

ll dp(int i, int j){
    if(i == j) return 0;
    if(DP[i][j] != -1) return DP[i][j];
    return DP[i][j] = S[j] - S[i] + min(dp(i+1, j), dp(i, j-1));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    S.resize(n); rep(i,n) cin>>S[i];
    sort(S.begin(), S.end());
    memset(DP, -1, sizeof DP);
    cout<<dp(0, n-1)<<"\n";
    return 0;
}