#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int n,k;
vector<string> mat;
/*
string DP[i][]

string dp(int i, int j, int x){
    if(DP[i][j]!="!") return DP[i][j];
    if(i==n-1 && j==n-1){
        if(x>0) return 'a';
        return DP[i][j]=mat[i][j];
    }
    if(i==n){

    }
 }
*/


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    mat.resize(n);
    rep(i,n) cin>>mat[i];
    char ans[n][n];
    int changes[n][0];
    memset(changes,k,sizeof(memset));
    
    ans[0][0]=mat[0][0];
    if(mat[0][0]!='a'){
        if(k==0) ans[0][0]= mat[0][0];
        else { ans[0][0]='a'; changes[0][0]=1; } 
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i][j]=mat[i][j];
            if(mat[i][j]=='a') continue;
            int op1=1e6, op2=1e6;

            if(i>0){
                if(changes[i-1][j]<k) { 
                    ans[i][j]='a';
                    op1=changes[i-1][j]+1;
                }
                else op1= changes[i-1][j];
            }
            if(j>0){
                if(changes[i][j-1]<k) { 
                    ans[i][j]='a';
                    op2=changes[i][j-1]+1;
                } 
                else op2= changes[i][j-1];
            }
            changes[i][j-1]
            
        }
    }

    return 0;
}