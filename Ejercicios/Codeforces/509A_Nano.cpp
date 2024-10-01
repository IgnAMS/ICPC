#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int mat[n][n];
  for(int i=0;i<n;i++){
    mat[0][i]=1;
    mat[i][0]=1;
  }
  for(int i=1;i<n;i++){
    for(int j=1;j<n;j++){
      mat[i][j]= mat[i-1][j]+mat[i][j-1];
    }
  }
  cout<<mat[n-1][n-1]<<endl;


  return 0;
}
