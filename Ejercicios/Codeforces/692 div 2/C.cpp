#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second

vector<bool> I,solv;
vector<int> rows,cols;
int solve(int x){
    cerr<<"visto la row "<<x<<"\n";
    int ans=0;
    if(rows[x]==-1) return 0;
    if(solv[x]) { return 0; }
    if(rows[x]==x) { solv[x]=1; return 0; }
    if(rows[rows[x]]==-1) { 
        solv[x]=1;
        rows[rows[x]]=-1; //reviso la fila en la que deberia estar y la marco
        rows[x]=-1;// desmarco la actual
        return 1;
    }
    else{
        I[x]=1;
        if(I[rows[x]]){ //encontré un ciclo
            rows[rows[x]]=-1;
            rows[x]=-1;
            I[x]=0;
            return 2;
        }
        ans=solve(rows[x])+1;
        I[x]=0;
        rows[rows[x]]=-1;
        rows[x]=-1;
        return ans;
    }
    
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        cols.assign(n,-1); rows.assign(n,-1);
        I.assign(n,0); solv.assign(n,0);
        rep(i,m) {
            int r,c; cin>>c>>r; r--,c--;
            rows[r]=c, cols[c]=r;
            //cerr<<aux<<" "<<rows[aux]<<"\n";
        }
        int ans=0;
        vector<bool> solv(n,0);
        rep(i,n) { ans+=solve(i); }
        cout<<ans<<"\n";i
    }




    return 0;
}