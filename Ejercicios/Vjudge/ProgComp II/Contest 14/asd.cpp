#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second

int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,r; cin>>n>>m>>r;
    
    bool visit[n][m];
    rep(i,n){
        string line; cin>>line;
        rep(j,m) line[j]=='.'? visit[i][j]=0:visit[i][j]=1;
    }
    map<ii,int> rocks;
    rep(i,r){
        int a,b,t; cin>>a>>b>>t; a--,b--;
        rocks[{a,b}]=t;
    }
    queue<ii> q;
    int dist[n][m];
    rep(i,n) rep(j,m) dist[i][j]=-1;
    dist[0][0]=0;
    q.push({0,0});
    while(!q.empty()){
        ii u=q.front(); q.pop();
        rep(i,4){
            int a=u.ff+dr[i];
            int b=u.ss+dc[i];
            if(0<= a && a<n && 0<=b && b<m){
                if(dist[a][b]==-1 && !visit[a][b]){
                    if(rocks.count({a,b}) && rocks[{a,b}]<=dist[u.ff][u.ss]+1){
                        cout<<"no se puede visitar a "<<a<<" "<<b<<"\n";
                        continue;
                    }
                    cout<<a<<" "<<b<<" es visitado en el tiempo "<<dist[u.ff][u.ss]+1<<"\n";
                    dist[a][b]=dist[u.ff][u.ss]+1;
                    q.push({a,b});
                }
            }
        }
    }
    if(dist[n-1][m-1]==-1) cout<<"imposible\n";
    else cout<<dist[n-1][m-1]<<"\n";


    return 0;
}