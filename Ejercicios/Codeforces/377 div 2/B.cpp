#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;



int main(){
    ll n,k; cin>>n>>k;
    int arr[n];
    rep(i,n) cin>>arr[i];
    ll ans=0;
    for(int i=1;i<n;++i){
        ans+= max(ll(0), ll(k-arr[i]-arr[i-1]));
        arr[i]+= max(ll(0), ll(k-arr[i]-arr[i-1]));
    }
    cout<<ans<<endl;
    rep(i,n) cout<<arr[i]<<" ";
    cout<<endl;


    return 0;
}