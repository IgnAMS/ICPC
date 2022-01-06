#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

vector<string> mat(10);
vector<vector<bool>> V;
int dr[]={0,0,1,-1};
int dc[]={1,-1,0,0};

int n=10,m=15;
int cont;
void dfs(int i, int j, char c){
    V[i][j]=1;
    cont++;
    rep(h,4){
        int di=i+dc[h], dj=j+dr[h];
        if(0<=di && di <n && 0<=dj && dj<m && !V[di][dj] && mat[di][dj]==c){
            dfs(di,dj,c);
        }
    }

}

void quitar(int i, int j, char c){
    mat[i][j]=' ';
    rep(h,4){
        int di=i+dc[h], dj=j+dr[h];
        if(0<=di && di<n && 0<=dj && dj<m && mat[di][dj]==c){
            quitar(di,dj,c);
        }
    }
}

void fix(){
    int d=0;
    rep(j,15){
        bool oc=1;
        int f=-1;
        for(int i=9; i>=0;i--){
            if(mat[i][j]==' ' && f==-1) f=i;
            if(mat[i][j]!=' ') {
                oc=0;
                char c=mat[i][j];
                mat[i][j]=' ';
                if(f!=-1){
                    mat[f][j-d]=c;
                    f--;
                }
                else mat[i][j-d]=c;
            }
        }
        if(oc) d++;
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    rep(cas,t){
        cout<<"Game "<<cas+1<<":\n\n"; 
        rep(i,10) cin>>mat[i]; 
        ll ans=0;
        int mov=0;
        while(1){
            V.assign(10,vector<bool>(15,0));
            int maxi=0;
            int x,y;
            int tot=0;
            rep(j,15) for(int i=9;i>=0;i--) if(!V[i][j] && mat[i][j]!=' '){
                cont=0; dfs(i,j,mat[i][j]);
                if(cont>maxi) x=i, y=j, maxi=cont;
                tot+=cont;
            }
            if(maxi<=1) {
                cout<<"Final score: "<<ans+(tot==0? 1000:0)<<", with "<<tot<<" balls remaining.\n";
                if(cas<t-1) cout<<"\n";
                break;
            }
            cout<<"Move "<<++mov<<" at ("<<10-x<<","<<y+1<<"): removed "<<maxi
                <<" balls of color "<<mat[x][y]<<", got "<<(maxi-2)*(maxi-2)<<" points.\n";
            ans+=(maxi-2)*(maxi-2);
            quitar(x,y,mat[x][y]);
            //rep(i,n) cerr<<mat[i]<<"\n";
            fix();
            //cerr<<"fixed:\n"; rep(i,n) cerr<<mat[i]<<"\n";
            
        }
        
    }



}