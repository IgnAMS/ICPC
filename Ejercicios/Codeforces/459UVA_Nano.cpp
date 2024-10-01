#include<bits/stdc++.h>
using namespace std;

int cont=0;

bool visit[27];
bool num[27][27];


void init(){
  for(int i=0;i<27;i++){
    for(int j=0;j<27;j++){
      num[i][j]=false;
    }
    visit[i]=false;
  }
}
void desm(){
  for(int i=0;i<27;i++) visit[i]=false;
}

void dfs(int a){
  if(visit[a]) return;
  visit[a]=true;
  cont++;
  for(int h=0;h<27;h++){
    if(num[a][h]) dfs(num[a][h]);
  }


}



int main(){
  int t;
  cin>>t;
  getchar();
  string linea;
  int n;
  bool primer=true;
  int skere;
  int test=0;

  while(getline(cin,linea)){
    //cout<<linea.length()<<endl;
    int xddd=linea.length();
    if(xddd==1){

      //if(test==t) break;
      //test++;
      if(!primer){
        if(test<t) cout<<endl;
        for(int i=0;i<27;i++){
          desm();
          cont=0;
          dfs(i);
          skere=max(cont,skere);
          cout<<skere<<endl;
        }
      }
      primer=false;
    }
    else if(xddd==0){
      test++;
      if(t==test)break;
    }
    else{
      skere = 0;
      primer=false;
      num[linea[1]][linea[0]] =true;
      num[linea[0]][linea[1]] =true;
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<27;j++){
      cont=0;
      dfs(num[i][j]);
      skere=max(cont,skere);
    }
  }
  cout<<skere<<endl;


  return 0;
}
