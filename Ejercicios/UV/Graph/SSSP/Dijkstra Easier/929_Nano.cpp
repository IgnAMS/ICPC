#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<ii,int> iii;
typedef pair<int,ii> inv;
typedef vector<iii> viii;

int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};

#define INF 1000000000

vector<vector<viii> > AdjList;
int main() {

    int t;
    int n,m;
    cin>>t;

    while(t--){
        cin>>n>>m;
        int Mat[n][m];

        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            cin>>Mat[i][j];
          }
        }
        AdjList.assign(n, vector<viii>(m,viii()));
        int posi,posj;
        for (int i = 0; i < n; i++) {
          for(int j=0;j<m;j++){
            for(int h=0;h<4;h++){
              posi=i+dr[h];
              posj=j+dc[h];
              if(0<=posi && posi<n && 0<=posj && posj<m){

                AdjList[i][j].push_back(iii(ii(posi,posj),Mat[posi][posj]));
                //cout<<"estoy vivo xd "<<posi<<" "<<posj<<endl;
              }
            }
          }
        }

          vector<vector<int> > dist(n,vector<int>(m,INF));

          dist[0][0] = Mat[0][0];

          priority_queue< inv, vector<inv>, greater<inv> > pq;

          pq.push(inv(0, ii(0,0)));

          while (!pq.empty()) {
            inv front = pq.top();
            pq.pop();

            int d = front.first;
            ii u = front.second;
            if (d > dist[u.first][u.second]) {
                continue;
            }

            for (int j = 0; j < (int)AdjList[u.first][u.second].size(); j++) {
              iii v = AdjList[u.first][u.second][j];
              if (dist[u.first][u.second] + v.second < dist[v.first.first][v.first.second]) {
                  dist[v.first.first][v.first.second] = dist[u.first][u.second] + v.second;
                  pq.push(inv(dist[v.first.first][v.first.second], v.first));
              }
            }
          }

          printf("%d\n",dist[n-1][m-1]);



      }



  return 0;
}
