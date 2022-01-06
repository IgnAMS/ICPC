#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1000000000

vector<vii> AdjList;

int main() {

    int V, E;  //V es el numero de nodos y E aristas
    int inicio, u, v, casos, peso, fin;
    bool primer=true;
    while(cin>>V>>E){
      if(V==0&&E==0){
        break;
      }

      else{
        if(!primer){
          cout<<endl;
        }
        else primer=false;
        vector<vector<bool> > mat(V,vector<bool> (V,false));
        AdjList.assign(V, vii()); //al vector de pares se le asigna un tamaño nodo y

        for (int i = 0; i < E; i++) {
          cin >> u >> v >> peso;
          u--;
          v--;
          AdjList[u].push_back(ii(v, peso));
          mat[u][v]=true;

          if(mat[u][v] && mat[v][u]){
            //cout<<"entre aca chaval\n";
            for(int j=0;j<AdjList[u].size();j++){
              if(AdjList[u][j].first==v){
                AdjList[u][j].second=0;
              }
            }
            for(int j=0;j<AdjList[v].size();j++){
              if(AdjList[v][j].first==u){
                AdjList[v][j].second=0;
              }
            }
          }
        }


        cin>>casos;
        while(casos--){

          cin>>inicio>>fin;
          inicio--;
          fin--;
          vi dist(V, INF);
          dist[inicio] = 0;
          priority_queue< ii, vector<ii>, greater<ii> > pq;
          pq.push(ii(0, inicio));

          while (!pq.empty()) {
            ii front = pq.top();
            pq.pop();

            int d = front.first;
            int u = front.second;

            if (d > dist[u]) continue;

            for (int j = 0; j < (int)AdjList[u].size(); j++) {
              ii v = AdjList[u][j];
              if (dist[u] + v.second < dist[v.first]) {
                  // v.first es nodo, v.second es distancia
                  dist[v.first] = dist[u] + v.second;
                  pq.push(ii(dist[v.first], v.first));
              }
            }
          }
          if(dist[fin]==INF)
            printf("Nao e possivel entregar a carta\n");
          else{
            printf("%d\n",dist[fin]);
          }
        }

      }
    }


return 0;
}
