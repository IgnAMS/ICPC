#include<bits/stdc++.h>
using namespace std;


typedef vector<pair<int,int> > vii;
vector<vector<bool> > AdjList;
vector<bool> visit;
vector<vector<int> > realv;

vector<int> aux;

void dfs(int a,int n){
  if(visit[a]) return;
  visit[a]=true;
  aux.push_back(a);
  for(int i=0;i<n;i++){
    if(i==a) continue;
    if(AdjList[a][i]) dfs(i,n);
  }

}
int cont=0;

void rdfs(int a,int n){
  if(visit[a]) return;
  visit[a]=true;
  aux.push_back(a);
  cont++;
  for(int i=0;i<realv.size();i++){
    rdfs(realv[a][i],n);
  }

}


int main(){
  int n;
  cin>>n;
  AdjList.assign(n,vector<bool>(n,false));
  visit.assign(n,false);
  int h;

  for(int i=0;i<n;i++){
    cin>>h;
    if(h==-1) continue;
    h--;
    AdjList[i][h]=true;
    AdjList[h][i]=true;
  }
  /*
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<AdjList[i][j]<<" ";
    }
    cout<<endl;
  }
  */
  realv.assign(n,vector<int>());
  for(int i=0;i<n;i++){
    visit.assign(n,false);
    aux.clear();
    dfs(i,n);
    for(int j=0;j<n;j++) if(!visit[j]) realv[i].push_back(j);
    for(int j=0;j<aux.size();j++) cout<<aux[j]<<" ";
    cout<<endl;
  }

  int comp=0;
  visit.assign(n,false);
  for(int i=0;i<n;i++){
    cout<<"entre\n";
    rdfs(i,n);
    if(cont>0) comp++;
  }
  cout<<"meeh "<<comp<<endl;




  return 0;
}
