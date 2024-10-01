#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int dr[]={0,1,0,-1};
int dc[]={1,0,-1,0};
int n, m;
vector<vector<int>> mat;
vector<vector<bool>> cant;
vector<vector<vector<pair<int,int>>>> T;
/*
bool check(int i, int j){
    bool aux=true;
    rep(k,4){
        if(0<=i+dr[k] && i+dr[k]<n && 0<=j+dc[k] && j+dc[k]<m) 
            if(mat[i][j] == mat[i+dr[k]][j+dc[k]])
                aux= check(i+dr[k],j+dc[k]);
    }
    if(aux) 
}
*/

void camb(int i, int j){
    mat[i][j]++;
    rep(k,4){
        if(0<=i+dr[k] && i+dr[k]<n && 0<=j+dc[k] && j+dc[k]<m){
            if(mat[i][j] == mat[i+dr[k]][j+dc[k]]-1){
                cant[i+dr[k]][j+dc[k]]=1;
            }
        }
    }
    for(auto &u: T[i][j]){
        camb(u.first,u.second);
    }
}


int main(){
    ios::sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        cin>>n>>m;
        mat.assign(n,vector<int>(m));
        cant.assign(n,vector<bool>(m));
        T.assign(n,vector<vector<pair<int,int>>> (m,vector<pair<int,int>>()) );
        rep(i,n) rep(j,m) { cin>>mat[i][j]; cant[i][j]=0; }
        rep(i,n) rep(j,m){
            bool change=0;
            rep(k,4){
                if(0<=i+dr[k] && i+dr[k]<n && 0<=j+dc[k] && j+dc[k]<m){
                    if(mat[i][j]+1==mat[i+dr[k]][j+dc[k]]) T[i][j].push_back({i+dr[k],j+dc[k]});
                }
            }
            if(change){ 
                mat[i][j]++;
            }
        }
        rep(i,n) rep(j,m){
            bool change=0;
            rep(k,4){
                if(0<=i+dr[k] && i+dr[k]<n && 0<=j+dc[k] && j+dc[k]<m){
                    if(mat[i][j] == mat[i+dr[k]][j+dc[k]] && !cant[i][j]){
                        cant[i+dr[k]][j+dc[k]]=1; change=1;
                    }
                    else if(mat[i][j]==mat[i+dr[k]][j+dc[k]]+1 && (dr[k]>=0 || dc[k]>=0) && cant[i][j]){
                        cant[i+dr[k]][j+dc[k]]=1;
                    }
                }
            }
            if(change){
                camb(i,j);
            }
        }
        rep(i,n){ rep(j,m) cout<<mat[i][j]<<" "; cout<<"\n";}
        
        
    }
        


    return 0;
}