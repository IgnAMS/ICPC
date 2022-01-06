#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int n,m; 
char mat[101][101];
bool V[101][101];
string linea = "ALLIZZWELL";
int largo = linea.length();

int dr[]={-1,-1,-1,0,1,1,1,0};
int dc[]={-1,0,1,1,1,0,-1,-1};

bool backtracking(int x, int r, int c){
    if(x==largo-1){
        bool flag=0;
        rep(h,8){
            int di = r+dr[h], dj = c+dc[h];
            if(0<=di && di<n && 0<=dj && dj<m && !V[di][dj] && mat[di][dj]==linea[x]){
                //encontré una, devuelvo 1
                return 1;
            }
        }
        return 0;
    }
    rep(h,8){
        int di = r+dr[h], dj = c+dc[h];
        if(0<=di && di<n && 0<=dj && dj<m && !V[di][dj] && mat[di][dj]==linea[x]){
            V[di][dj]=1;
            if(backtracking(x+1, di, dj)){
                return 1;
            } 
            V[di][dj]=0;
        }
    }
    return 0;

}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>n>>m;
        rep(i,n) rep(j,m) cin>>mat[i][j];
        memset(V, 0, sizeof V);
        bool ans=0;
        rep(i,n){
            rep(j,m){
                V[i][j]=1;
                if(mat[i][j] == linea[0] && backtracking(1,i,j)) { 
                    ans=1;
                    break;
                }
                V[i][j]=0;
            }
            if(ans) break;
        }
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }


    return 0;
}
