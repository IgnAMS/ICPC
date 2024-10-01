#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

int V, E, a, b, s, d, n;
// V son los vertices o nodos, E la

vector<vii> AdjList;

int main() {
  int E;
  int t=0;
  int test;
  cin>>test;
  while (test--) {
    if(E==0) break;

    AdjList.assign(33, vii());
    map<int,int> nodos;
    int cont=0;
    int p1,p2;

    for (int i = 0; i < E; i++) { //se ingresan los nodos a y b
      cin >> a >> b;
      if(!nodos.count(a)){
        nodos.insert(ii (a,cont));
        cont++;
      }
      if(!nodos.count(b)){
        nodos.insert(ii (b,cont));
        cont++;
      }

      AdjList[nodos[a]].push_back(ii(nodos[b], 0));
      AdjList[nodos[b]].push_back(ii(nodos[a], 0));
    }

    int in, salt;
    while(cin>>in>>salt){
      if(in==0 && salt==0) break;

      vi dist(33, INF);
      dist[nodos[in]] = 0;
      queue<int> q;
      q.push(nodos[in]);

      int cont2=0;

      for(int i=0;i<33;i++){
        while (!q.empty()) {
          int u = q.front(); //siendo u la ubicacion actual
          q.pop();
          for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];

            if (dist[v.first] == INF) {
              dist[v.first] = dist[u] + 1;
              q.push(v.first);
            }
          }
        }
        if(dist[i]<=salt) cont2++;
        //cout << dist[i] << endl;
      }
      //cout<<"nodos no visitados "<<cont-cont2<<endl;
      t++;
      printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",t, cont-cont2, in, salt);
    }




  }



return 0;
}

