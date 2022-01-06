#include<bits/stdc++.h>
using namespace std;
typedef pair<string,int> si;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define INF 1000000000

int main(){
  int t;
  cin>>t;
  vector<vector<int> > ans;
  while(t--){
    int m,n,p;
    vector<int> aux;
    cin>>m>>n>>p;
    map<string,int> mapa;
    string linea;

    for(int i=0;i<m;i++){
      cin>>linea;
      mapa.insert(si(linea,i));
    }

    vector<vii> AdjList(m);
    string linea2;
    int nod1,nod2;

    for(int i=0;i<n;i++){
      cin>>linea>>linea2;
      nod1=mapa[linea];
      nod2=mapa[linea2];
      AdjList[nod1].push_back(ii(nod2,1));
      AdjList[nod2].push_back(ii(nod1,1));
    }

    int mult;
    for(int i=0;i<p;i++){
      cin>>mult>>linea>>linea2;
      int ini=mapa[linea];
      int fin=mapa[linea2];

      vector<int> dist(m,INF);
      dist[ini]=0;
      queue<int> q;
      q.push(ini);

      while(!q.empty()){
        int u=q.front();
        q.pop();
        //printf("verifiamos el nodo %d\n",u);
        for(int j=0;j<(int)AdjList[u].size();j++){
          ii v = AdjList[u][j];
          if(dist[v.first] > dist[u]+v.second){
            dist[v.first]= dist[u]+v.second;
            q.push(v.first);
          }
        }
      }
      if(dist[fin]==INF){
        aux.push_back(-1);
      }
      else{
        aux.push_back(mult*dist[fin]*100);
      }
    }
    ans.push_back(aux);
  }
  //cout<<"sali del while?\n";
  cout<<"SHIPPING ROUTES OUTPUT\n";
  for(int i=0;i<ans.size();i++){
    cout<<endl<<"DATA SET  "<<i+1<<"\n\n";
    for(int j=0;j<ans[i].size();j++){
      if(ans[i][j]==-1){
        cout<<"NO SHIPMENT POSSIBLE";
      }
      else{
        cout<<"$"<<ans[i][j];
      }
      cout<<endl;
    }
  }
  cout<<endl<<"END OF OUTPUT\n";

  return 0;
}
