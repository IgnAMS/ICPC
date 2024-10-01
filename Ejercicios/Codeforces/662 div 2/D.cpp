#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second

int DP[2002][2002];
char mat[2002][2002];
int n,m;

int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};


bool check(int i, int j, char c){
    return (0<=i && i<n && 0<=j && j<m && mat[i][j]==c);
}


int main(){
    cin>>n>>m;
    memset(DP,-1,sizeof(DP));
    rep(i,n){
        DP[i][0]=1;
        DP[i][m-1]=1;
    }
    rep(i,m){
        DP[0][i]=1;
        DP[n-1][i]=1;
    }
    rep(i,n) rep(j,m) cin>>mat[i][j];
    rep(i,n){
        rep(j,m){
            bool yes=true;
            rep(k,4){
                int posi=i+dr[k];
                int posj=j+dc[k];
                if(!check(posi,posj,mat[i][j])) {yes=false; break;}
            }
            if(!yes) DP[i][j]=1;

        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            queue<ii> q;
            q.push({i,j});
            int extension=1e5;
            while(!q.empty() && extension){
                ii u=q.front(); q.pop();
                if(DP[u.ff][u.ss]!=-1 && mat[u.ff][u.ss]==mat[i][j]){
                    extension=min(extension,DP[u.ff][u.ss]);
                    
                }
            }
        }
    }



    return 0;
}