#include<bits/stdc++.h>
using namespace std;

int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};
#define INF INT_MAX
typedef pair<int,int> ii;

int main(){
  int r,c;
  while(cin>>r>>c){
    if(r==0 && c==0) break;

    int maxi=max(r,c);
    vector<vector<int> > dist(maxi,vector<int>(maxi,INF));
    int R;
    cin>>R;
    int col,row,n;
    for(int i=0;i<R;i++){
      cin>>row>>n;
      for(int j=0;j<n;j++){
        cin>>col;
        dist[row][col]=true;
      }
    }

    //cout<<"llegue aca"<<endl;
    int posi,posj,desti,destj;
    cin>>posi>>posj>>desti>>destj;
    dist[posi][posj] = 0;
    queue<ii> q;
    q.push(ii(posi,posj));


    int cont=0;
    while (!q.empty() ) {
      ii u = q.front(); //siendo u la ubicacion actual
      q.pop();
      //cout<<"aaaa\n";

      for (int j = 0; j < 4 ; j++) {

        posi=u.first+dr[j];
        posj=u.second+dc[j];
        //cout<<posi<<" "<<posj<<" "<<cont<<" meeeh\n";
        if (0<=posi && posi<r && 0<=posj && posj<c) {
          if(dist[posi][posj] == INF){
            dist[posi][posj] = dist[u.first][u.second] + 1;
            q.push(ii(posi,posj));
          }

        }
      }
    }
    cout<<dist[desti][destj]<<endl;


  }

  return 0;
}
