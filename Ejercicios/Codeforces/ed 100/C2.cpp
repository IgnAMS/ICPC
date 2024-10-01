#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        ll T[n], P[n];
        rep(i,n) cin>>T[i]>>P[i];
        ll d=(P[0]>0? 1:P[0]==0? 0:-1);
        ll x=0;
        ll pos=P[0];
        ll time= T[0]+abs(P[0]); //tiempo para llegar al next
        int ans=0;
        ll mini,maxi;
        rep(i,n) if(i) {
            if(T[i]<time){
                mini=min(x,x+d*(T[i]-T[i-1]));
                maxi=max(x,x+d*(T[i]-T[i-1]));
                if(mini<= P[i-1] && P[i-1]<=maxi) ans++;
                x+=d*(T[i]-T[i-1]);
            }
            else{
                mini=min(x,pos);
                maxi=max(x,pos);
                if(mini<=P[i-1] && P[i-1]<=maxi) ans++;
                x=pos;
                d=(P[i]>x? 1:P[i]==x? 0:-1);
                time=T[i]+abs(P[i]-pos);
                pos=P[i];
            }
            //cout<<mini<<" "<<P[i-1]<<" "<<maxi<<"\n";
        }
        mini=min(x,pos); maxi=max(x,pos);
        if(mini<=P[n-1] && P[n-1]<=maxi) ans++;
        cout<<ans<<"\n";
    }



    return 0;
}