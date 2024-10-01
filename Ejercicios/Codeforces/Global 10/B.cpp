#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
 
int main(){
    int t; cin>>t;
    while(t--){
        ll n,k; cin>>n>>k;
        ll d = -1e18;
        ll mini=1e18;
        ll arr[n];
        rep(i,n){
            cin>>arr[i];
            d=max(d,arr[i]);
            mini=min(mini,arr[i]);
        }
 
        rep(i,n){
            arr[i]=d-arr[i];
        }
        d=d-mini;
 
        if(k%2==1){
            rep(i,n) cout<<arr[i]<<" ";
            cout<<endl;
        }   
        else{
            rep(i,n) cout<<d-arr[i]<<" ";
            cout<<endl;
        }
        
    }
 
 
    return 0;
}