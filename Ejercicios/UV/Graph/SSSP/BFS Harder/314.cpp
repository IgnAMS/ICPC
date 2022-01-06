#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
#define ff first
#define ss second

int dr[]={0,1,0,-1}; // 0->E, 1->S, 2->W, 3->N
int dc[]={1,0,-1,0};
vector<vector<int>> mat;

bool check(ii x, int c){
    if(c==0) return !mat[x.ff-1][x.ss] && ! mat[x.ff][x.ss];
    if(c==1) return !mat[x.ff][x.ss] && !mat[x.ff][x.ss-1];
    if(c==2) return !mat[x.ff-1][x.ss-1] && !mat[x.ff][x.ss-1];
    return !mat[x.ff-1][x.ss] && ! mat[x.ff-1][x.ss-1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    while(cin>>n>>m && (n!=0 && m!=0)){
        mat.assign(n,vector<int>(m)); rep(i,n) rep(j,m) cin>>mat[i][j];
        int b1,b2,e1,e2;
        string com;
        cin>>b1>>b2>>e1>>e2>>com; //b1,b1-1
        int D[n][m][4];
        memset(D,-1,sizeof(D));
        queue<iii> q;
        int dir;
        if(com[0]=='e') dir=0;
        if(com[0]=='s') dir=1;
        if(com[0]=='w') dir=2;
        if(com[0]=='n') dir=3;
        q.push({{b1,b2},dir});
        D[b1][b2][dir]=0;
        int ans=-1;
        if(b1==e1 && b2==e2) ans=0;
        while(!q.empty()){
            ii u; int d;
            tie(u,d) = q.front(); q.pop();
            int dist=D[u.ff][u.ss][d];
            //cout<<u.ff<<" "<<u.ss<<" "<<d<<" "<<dist<<"\n";
            if(u.ff==e1 && u.ss==e2) { ans=dist; break; }
            if(D[u.ff][u.ss][(d+1)%4]==-1) { 
                D[u.ff][u.ss][(d+1)%4]=dist+1;
                q.push({u,(d+1)%4});
            }
            if(D[u.ff][u.ss][(d+3)%4]==-1){
                D[u.ff][u.ss][(d+3)%4]=dist+1;
                q.push({u,(d+3)%4});
            }
            for(int i=1;i<=3;i++){
                int x=u.ff+dr[d]*i, y=u.ss+dc[d]*i;
                //cout<<x<<" "<<y<<"\n";
                if(1<=x && x<n && 1<=y && y<m && D[x][y][d]==-1 && check({x,y},d)){
                    D[x][y][d]=dist+1;
                    q.push({{x,y},d});
                }
                else break;
            }
            if(ans!=-1) break;
        }
        cout<<ans<<"\n";
    }



    return 0;
}