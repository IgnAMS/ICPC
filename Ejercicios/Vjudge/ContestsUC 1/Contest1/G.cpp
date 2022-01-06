#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,char> iic;

vector<vector<int> > mat(4,vector<int>(4,int()));
int dc[]={ 0,1,0,-1};
int dr[]={-1,0,1, 0};
//0,-1 = N
//0, 1 = S
//1, 0 = E
//-1,0 = O
bool yeah=true;
bool primer=true;
bool second=true;
char previ;


map<ii,char> mapa;
void initmap(){
  mapa.insert(iic(ii( 0,-1),'N'));
  mapa.insert(iic(ii( 0, 1),'S'));
  mapa.insert(iic(ii( 1, 0),'E'));
  mapa.insert(iic(ii(-1, 0),'O'));
}
vector<vector<bool> > visit(4,vector<bool>(4,false));
int cont;
vector<int> contperrow;
vector<int> contpercol;
void init(){
  contperrow.assign(4,0);
  contpercol.assign(4,0);
  primer=true;
  second=true;
  yeah=true;
  cont=0;
}

void dfs(int a, int b, int c){
  if(visit[a][b]) return;
  visit[a][b]=true;
  cont++;
  contperrow[a]++;
  contpercol[b]++;
  for(int i=0;i<4;i++){
    int di=a+dr[i];
    int dj=b+dc[i];
    if(0<=di && di<4 && 0<=dj && dj<4){
      if(mat[di][dj]!=c) continue;
      if(visit[di][dj]) continue;
      char act=mapa[ii(dc[i],dr[i])];

      printf("la posicion actual es di: %d,  dj %d y el caracter es %d\n",di,dj,mat[di][dj]);
      if(!primer){
        if(!second){
          if(previ=='S' && (act=='O'|| act=='E')){
            printf("prev S: di: %d y dj: %d\n",di-1,dj);
            if(mat[di-1][dj]!=c) yeah=false;
          }
          else if(previ=='N' && (act=='E'|| act=='O')){
            printf("prev N: di: %d y dj: %d\n",di+1,dj);
            if(mat[di+1][dj]!=c) yeah=false;
          }
          else if(previ=='E' && (act=='N'|| act=='S')){
            printf("prev E: di: %d y dj: %d\n",di,dj-1);
            if(mat[di][dj-1]!=c) yeah=false;
          }
          else if(previ=='O' && (act=='N'|| act=='S')){
            printf("prev S: di: %d y dj: %d\n",di,dj+1);
            if(mat[di][dj+1]!=c) yeah=false;
          }
        }
        second=false;
        previ=act;
      }
      primer=false;
      dfs(di,dj,c);

    }
  }
}


int main(){
  initmap();
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      int h;
      cin>>h;
      mat[i][j]=h;
    }
  }
  bool asd=false;
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      init();
      printf("el caracter c es: %d\n",mat[i][j]);
      dfs(i,j,mat[i][j]);
      sort(contpercol.begin(),contpercol.end(),greater<int>());
      sort(contperrow.begin(),contperrow.end(),greater<int>());
      bool help=true;
      for(int k=1;k<4;k++){
        if(contperrow[k]<contperrow[0] && contperrow[k]!=0) help=false;
        if(contpercol[k]<contpercol[0] && contpercol[k]!=0) help=false;
      }
      if(yeah && cont>1 && help) asd=true;
    }
  }
  if(asd) cout<<"YES\n";
  else cout<<"NO\n";



  return 0;
}
