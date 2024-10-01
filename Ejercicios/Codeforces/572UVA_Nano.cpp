#include<bits/stdc++.h>
using namespace std;

int dr[]={-1,-1,-1,0,1,1, 1,-1};
int dc[]={-1, 0, 1,1,1,0,-1,-1};



int mat[100][100];
int ent[100][100];
int cont=0;

void init(int a, int b){
  cont=0;
  for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
      mat[i][j]=0;
      ent[i][j]=0;
    }
  }
}
bool state=true;
int asd=0;

void dfs(int a,int b,int d1,int d2){
  if(mat[a][b]) return;
  mat[a][b]=1;
  asd++;

  if(state && ent[a][b]>0){
    state=false;
    cont++;
  }

  for(int r=0;r<8 && ent[a][b]>0;r++){
    for(int c=0;c<8;c++){
      if(dr[r]+a<d1 && dc[c]+b<d2 && dr[r]+a>=0 && dc[c]+b>=0 && ent[dr[r]+a][dc[c]+b]!=0){
        dfs(dr[r]+a,dc[c]+b,d1,d2);
      }
    }
  }

}



int main(){
  int n,m;
  int t=0;
  while(cin>>m>>n){
    if(m==0 && n==0) break;
    t++;
    init(m,n);
    string linea;
    for(int i=0;i<m;i++){
      cin>>linea;
      for(int j=0;j<n;j++){
        ent[i][j]=linea[j]-'*';
      }
    }
    //cout<<"termine el cin\n";
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        state=true;
        dfs(i,j,m,n);
      }
    }
    //cout<<asd<<endl;
    //printf("Image number %d contains %d war eagles.\n",t,cont);
    cout<<cont<<endl;
  }



  return 0;
}
