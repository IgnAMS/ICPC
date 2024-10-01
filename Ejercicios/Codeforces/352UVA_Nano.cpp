#include<bits/stdc++.h>
using namespace std;

int dr[]={-1,-1,-1,0,1,1, 1,-1};
int dc[]={-1, 0, 1,1,1,0,-1,-1};



int mat[25][25];
int ent[25][25];
int cont=0;

void init(){
  cont=0;
  for(int i=0;i<25;i++){
    for(int j=0;j<25;j++){
      mat[i][j]=0;
      ent[i][j]=0;
    }
  }
}
bool state=true;
int asd=0;

void dfs(int a,int b,int d){
  if(mat[a][b]) return;
  mat[a][b]=1;
  asd++;

  if(state && ent[a][b]>0){
    state=false;
    cont++;
  }

  for(int r=0;r<8 && ent[a][b]>0;r++){
    for(int c=0;c<8;c++){
      if(dr[r]+a<d && dc[c]+b<d && dr[r]+a>=0 && dc[c]+b>=0 && ent[dr[r]+a][dc[c]+b]>0){
        dfs(dr[r]+a,dc[c]+b,d);
      }
    }
  }

}



int main(){
  int n;
  int t=0;
  while(cin>>n){
    t++;
    init();
    string linea;
    for(int i=0;i<n;i++){
      cin>>linea;
      for(int j=0;j<n;j++){
        ent[i][j]=linea[j]-'0';
      }
    }
    //cout<<"termine el cin\n";
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        state=true;
        dfs(i,j,n);
      }
    }
    //cout<<asd<<endl;
    printf("Image number %d contains %d war eagles.\n",t,cont);
    //cout<<cont<<endl;
  }



  return 0;
}
