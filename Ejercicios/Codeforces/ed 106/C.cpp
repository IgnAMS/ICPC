#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<ll> R,C;
        rep(i,n) { ll x; cin>>x; i%2==0? R.push_back(x):C.push_back(x); }
        ll suma=0;
        //parto con 
        ll minc=1e10, minr=1e10;
        ll ans=1e16;
        //primero chequeo
        rep(i,n/2){
            suma+=R[i]+C[i];
            minr=min(minr,R[i]);
            minc=min(minc,C[i]);
            ans=min(ans, minr*(n-i)+minc*(n-i)+suma-minc-minr);
            //cout<<ans<<"\n";
            if(i+1<n/2+(n%2)){
                ll minaux=min(minr,R[i+1]);
                ans=min(ans, minaux*(n-i-1)+minc*(n-i)+R[i+1]+suma-minc-minaux);
                //cout<<ans<<"\n";
            }
        }
        cout<<ans<<"\n";
        //cout<<"\n";
    }




    return 0;
}