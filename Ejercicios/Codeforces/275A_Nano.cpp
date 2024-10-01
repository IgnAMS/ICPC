#include<bits/stdc++.h>
using namespace std;

int dc[]={1,0,-1, 0};
int dr[]={0,1, 0,-1};



int main(){
  int grid[3][3];
  int aux[3][3];
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin>>grid[i][j];
      aux[i][j]=1;
      if(grid[i][j]%2==0) grid[i][j]=0;
      else grid[i][j]=1;
    }
  }

  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(grid[i][j]==1){

        if(aux[i][j]==1) aux[i][j]=0;
        else aux[i][j]=1;
        for(int h=0;h<4;h++){
          if(i+dc[h]<3 && j+dr[h]<3 && i+dc[h]>=0 && j+dr[h]>=0){
            if(aux[i+dc[h]][j+dr[h]]==1) aux[i+dc[h]][j+dr[h]]=0;
            else if(aux[i+dc[h]][j+dr[h]]==0) aux[i+dc[h]][j+dr[h]]=1;
            //cout<<i+dc[h]<<" "<<j+dr[h]<<" "<<aux[i+dc[h]][j+dr[h]]<<"\t";
          }
        }
        //cout<<i<<" "<<j<<endl;
      }
    }
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cout<<aux[i][j];
    }
    cout<<endl;
  }

  return 0;
}
