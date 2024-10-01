#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        ll n, x; cin>>n>>x;
        ll A[n];
        rep(i,n) cin>>A[i];
        ll sum=0;
        bool stop=0;
        int pos=-1;
        ll amp = 1;
        bool primer=1;
        while(true){
            rep(i,n){
                if(i==pos){
                    //cout<<"finalmente sumo "<<amp<<" veces "<<A[i]<<"\n";
                    stop=1;
                    sum+=A[i]*amp;
                    break;
                }
                if(A[i]%x==0){
                    //cout<<"sumo "<<amp<<" veces "<<A[i]<<"\n";
                    sum+=A[i]*amp;
                    A[i]/=x;
                }
                else { 
                    //cout<<"sumo "<<amp<<" veces "<<A[i]<<"\n";
                    sum+= A[i]*amp;
                    if(primer){ pos= i==0? n-1: i-1; primer=0; }
                    if(n==1) stop=1;
                } 
            }
            amp*=x;
            if(stop) break;
        }
        
        cout<<sum<<"\n";
    }




    return 0;
}