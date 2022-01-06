#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int n;
int m;
int coins[50];
ll DP[251][50];
bool D[251];

ll dp(int k, int i){
    if(k==0) return 1;
    if(i==m) return 0;
    ll& ans=DP[k][i];
    
    if(ans!=-1) return ans;
    //opcion 1: no tomes la moneda
    ans=dp(k,i+1);
    //opcion 2: de ser posible, toma la moneda
    if(k-coins[i]>=0) ans+=dp(k-coins[i],i);
    return ans;
}


int main(){
    cin>>n>>m; 
    rep(i,m) cin>>coins[i];
    memset(DP,-1,sizeof(DP));
    //rep(i,n) cout<<dp(i,0)<<endl;
    cout<<dp(n,0)<<endl;
    //rep(i,n) cout<<dp(i,0)<<endl;

    return 0;
}