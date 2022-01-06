#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int,int> ii;
#define ff first
#define ss second

ii choice[(1<<24)+1];
int DP[(1<<24)+1];
int d[26][26];
ii pos[25];
int n;

int dp(int mask){
    //rep(i,n) cout<<(mask & (1<<i)); cout<<"\n";
    int& ans=DP[mask];
    if(ans!=-1) return ans;
    if(mask==0) return ans=0;
    int i,j,b; 
    for(i=1,b=1; i<=n && !(mask&b); b<<=1, i++) {}
    //cout<<"llevo al elemento "<<i<<" solito\n";
    ans= 2*d[0][i]+ dp(mask & ~b);
    int mask2= mask&~b;
    choice[mask]={i,i};
    for(j=i+1, b<<=1;j<=n;b<<=1,j++) if(mask2 & b) {
        int tmp=d[0][i]+d[i][j]+d[j][0] +dp(mask2& ~b);
        if(tmp<ans){
            //cout<<"llevo a "<<i<<" y a "<<j<<" juntos\n";
            ans=tmp;
            choice[mask]={i,j};
        }
    }

    return ans;
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>pos[0].ff>>pos[0].ss;
    cin>>n;
    rep(i,n) cin>>pos[i+1].ff>>pos[i+1].ss;
    rep(i,n+1) rep(j,n+1) 
        d[i][j]=(pos[i].ff-pos[j].ff)*(pos[i].ff-pos[j].ff)+
                (pos[i].ss-pos[j].ss)*(pos[i].ss-pos[j].ss);
    int mask=(1<<n)-1;
    memset(DP,-1,sizeof(DP));
    
    cout<<dp(mask)<<"\n";
    mask=(1<<n)-1;
    cout<<0;
    while(mask){
        ii p= choice[mask];
        cout<<" "<<p.ff;
        if(p.ff!=p.ss) cout<<" "<<p.ss;
        mask=mask & ~(1<<(p.ff-1)); mask= mask & ~(1<<(p.ss-1));
        cout<<" "<<0;
    }
    cout<<"\n";
}