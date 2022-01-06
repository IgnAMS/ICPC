#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repx(i,a,b) for(int i=a; i<b;i++)
typedef long long ll;

int n, m; 
int c[51];

ll DP[255][55]; 

ll dp(ll x, ll i){
    cerr<<x<<" "<<i<<"\n";
    if(x == 0) return 1;
    if(i == m) return 0;
    if(DP[x][i] != -1) return DP[x][i];
    
    DP[x][i] = dp(x, i+1);
    if(x-c[i] >=0) DP[x][i] += dp(x-c[i], i);
    return DP[x][i];
}



int main(){ 
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i, m) cin>>c[i];
    memset(DP, -1, sizeof DP);
    
    cout<<dp(n, 0)<<"\n";

    return 0;
}