#include<bits/stdc++.h>
using namespace std;

int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
vector<vector<char> > mat;
vector<vector<bool> > visited;
bool entro;
void dfs(int a,int b,int c, int d){
  if(visited[a][b]) return;
  //printf("entre a: %d, b: %d\n",a,b);
  visited[a][b]=true;
  entro=true;
  for(int i=0;i<4;i++){
    int dy= a+dr[i];
    int dx= b+dc[i];
    if(0<=dy && dy<c && 0<=dx && dx<d){
      if(mat[dy][dx]=='-') dfs(dy,dx,c,d);
    }
  }
}

int main(){
  int n,m;
  vector<int> ans;
  while(cin>>n>>m){
    mat.assign(n,vector<char>(m));
    visited.assign(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin>>mat[i][j];
        if(mat[i][j]!='-') visited[i][j]=true;
      }
    }
    int cont=0;
    //cout<<"eehhh\n";
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        entro=false;
        dfs(i,j,n,m);
        if(entro) cont++;
      }
    }
    //cout<<"aaahhh\n";
    ans.push_back(cont);
  }
  for(int i=0;i<ans.size();i++){
    printf("Case %d: %d\n",i+1,ans[i]);
  }

  return 0;
}
