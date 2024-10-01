#include<bits/stdc++.h>
using namespace std;

//int dc[]={-1, 0, 1,1,1,0,-1,-1};
//int dr[]={-1,-1,-1,0,1,1, 1, 0};

int dc1[]={-1,-1,0};
int dr1[]={ 0,-1,-1};

int dc2[]={ 0, 1,1};
int dr2[]={-1,-1,0};

int dc3[]={-1,-1,0};
int dr3[]={ 0, 1,1};

int dc4[]={0,1,1};
int dr4[]={1,1,0};


int main(){
  char mat[4][4];
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      cin>>mat[i][j];
    }
  }
  //cout<<"aaa\n";
  bool state=false;
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      int contb=0;
      int contw=0;
      //primer cuad
      for(int h=0;h<3;h++){
        if(i+dr1[h]>=0 && i+dr1[h]<4 && j+dc1[h]>=0 && j+dc1[h]<4 && mat[i+dr1[h]][j+dc1[h]]=='#') contb++;
        if(i+dr1[h]>=0 && i+dr1[h]<4 && j+dc1[h]>=0 && j+dc1[h]<4 && mat[i+dr1[h]][j+dc1[h]]=='.') contw++;
      }
      if(contb==3 || contw==3){
        state=true;
        break;
      }
      contb=0;
      contw=0;
      //segundo cuad
      for(int h=0;h<3;h++){
        if(i+dr2[h]>=0 && i+dr2[h]<4 && j+dc2[h]>=0 && j+dc2[h]<4 && mat[i+dr2[h]][j+dc2[h]]=='#') contb++;
        if(i+dr2[h]>=0 && i+dr2[h]<4 && j+dc2[h]>=0 && j+dc2[h]<4 && mat[i+dr2[h]][j+dc2[h]]=='.') contw++;
      }
      if(contb==3 || contw==3){
        state=true;
        break;
      }
      contb=0;
      contw=0;
      //tercer cuad
      for(int h=0;h<3;  h++){
        if(i+dr3[h]>=0 && i+dr3[h]<4 && j+dc3[h]>=0 && j+dc3[h]<4 && mat[i+dr3[h]][j+dc3[h]]=='#') contb++;
        if(i+dr3[h]>=0 && i+dr3[h]<4 && j+dc3[h]>=0 && j+dc3[h]<4 && mat[i+dr3[h]][j+dc3[h]]=='.') contw++;
      }
      if(contb==3 || contw==3){
        state=true;
        break;
      }
      contb=0;
      contw=0;
      //cuarto cuad
      for(int h=0;h<3;h++){
        if(i+dr4[h]>=0 && i+dr4[h]<4 && j+dc4[h]>=0 && j+dc4[h]<4 && mat[i+dr4[h]][j+dc4[h]]=='#') contb++;
        if(i+dr4[h]>=0 && i+dr4[h]<4 && j+dc4[h]>=0 && j+dc4[h]<4 && mat[i+dr4[h]][j+dc4[h]]=='.') contw++;
      }
      if(contb==3 || contw==3){
        state=true;
        break;
      }
    }
  }
  if(state) cout<<"YES\n";
  else cout<<"NO\n";


  return 0;
}
