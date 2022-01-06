#include<bits/stdc++.h>
using namespace std;
int dc[]={-1, 0, 1,1,1,0,-1,-1}; //j
int dr[]={-1,-1,-1,0,1,1, 1, 0};


int main(){
  int n,m;
  int t=0;
  vector<vector<vector<char> > > ans;
  while(cin>>n>>m){
    if(n==0 && m==0) break;

    vector<vector<char> > mat(n,vector<char>(m,char()));
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        cin>>mat[i][j];

    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        int cont=0;
        if(mat[i][j]=='*') continue;
        for(int k=0;k<8;k++){
          int x=i+dr[k];
          int y=j+dc[k];
          if(0<=x && x<n && 0<=y && y<m){
            if(mat[x][y]=='*') cont++;
          }
        }
        mat[i][j]=cont+'0';
      }
    }
    ans.push_back(mat);

  }
  for(int i=0;i<ans.size();i++){
    if(i>0) cout<<endl;
    printf("Field #%d:\n",i+1);
    for(int j=0;j<ans[i].size();j++){
      for(int k=0;k<ans[i][j].size();k++){
        cout<<ans[i][j][k];
      }
      cout<<endl;
    }
  }

  return 0;
}
