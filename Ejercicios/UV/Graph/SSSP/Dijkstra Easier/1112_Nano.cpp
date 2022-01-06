#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1000000000

vector<vii> AdjList;

int main() {

    int V, E;  //V es el numero de nodos y E aristas
    int temp;
    int fin;
    fin--;
    int t;
    cin>>t;
    int u,v,peso;
    bool primer=true;
    vector<int> ans;
    while(t--){
        if(!primer) cout<<endl;
        primer=false;
        cin>>V>>fin>>temp>>E;

        AdjList.assign(V, vii()); //al vector de pares se le asigna un tamaño nodo y


        vector<int> ind;
        for (int i = 0; i < E; i++) {
          cin >> u >> v >> peso;
          u--;
          v--;
          AdjList[u].push_back(ii(v, peso));
        }
        int cont=0;
        for(int i=0;i<V;i++){

          int inicio=i;
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
          if(dist[fin]<temp) {
            cont++;
            ind.push_back(i);
            cout<<i<<" ";
          }
        }
        cout<<endl;
        ans.push_back(cont);


    }
    for(int i=0;i<ans.size();i++){
      if(i>0) cout<<endl;
      cout<<ans[i]<<endl;
    }



  return 0;
}
