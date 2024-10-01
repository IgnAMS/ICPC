#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n,q; cin>>n>>q;
        vector<ll> arr(n);
        rep(i,n){
            cin>>arr[i];
        }
        ll DP[n+1][4];
        DP[n-1][0]= arr[n-1];
        DP[n-1][1]= -arr[n-1];
        DP[n-1][2]= 0;
        DP[n-1][3]= 0;
        ll maxi=arr[n-1];
        //2 sera que debo ir al 0
        //3 sera que debo ir al 1
        for(int i=n-2;i>=0;i--){    
            for(int j=0;j<4;j++){
                if(j==0) DP[i][j]=max(DP[i+1][3],DP[i+1][1])+arr[i];
                if(j==1) DP[i][j]=max(DP[i+1][2],DP[i+1][0])-arr[i];
                if(j==2) DP[i][j]=max(DP[i+1][0],DP[i+1][2]);
                if(j==3) DP[i][j]=max(DP[i+1][1],DP[i+1][3]);
                //cout<<"i: "<<i<<", j: "<<j<<", DP:"<<DP[i][j]<<"\n";
                maxi=max(maxi,DP[i][j]);
            }
        }
        cout<<maxi<<"\n";
    }



    return 0;
}