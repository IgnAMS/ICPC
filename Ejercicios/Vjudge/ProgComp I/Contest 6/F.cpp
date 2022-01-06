#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repx(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
#define ss second
#define ff first


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        map<ll, vector<ll>> mapa;
        ll U[n]; rep(i,n) { cin>>U[i]; mapa[U[i]]=vector<ll>(); }
        ll h;
        ll S[n]; rep(i,n) { cin>>h; mapa[U[i]].push_back(h); }
        for(auto& u: mapa) sort(u.ss.begin(), u.ss.end());
        
        //for(auto& u: mapa) { rep(i,u.ss.size()) cout<<u.ss[i]<<" "; cout<<"\n"; }
        vector<vector<ll>> acc;
        for(auto& u: mapa){
            acc.push_back({});
            acc.back().assign(u.ss.size()+1, 0);
            rep(i,u.ss.size()) acc.back()[i+1] = acc.back()[i] + u.ss[i];
        }

        int k=1;
        for(k=1; k<=n;k++){
            ll ans=0;
            for(auto& u: acc) {
                int siz= u.size()-1;
                ans+= u[siz] - u[(siz)%k];
            }
            if(ans==0) break;
            cout<<ans<<" ";
        }
        rep(i,n-k+1) cout<<0<<" "; 
        cout<<"\n";
    }





    return 0;
}