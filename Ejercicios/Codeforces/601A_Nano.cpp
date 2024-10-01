#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
vector<vector<bool> > AdjList;
vector<vector<bool> > Adj2;
#define INF 1e9


int main(){
  int n,m;
  cin>>n>>m;
  int h1,h2;
  AdjList.assign(n,vector<bool>(n,false));
  Adj2.assign(n,vector<bool>(n,false));

  for(int i=0;i<m;i++){
    cin>>h1>>h2;
    h1--;
    h2--;
    AdjList[h1][h2]=true;
    AdjList[h2][h1]=true;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(!AdjList[i][j])Adj2[i][j]=true;
    }
  }
  vector<int> dist(n, INF);
  dist[0] = 0;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int j = 0; j < n; j++) {
      if(AdjList[u][j]){
        int v=j;
        if (dist[v] == INF) {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }
  }
  cout<<dist[n-1]<<endl;

  vector<int> dist2(n,INF);
  dist2[0]=0;
  queue<int> q2;
  q2.push(0);

  while(!q2.empty()){
    int u=q2.front();
    q2.pop();

    for(int j=0;j<n;j++){
      if(Adj2[u][j]){
        int v=j;
        if(dist2[v]==INF){
          dist2[v]=dist2[u]+1;
          if(dist2[v]==dist[v]){
            if(dist2[v]<dist[v]){
              dist2[v]
            }
          }
          q2.push(v);
        }
      }
    }
  }

  cout<<dist2[n-1]<<endl;


  return 0;

}
