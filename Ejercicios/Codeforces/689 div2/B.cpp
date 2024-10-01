#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
#define ff fisrt
#define ss second

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<vector<int>> R(n,vector<int>(m,0)); //right y left
        vector<vector<int>> L(n,vector<int> (m,0));
        char mat[n][m];
        rep(i,n) rep(j,m) cin>>mat[i][j];
        rep(i,n){
            for(int j=1;j<m;j++){
                if(mat[i][j]=='*' && mat[i][j-1]=='*') L[i][j]=L[i][j-1]+1;
            }
            for(int j=m-2; j>=0;j--){
                if(mat[i][j]=='*' && mat[i][j+1]=='*') R[i][j]=R[i][j+1]+1;
            }
        }
        
        int ans=0;
        rep(i,n) rep(j,m)
            if(mat[i][j]=='*'){
                ans++;
                for(int k=i+1;k<n;k++){
                    if(mat[k][j]=='*' && R[k][j]>=k-i &&  L[k][j]>=k-i){
                        ans++;
                    }
                    else break;
                }
            }

        cout<<ans<<"\n";

    }



    return 0;
}