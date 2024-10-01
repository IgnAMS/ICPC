#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

vector<vii> AdjList;

int main() {

    int V, E;  //V es el numero de nodos y E aristas
    int in, u, v, casos, peso, fin;

    while(cin>>V>>E){
      if(V==0&&E==0){
        break;
      }

        bool Matrix[V][V];
        for(int a=0;a<V;a++){
          for(int b=0;b<V;b++){
            Matrix[a][b]=false;
          }
        }

        AdjList.assign(V, vii());

        for (int i = 0; i < E; i++) {
          cin >> u >> v >> peso;
          u--;
          v--;
          AdjList[u].push_back(ii(v, peso));
          Matrix[u][v]=true;
        }

        cin>>casos;
        while(casos--){
          cin>>in>>fin;
          in--;
          fin--;
          vi dist(V, INF);
          dist[in] = 0;
          priority_queue< ii, vector<ii>, greater<ii> > pq;
          pq.push(ii(0, in));

          while (!pq.empty()) {
            ii front = pq.top();
            pq.pop();

            int d = front.first;
            int u = front.second;

            if (d > dist[u]) {
                continue;
            }

            for (int j = 0; j < (int)AdjList[u].size(); j++) {
              ii v = AdjList[u][j];
              if (dist[u] + v.second < dist[v.first]) {
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
          cout<<endl;
    }


return 0;
}
