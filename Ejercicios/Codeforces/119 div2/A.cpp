#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int n,a,b,c;
int DP[4000+2];


int main(){
    cin>>n>>a>>b>>c;
    memset(DP,0,sizeof(DP));
    DP[0]=0;
    DP[a]=1;
    DP[b]=1;
    DP[c]=1;
    rep(i,n+1){
        if(i-a>=0 && DP[i-a]!=0){
            DP[i]=DP[i-a]+1;
        }
        if(i-b>=0 && DP[i-b]!=0){
            DP[i]=max(DP[i-b]+1,DP[i]);
        }
        if(i-c>=0 && DP[i-c]!=0){
            DP[i]=max(DP[i-c]+1,DP[i]);
        }
        //cout<<i<<" "<<DP[i]<<endl;
    }
    cout<<DP[n]<<endl;

    return 0;
}