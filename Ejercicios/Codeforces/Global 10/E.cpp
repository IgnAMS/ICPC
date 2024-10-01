#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll mat[25][25];
    for(int i=0;i<25;i++){
        mat[i][24]=1;
        mat[0][i]=1;
        if(i<24) mat[1][i]=2;
    }
    ll suma;
    ll mini=0;
    for(int i=2;i<24;i++){
        for(int k=23;k>=0;k--){
            suma=0;
            for(int j=0;j<i-1;i++) suma+=mat[0][j];
            for(int j=0;j<=k;j++) suma+=mat[i-1][j];
            mini=(k+1);
            for(int j=0;j<i-1;i++) mini+=mat[j][k];
            mat[i][k]=suma-mini+1;
            cout<<"mat["<<i<<"]["<<k<<"]: "<<mat[i][k]<<endl;


        }
        
    }


    return 0;
}