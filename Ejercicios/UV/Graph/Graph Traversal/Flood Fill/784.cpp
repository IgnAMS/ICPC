#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second

vector<string> mat;
int dr[]={0,0,-1,1};
int dc[]={1,-1,0,0};
int n,m;

void dfs(int i, int j){
    mat[i][j]='#';
    rep(h,4){
        int di=i+dr[h], dj=j+dc[h];
        if(0<=di && di<n && 0<=dj && dj<mat[i].size() && mat[di][dj]==' '){
            dfs(di,dj);
        }
    }
}



int main(){ 
    ios::sync_with_stdio(0); cin.tie(0);
    string linea;
    getline(cin,linea);
    while(getline(cin,linea)){
        bool oc=0;
        rep(i,linea.length()) if(linea[i]!='_') oc=1; 
        if(oc) { mat.push_back(linea); continue; }
        n=mat.size(); m=mat[0].size();
        int x,y;
        rep(i,n) rep(j,mat[i].size()) if(mat[i][j]=='*') x=i, y=j;
        dfs(x,y);
        rep(i,n) cout<<mat[i]<<"\n";
        cout<<linea<<"\n";

        mat.clear();
    }


    return 0;
}