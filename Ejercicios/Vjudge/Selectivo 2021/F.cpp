#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii, int> iii;
#define ff first
#define ss second




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    map<ii,ll> mapa;
    vector<ii> V(n);
    rep(i,n) cin>>V[i].ff>>V[i].ss;
    rep(i,n) for(int j=i+1; j<n;j++){
        int dx= V[i].ff-V[j].ff;
        int dy= V[i].ss-V[j].ss;
        if(dx*dy>=0) dx=abs(dx), dy=abs(dy);
        else if(dx*dy<0) dx=-abs(dx), dy=abs(dy);
        if(!mapa.count({dy,dx})) mapa[{dy,dx}] = 0;
        mapa[{dy,dx}]++;
    }

    ll ans=0;
    for(auto& u: mapa){
        ans+=u.ss*(u.ss-1)/2;
    }
    cout<<ans/2<<"\n";

    return 0;
}