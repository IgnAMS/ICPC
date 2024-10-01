#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,m,cx,cy;
    cin>>n>>m>>cx>>cy;
    char mat[n][m];
    int cont=0;
    bool bul= cy<2*cx;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin>>mat[i][j];
      }
    }
    long long cost=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(mat[i][j]=='.'){
          if(j<m-1 && bul && mat[i][j+1]=='.'){
            cost+=cy;
            j++;
          }
          else{
            cost+=cx;
          }
        }
      }
    }
    cout<<cost<<endl;

  }


  return 0;
}
