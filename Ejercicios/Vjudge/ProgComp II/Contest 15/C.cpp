#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    string lineas[n];
    rep(i,n) cin>>lineas[i];
    vector<vector<int>> mat(n,vector<int>(m,1));
    rep(i,n){
        for(int j=m-2;j>=0;j--){
            if(lineas[i][j] == lineas[i][j+1]) {
                mat[i][j]=mat[i][j+1]+1;
            }
        }
    } 
            
    
    vector<int> U(n,0), D(n,0); //Up, Down
    int ans=0;
    rep(j,m){
        stack<ii> q;
        rep(i,n){
            ii u={-1,-1};
            while(!q.empty() && q.top().ff >= mat[i][j]){
                u =q.top(); q.pop();
            }
            if(u.ff!=-1)  U[i] = U[u.ss]+(i-u.ss);
            else U[i] = 0;
            q.push({mat[i][j],i});
        }
        while(!q.empty()) q.pop();  
        for(int i=n-1;i>=0;i--){
            ii u={-1,-1};
            while(!q.empty() && q.top().ff >= mat[i][j]){
                u = q.top(); q.pop();
            }
            if(u.ff!=-1)  D[i] = D[u.ss]+(u.ss-i);
            else D[i] = 0;
            q.push({mat[i][j],i});
        }
        rep(i,n){
            //cout<<"estoy en "<<i<<" "<<j<<"\n";
            //cout<<"lo maximo que puedo ir hacia los lados es "<<U[i]+D[i]+1<<"\n";
            //cout<<"la altura es "<<mat[i][j]<<"\n\n";
            int mini=min(U[i]+D[i]+1, mat[i][j]);
            ans= max(ans, mini*mini);
        }
    }

    cout<<ans<<"\n";
    return 0;
}