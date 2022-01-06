#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
  int e;
  cin>>e;
  vector<vii> AdjList(e,vii());
  int h;

  for(int i=0;i<e;i++){
    cin>>h;
    int aux;

    for(int j=0;j<h;j++){
      cin>>aux;
      AdjList[i].push_back(ii(aux,0));
    }
  }
  int t;
  cin>>t;
  while(t--){
    int s;
    cin>>s;
    vector<int> dist(e,INF);
    queue<int> q;
    queue<int> q2;
    dist[s]=0;
    q.push(s);
    int cont=0;
    int maxi=INT_MIN;
    int FirstB;
    bool state=true;
    int ind=0;

    while(!q.empty() || !q2.empty()){
      cont=0;
      ind++;
      //  cout<<"el estado es "<<state<<endl;
      if(state){
        while(!q.empty()){
          int u=q.front();
          q.pop();

          for(int i=0;i<(int)AdjList[u].size();i++){
            ii v=AdjList[u][i];
            if(dist[v.first]==INF){
              dist[v.first]=dist[u]+1;
              q2.push(v.first);
              cont++;
            }
          }
        }
      }

      else{
        while(!q2.empty()){
          int u=q2.front();
          q2.pop();

          for(int i=0;i<(int)AdjList[u].size();i++){
            ii v=AdjList[u][i];
            if(dist[v.first]==INF){
              dist[v.first]=dist[u]+1;
              q.push(v.first);
              cont++;
            }
          }
        }
      }
      state=!state;
      if(cont>maxi){
        maxi=cont;
        FirstB=ind;
      }
    }
    if(maxi==0){
      cout<<0<<endl;
    }
    else{
      cout<<maxi<<" "<<FirstB<<endl;
    }
  }




  return 0;
}
