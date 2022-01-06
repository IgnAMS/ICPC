#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > mat;

void printmat(){
  for(int i=0;i<mat.size();i++){
    for(int j=0;j<mat[i].size();j++){
      cout<<mat[i][j]<<" ";
    }
    cout<<endl;
  }

}

void reina(int n,int m){
  mat.assign(n,vector<int> (m,0));

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(mat[i][j]==1) continue;
      else if(mat[i][j]==){
        mat[i][j]=-1;
        for(int k=0;k<m;k++) {
          if(k==j) continue;
          mat[i][k]=1;
        }
        for(int k=0;k<n;k++){
          if(k==i) continue;
          mat[k][j]=1;
        }
        for(int k=1;k<max(n,m);k++){
          if(0<=i+k && i+k<n && 0<=j+k && j+k<m){
            mat[i+k][j+k]=1;
          }
          if(0<=i-k && i-k<n && 0<=j+k && j+k<m){
            mat[i-k][j+k]=1;
          }
          if(0<=i+k && i+k<n && 0<=j-k && j-k<m){
            mat[i+k][j-k]=1;
          }
          if(0<=i-k && i-k<n && 0<=j-k && j-k<m){
            mat[i-k][j-k]=1;
          }
        }
        printmat();
        cout<<endl<<endl;
      }
    }
  }
  return;
}


int main(){
  int n,m;
  cin>>n>>m;
  reina();


  return 0;
}
