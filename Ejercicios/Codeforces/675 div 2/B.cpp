#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    int t; cin>>t;
    while(t--){
        ll n,m; cin>>n>>m;
        ll mat[n][m];
        rep(i,n) rep(j,m) cin>>mat[i][j];
        ll limi= n%2==0? n/2:(n/2+1);
        ll limj= m%2==0? m/2:(m/2+1);
        ll ans=0;
        rep(i,limi){
            rep(j,limj){
                ll suma=mat[i][j]+mat[n-i-1][j]+mat[i][n-j-1]+mat[n-i-1][m-j-1];
                suma/=4;
                //cout<<"el promedio en "<<i<<" "<<j<<" es de "<<suma<<"\n";
                ll cont1=0;
                ll cont2=0;
                vector<ll> conts(4,0);
                vector<ll> arr={mat[i][j],mat[n-i-1][j],mat[i][m-j-1],mat[n-i-1][m-j-1]};
                
                cont1+=abs(suma-mat[i][j])+abs(suma-mat[n-i-1][j]);
                cont1+=abs(suma-mat[i][m-j-1])+abs(suma-mat[n-i-1][m-j-1]);

                cont2+=abs(suma+1-mat[i][j])+abs(suma+1-mat[n-i-1][j]);
                cont2+=abs(suma+1-mat[i][m-j-1])+abs(suma+1-mat[n-i-1][m-j-1]);
                rep(k,4){
                    conts[k]+=abs(arr[k]-mat[i][j])+abs(arr[k]-mat[n-i-1][j]);
                    conts[k]+=abs(arr[k]-mat[i][m-j-1])+abs(arr[k]-mat[n-i-1][m-j-1]);
                }
                

                if(j==limj-1 && limj==m/2+1) {
                    cont1/=2; 
                    cont2/=2;
                    rep(k,4) conts[k]/=2;
                }

                if(i==limi-1 && limi==n/2+1) {
                    cont1/=2; 
                    cont2/=2;
                    rep(k,4) conts[k]/=2;
                }
                ll mini=1e18;
                cout<<cont1<<" "<<cont2<<"\n";
                rep(k,4) {mini=min(mini,conts[k]);cout<<conts[k]<<" ";} cout<<"\n";
                //cout<<cont1<<"\n";
                ans+=min({cont1,cont2,mini});
            }
        }
        cout<<ans<<"\n";
         
    }


    return 0;
}