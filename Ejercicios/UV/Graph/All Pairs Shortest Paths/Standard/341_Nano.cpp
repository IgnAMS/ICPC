#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector<vii> AdjList;
#define INF 100000000


int main(){
  int n;
  int test=0;
  while(cin>>n){
    if(n==0) break;
    test++;
    AdjList.assign(n,vii());
    int conect, a,b;
    for(int i=0;i<n;i++){
      cin>>conect;
      for(int j=0;j<conect;j++){
        cin>>a>>b;
        a--;
        AdjList[i].push_back(ii(a,b));
      }
    }
    int inicio,fin;
    cin>>inicio>>fin;
    inicio--;
    fin--;
    vi dist(n, INF);
    dist[inicio] = 0;
    priority_queue< ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, inicio));
    vector<int> asd(n,int());

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
          asd[v.first]= u;
          dist[v.first] = dist[u] + v.second;
          pq.push(ii(dist[v.first], v.first));
        }
      }
    }
    vector<int> ans;
    ans.push_back(fin+1);
    int ind=fin;
    while(asd[ind]!=inicio){
      //cout<<asd[ind]+1<<" ;
      ans.push_back(asd[ind]+1);
      ind=asd[ind];
    }
    ans.push_back(inicio+1);

    printf("Case %d: Path = ",test);
    for(int i=ans.size()-1;i>=0;i--){
      cout<<ans[i];
      if(i>=1) cout<<" ";
    }

    printf("; %d second delay\n",dist[fin]);

  }

  return 0;
}
