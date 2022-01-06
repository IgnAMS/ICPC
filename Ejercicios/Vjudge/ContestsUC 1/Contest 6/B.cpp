#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

int n;
int DP[1<<24];
int adj[25][25];
int xi[25], yi[25];
pair<int,int> choice[1<<24];

int inline calcd(int x1,int x2,int y1,int y2){
    int dx= x1-x2;
    int dy=y1-y2;
    return dx*dx+dy*dy;
} 


int dp(int mask){
    if(mask==0) return 0;
    
    int& ans = DP[mask];
    if(ans!=-1) return ans;
    //ya no le quedan vecinos por viistar
    int aux=mask;
    int i,j,b;

    for(i=1, b=1; i<=n; b<<=1,i++){
        if(mask & b) break;
    }

    int mask2= mask & ~b;
    ans=2*adj[0][i]+dp(mask2);
    choice[mask]={i,i};

    for(j=i+1, b<<=1; j<=n; ++j,b<<=1){
        if(mask2 & b){
            int tmp=adj[0][i]+adj[i][j]+adj[j][0]+dp(mask2 & ~b);
            if(tmp < ans){
                ans=tmp;
                choice[mask]={i,j};
            }
        }
    }


    return ans;
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cout.tie(0);
    int x1,y1;
    cin>>x1>>y1>>n;

    xi[0]=x1, yi[0]=y1;
    rep(i,1,n+1) cin>>xi[i]>>yi[i];
    int mask=(1<<n)-1;
    memset(DP,-1,sizeof(int)*(mask+2));

    rep(i,0,n+1) rep(j,0,n+1) {
        adj[i][j] = calcd(xi[i],xi[j],yi[i],yi[j]);
    }
    cout<<dp(mask)<<endl;
    cout<<"0";

    while(mask){
        auto p=choice[mask];
        mask &= ~(1<<(p.first-1));
        cout<<" "<<p.first;
        if(p.first != p.second){
            mask &= ~(1<<(p.second-1));
            cout<<" "<<p.second;
        }
        cout<<" 0";
    }
    cout<<endl;

    return 0;
}