#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define INF 1000000000


int main(){
  int t;
  cin>>t;
  vector<int> ans;
  int outp=0;
  while(t--){
    outp++;
    //cout<<"\n\nESTE ES EL INPUT NUMERO "<<outp<<endl<<endl;
    int n,e,tim,m;
    cin>>n>>e>>tim>>m;

    vector<vii> AdjList(n);
    int nod1,nod2,h;
    map<int,int> mapa;
    int cont=0;
    int paso=0;

    for(int i=0;i<m;i++){
      cin>>nod1>>nod2>>h;
      if(!mapa.count(nod1)){
        mapa.insert(ii(nod1,cont));
        //printf("se emparento el nodo %d con el numero: %d\n",nod1,cont);
        cont++;
      }
      if(!mapa.count(nod2)){
        mapa.insert(ii(nod2,cont));
        //printf("se emparento el nodo %d con el numero: %d\n",nod2,cont);
        cont++;
      }
      //cout<<"xddd\n";
      AdjList[mapa[nod1]].push_back(ii(mapa[nod2],h));
      //cout<<"pase esta linea chaval\n";
    }

    /*cout<<"\npares: "<<endl;
    for(map<int,int>::iterator it=mapa.begin();it!=mapa.end();++it) cout<<it->first<<" "<<it->second<<endl;
    cout<<endl;
    */
    vector<bool> pasaron(cont+1,false);
    for(map<int,int>::iterator it=mapa.begin(); it!=mapa.end();++it){
      if(pasaron[it->second]) continue;
      pasaron[it->second]=true;
      //cout<<"it second vale: "<<it->second<<endl;
      vector<int> dist(n,INF);
      dist[it->second]=0;
      priority_queue<ii, vector<ii>, greater<ii> > pq;
      pq.push(ii(0,it->second));

      while(!pq.empty()){
        int d= pq.top().first;
        int u= pq.top().second;
        pq.pop();

        //if(dist[u] < d) continue;

        for(int j=0;j<AdjList[u].size();j++){
          ii v=AdjList[u][j];
          if(dist[u]+v.second < dist[v.first]){
            dist[v.first]=dist[u]+v.second;
            pq.push(ii(dist[v.first], v.first));
          }
        }
      }
      if(dist[mapa[e]]<=tim) {
        paso++;
        //cout<<"paso el raton "<<it->second<<endl;
      }
    }
    ans.push_back(paso);
  }
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<endl;
    if(i<ans.size()-1) cout<<endl;
  }

  return 0;
}
