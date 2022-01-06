#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
string ans="ALLIZZWELL";
int dr[]={-1,-1,-1,0,1,1, 1, 0};
int dc[]={-1, 0, 1,1,1,0,-1,-1};
vector<vector<bool>> visited;
vector<vector<char>> mat;
int n,m;
bool backtracking(int i, int j, int ind, string s){
    //cout<<mat[i][j]<<endl;
    if(mat[i][j]!=ans[ind]) return false;
    s+=mat[i][j]; ind++;
    visited[i][j]=true;
    if(s==ans) return true;
    //cout<<i<<" "<<j<<" "<<ind<<" "<<s<<endl;
    rep(h,8){
        int posi=i+dr[h];
        int posj=j+dc[h];
        if(0<=posi && posi<n && 0<=posj && posj<m && !visited[posi][posj]){
            if(backtracking(posi,posj,ind,s)) return true;
        }
    }
    visited[i][j]=false;
    return false;
}

int main(){
    int t; cin>>t;
    while(t--){
        cin>>n>>m;
        mat.assign(n,vector<char>(m));
        visited.assign(n,vector<bool>(m,false));
        rep(i,n) rep(j,m) cin>>mat[i][j];
        rep(i,n) rep(j,m){
            if(backtracking(i,j,0,"")) {cout<<"YES"<<endl; goto stop;}
        }
        cout<<"NO"<<endl;
        stop: 
            continue;
    }


    return 0;
}