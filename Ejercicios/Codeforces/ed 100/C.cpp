#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        ii A[n];
        rep(i,n) cin>>A[i].ff>>A[i].ss;

        int i=0,ans=0,x=0;
        int d=(A[i].ss>1? 1:A[i].ss==0? 0:-1);
        int time=0;
        time= A[0].ff+abs(x-A[i].ss);
        int pos=A[0].ss;
        i++;
        rep(i,n) if(i){
            int mini,maxi;
            int k=A[i].ff;
            if(k<time){
                mini= min(x,x+d*(k-A[i-1].ff));
                maxi= max(x,x+d*(k-A[i-1].ff));
                if(mini<= A[i-1].ss && A[i-1].ss<=maxi) ans++;
                x+=d*(k-A[i-1].ff);
            }
            else{
                mini= min(x,pos);
                maxi= max(x,pos);
                if(mini<= A[i-1].ss && A[i-1].ss <=maxi) ans++;
                d=(A[i].ss>pos? 1:A[i].ss==pos? 0:-1);
                x=pos;
                pos=A[i].ss;
                time=A[i].ff+abs(A[i].ss-x);
                //if(i==n-1) ans++;
            }
            //cout<<time<<" "<<mini<<" "<<A[i-1].ss<<" "<<maxi<<"\n";
        }
        int mini=min(x,pos), maxi=max(x,pos);
        //cout<<mini<<" "<<A[n-1].ss<<" "<<maxi<<"\n";
        if(mini<= A[n-1].ss && A[n-1].ss<=maxi) ans++;

        cout<<ans<<"\n";
            
        
    }



    return 0;
}