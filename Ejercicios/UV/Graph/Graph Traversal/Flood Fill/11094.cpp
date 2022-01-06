#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int dr[]={0,0,-1,1};
int dc[]={1,-1,0,0};

vector<vector<bool>> V;
int n,m;
int cont=0;
char l;
vector<vector<char>> mat;
void dfs(int i, int j){
    V[i][j]=1;
    cont++;
    rep(h,4){
        int di=i+dc[h], dj=j+dr[h];
        if(0<=di && di<n && !V[di][(dj+m)%m] && mat[di][(dj+m)%m]==l){
            dfs(di,(dj+m)%m);
        }
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(cin>>n>>m){
        V.assign(n,vector<bool>(m,0));
        mat.assign(n,vector<char>(m,'a'));
        rep(i,n) rep(j,m) cin>>mat[i][j];
        int a,b; cin>>a>>b;
        l=mat[a][b];
        dfs(a,b);
        int maxi=0;
        rep(i,n) rep(j,m) 
            if(!V[i][j] && mat[i][j]==l) { cont=0; dfs(i,j); maxi=max(maxi,cont); }
        cout<<maxi<<"\n";

    }



    return 0;
}