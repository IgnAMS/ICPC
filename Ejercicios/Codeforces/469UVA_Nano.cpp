#include<bits/stdc++.h>
using namespace std;

int dr[]={-1,-1,-1,0,1,1, 1,-1};
int dc[]={-1, 0, 1,1,1,0,-1,-1};



int mat[100][100];
int ent[100][100];
int cont=0;

void init(){
  cont=0;
  for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
      mat[i][j]=0;
      ent[i][j]='L';
    }
  }
}

void desmarc(){
  for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
      mat[i][j]=0;
    }
  }
}
bool state=true;
int asd=0;

void dfs(int a,int b){
  if(mat[a][b]) return;
  mat[a][b]=1;
  cont++;

  for(int r=0;r<8 && ent[a][b]>0;r++){
    for(int c=0;c<8;c++){
      if(dr[r]+a>=0 && dc[c]+b>=0 && ent[dr[r]+a][dc[c]+b]=='W'){
        dfs(dr[r]+a,dc[c]+b);
      }
    }
  }

}



int main(){
  int n;
  int t=0;
  cin>>t;
  int cas=0;
  char car;
  bool salto=false;
  string linea;
  int row=0;
  init();
  getchar();

  while(getline(cin,linea)){
    if(linea[0]=='L'||linea[0]=='W'){
      if(salto){
        init();
        cas++;
        salto=false;
        if(cas<t) cout<<endl;
      }

      for(int i=0;i<linea.length();i++){
        ent[row][i]=linea[i];
      }
      row++;
    }
    else if(linea.length()==0) continue;
    else{
      row=0;
      salto=true;
      int posr=0,posc=0;
      bool fila=true;
      cont=0;
      desmarc();
      for(int i=0;i<linea.length();i++){
        if(linea[i]<='9' && linea[i]>='0' && fila){
          posr*=10;
          posr+=linea[i]-'0';
        }
        else if(linea[i]<='9' && linea[i]>='0' && !fila){
          posc*=10;
          posc+=linea[i]-'0';
        }
        else{
          fila=false;
        }
      }
      posr--;
      posc--;
      if(ent[posr][posc]=='W') dfs(posr,posc);
      cout<<cont<<endl;
    }

  }



  return 0;
}
