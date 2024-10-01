#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

int V, E, Q, a, b, s, d, n;
// V son los vertices o nodos, E la

vector<vii> AdjList;

int main() {
  cout<<"SHIPPING ROUTES OUTPUT\n\n";
  int E;
  int t=0;
  int test;
  cin>>test;

  while (test--) {
    cin>>V>>E>>Q;
    t++;
    cout<<"DATA SET"<<"\t"<<t<<endl<<endl;

    AdjList.assign(V, vii());
    map<string,int> nodos;
    string nod1,nod2;;

    for(int i=0;i<V;i++){
      cin>>nod1;
      nodos.insert(pair<string,int> (nod1,i));
    }

    for (int i = 0; i < E; i++) { //se ingresan los nodos a y b
      cin >> nod1 >> nod2;
      AdjList[nodos[nod1]].push_back(ii(nodos[nod2], 0));
      AdjList[nodos[nod2]].push_back(ii(nodos[nod1], 0));
    }

    int cost;

    for(int i=0;i<Q;i++){
      cin>>cost>>nod1>>nod2;
      vi dist(V, INF);
      dist[nodos[nod1]] = 0;
      queue<int> q;
      q.push(nodos[nod1]);

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
      if(dist[nodos[nod2]]== INF){
        cout<<"NO SHIPMENT POSSIBLE\n";
      }
      else{
        cout <<"$"<< dist[nodos[nod2]]*cost*100 << endl;
      }

    }
    cout<<endl;

  }

  cout<<"END OF OUTPUT\n";


return 0;
}

