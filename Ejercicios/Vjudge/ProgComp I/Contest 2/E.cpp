#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;


int dr[] = {-1,1,0, 0};
int dc[] = { 0,0,1,-1};

vector<vector<char>> G;
vector<vector<bool>> V;
int n, m;
void dfs(int i, int j){
    V[i][j] = 1;
    for(int h=0;h<4;h++){
        int di = i+dr[h];
        int dj = j+dc[h];
        if(0<=di && di<n && 0<=dj && dj<m && !V[di][dj] && G[di][dj]=='-'){
            dfs(di,dj);
        }
    }
}

int main(){ 
    int cas=0;
    while(cin>>n>>m && ++cas){
        V.assign(n,vector<bool>(m,0));
        G.assign(n,vector<char>(m));
        rep(i,n) rep(j,m) cin>>G[i][j];
        int ans=0;
        rep(i,n) rep(j,m) if(G[i][j]=='-' && !V[i][j]) { ans++; dfs(i,j); }
        cout<<"Case "<<cas<<": "<<ans<<"\n";
    }
    


    return 0;
}