#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    int n; cin>>n;
    ll memo[n+1][n+1];
    memset(memo,0,sizeof(memo));
    for(int i=3;i<n+1;i++) memo[i][2]=1; 
    memo[3][2]=1;
    memo[4][2]=1;
    ll ans;
    for(int i=5;i<=n;i++){
        ans=0;
        for(int j=2;j<=i/2;j++){
            memo[i][j]+=ll(memo[i-j][j]);
            memo[i][j]+=memo[i-j][j-1];
            ans+=memo[i][j];
        }
    }
    cout<<ans<<endl;


    return 0;
}