#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int mat[n][100];

  int h;

  for(int i=0;i<n;i++){
    cin>>h;
    for(int j=0;j<100;j++) mat[i][j]=0;

    for(int j=0;j<h;j++){
      mat[i][j]=1;
      //cout<<mat[i][j]<<" ";
    }
    //cout<<endl;
  }

  for(int i=99;i>=0;i--){
    for(int j=n-1;j>=0;j--){

      if(mat[j][i]==1){
        for(int h=j+1; h<n && mat[h][i]==0;h++){
          mat[h][i]=1;
          mat[h-1][i]=0;
          //printf("tome el %d %d y lo movi a %d %d\n",h-1,i,h,i);
        }
        for(int a=0;a<n;a++){
          for(int b=0;b<n;b++){
            //cout<<mat[a][b]<<" ";
          }
          //cout<<endl;
        }
      }
    }
  }

  int cont=0;
  for(int i=0;i<n;i++){
    cont=0;
    for(int j=0;j<100;j++){
      if(mat[i][j]==1) cont++;

    }
    cout<<cont<<" ";
  }
  cout<<endl;

  return 0;
}
