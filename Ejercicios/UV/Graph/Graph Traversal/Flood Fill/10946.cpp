#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
#define pb push_back
#define ff first
#define ss second 

vector<vector<bool>> V;
vector<vector<char>> mat;
int cont=0;
int n,m;
int dc[]={0,0,1,-1};
int dr[]={1,-1,0,0};

void dfs(int i, int j, char c){
    V[i][j]=1;
    cont++;
    rep(h,4){
        int di=i+dc[h], dj=j+dr[h];
        if(0<=di && di<n && 0<=dj && dj<m && !V[di][dj] && mat[di][dj]==c){
            dfs(di,dj,c);
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int cas=0;
    while(cin>>n>>m && (n!=0 && m!=0) && cout<<"Problem "<<++cas<<":\n"){
        vector<pair<int,char>> ans;
        mat.assign(n,vector<char>(m,'a'));
        V.assign(n,vector<bool>(m,0));
        rep(i,n) rep(j,m) cin>>mat[i][j];
        rep(i,n) rep(j,m) if(!V[i][j] && mat[i][j]!='.') 
            { cont=0; dfs(i,j,mat[i][j]); ans.pb({cont,mat[i][j]}); }
        sort(ans.begin(),ans.end(),[&](const pair<int,char>& a, const pair<int,char>& b){
            if(a.ff==b.ff) return a.ss<b.ss;
            return a.ff>b.ff;
        });
        rep(i,ans.size()) cout<<ans[i].ss<<" "<<ans[i].ff<<"\n";
    }

}