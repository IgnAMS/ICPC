#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define INF 1000000000

int main(){
  int n;
  vector<vector<deque<int> > > ans;
  while(cin>>n){
    //if(n==-1) break;
    map<int,int> mapa;
    int cont=0;
    vector<deque<int> > aux2;
    vector<vii> AdjList(n);
    int asd;
    char c;
    map<int,int> mapa2;
    for(int i=0;i<n;i++){
      cin>>asd;
      if(!mapa.count(asd)){

        mapa2.insert(ii(cont,asd));
        mapa.insert(ii(asd,cont));
        cont++;
      }
      asd=mapa[asd];

      cin>>c;
      string linea;
      getline(cin,linea);
      //cout<<linea<<endl;
      vector<int> conex;
      int a=0;
      for(int j=0;j<linea.length();j++){
        if(linea[j]==','){
          //printf("el nodo %d puede ir al nodo %d\n",i,a-1);
          if(!mapa.count(a)){
            //printf("%d va con %d\n",a,cont);
            mapa.insert(ii(a,cont));
            mapa2.insert(ii(cont,a));
            cont++;
          }
          AdjList[asd].push_back(ii(mapa[a],1));

          a=0;
          continue;
        }
        //if(linea[j]!=',' && !(linea[j]<'9' || linea[j]>'0')) cout<<"aca falla chaval!!!!\n";
        //printf("digito a sumar es: %d\n",linea[j]-'0');
        a*=10;
        a+=linea[j]-'0';
      }
      if(a!=0){
        if(!mapa.count(a)){
          mapa2.insert(ii(cont,a));
          mapa.insert(ii(a,cont));
          cont++;
        }
        AdjList[asd].push_back(ii(mapa[a],1));
      }
      //printf("el nodo %d puede ir al nodo %d\n",i,a-1);
    }

    int m;
    cin>>m;
    int inicio,fin;
    for(int i=0;i<m;i++){
      vector<int> cam(n,-2);
      cin>>inicio>>fin;
      inicio=mapa[inicio];
      fin=mapa[fin];
      vector<int> dist(n,INF);
      dist[inicio] = 0;
      queue<int> q;
      q.push(inicio);

      while (!q.empty()) {
        //printf("el tamaño del queue es %d\n",q.size());
        int u = q.front(); //siendo u la ubicacion actual
        //printf("el nodo actual es %d y tiene por el momento costo %d\n",u,dist[u]);
        q.pop();

        for (int j = 0; j < (int)AdjList[u].size(); j++) {
          ii v = AdjList[u][j];
          if (dist[v.first] > dist[u]+v.second) {
            dist[v.first] = dist[u] + 1;
            //printf("el nodo a explorar es el %d\n",v.first);
            q.push(v.first);
            cam[v.first]=u;
            //printf("el nodo %d viene del nodo %d\n",v.first,u);
          }
        }
      }
      deque<int> aux;
      int ind=fin;
      //cout<<cam[fin]<<" "<<dist[fin]<<endl;
      if(dist[fin]==INF){
        aux.push_back(-1);
      }
      else{
        aux.push_front(mapa2[fin]);
        //printf("mapa2 de %d es %d\n",fin,mapa2[fin]);
        while(cam[ind]!=inicio){
          //  printf("cam[ind]= %d\n",cam[ind]);
          //cout<<"muero aca?\n";
          //printf("ind actual es: %d y su map2 es %d\n",cam[ind],mapa2[cam[ind]]);
          aux.push_front(mapa2[cam[ind]]);
          ind=cam[ind];
        }
        aux.push_front(mapa2[inicio]);
      }
      aux2.push_back(aux);
    }
    ans.push_back(aux2);
  }

  for(int i=0;i<ans.size();i++){
    cout<<"-----\n";
    for(int j=0;j<ans[i].size();j++){
      for(int h=0;h<ans[i][j].size();h++){
        if(ans[i][j][h]==-1) {
          cout<<"connection impossible";
          continue;
        }
        cout<<ans[i][j][h];
        if(h<ans[i][j].size()-1) cout<<" ";
      }
      cout<<endl;
    }
  }


  return 0;
}
