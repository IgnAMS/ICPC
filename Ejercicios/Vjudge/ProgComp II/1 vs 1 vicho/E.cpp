#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second

int DP[10001][1001];
vector<ii> cd;

int f(int i, int m){
    //cout<<i<<" "<<m<<"\n";
    if(i==cd.size()) return 0;
    if(DP[i][m]!=-1) return DP[i][m];
    DP[i][m]=f(i+1,m); // no lo tomo
    if(m-cd[i].ff>=0){
        //cout<<f(i+1, m-cd[i].ff)+cd[i].ss<<" "<<DP[i][m]<<"\n\n";
        DP[i][m]=max(f(i+1,m-cd[i].ff)+cd[i].ss, DP[i][m]);
    }
    return DP[i][m];
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, c0, d0; cin>>n>>m>>c0>>d0;
    memset(DP,-1,sizeof(DP));
    cd.push_back({c0,d0});

    for(int i=1; c0*i<=n; i++) cd.emplace_back(c0,d0);

    rep(i,m){
        int a,b,c,d;
        cin>>a>>b>>c>>d;   
        for(int i=1; c*i <= n && b*i<=a; i++) cd.emplace_back(c,d);
    }
    
    int ans=0;
    if(n>0){
        ans=f(0,n);
    }
    cout<<ans<<"\n";


    return 0;
}