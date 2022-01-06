#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second

ii DP[3000+3][3000+3];
vector<ii> ans;
int S,n;
vector<int> A;

ii dp(int i, int x, int s){ // x-> pos, s->sum
    ii& ans=DP[x][s];
    if(ans.ff!=-1) { 
        return ans;
    }
    if(x==n) return {0,0};
    cout<<x<<" "<<s<<"\n";
    ans.ff=0;
    ans=dp(i,x+1,s); //la opcion de no tomarlo
    if(s+A[x]<=S){
        cout<<"tomo el elemnto "<<x<<" "<<A[x]<<"\n";
        if(i==-1) i=x;
        if(s+A[x]==S) {
            cout<<"inicio: "<<i<<", final: "<<x<<"\n"; 
            ans.ff++; ans.ss=x; 
            //cout<<"ans found\n"; 
        }
        if(s+A[x]<S) ans.ff+=dp(i,x+1,s+A[x]).ff;
        if(DP[x+1][s+A[x]].ff!=0){ 
            cout<<"solucion por rec\n";
            cout<<"inicio: "<<i<<", final: "<<DP[x+1][s+A[x]].ss<<"\n";
        }
        cout<<"suelto el elemento "<<x<<"\n";
    }
    return ans;
}
    
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    rep(i,300+2) rep(j,3000+2) DP[i][j]= {-1,-1};
    cin>>n>>S;
    A.resize(n); 
    rep(i,n) cin>>A[i];    
    cout<<dp(-1,0,0).ff<<"\n";


}