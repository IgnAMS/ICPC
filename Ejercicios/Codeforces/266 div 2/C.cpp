#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;



int main(){
    int n; cin>>n;
    ll arr[n];
    ll acc[n+1];
    acc[0]=0;
    rep(i,n) {cin>>arr[i];acc[i+1]=acc[i]+arr[i];}

    ll S=acc[n];
    if(S%3!=0){
        cout<<0<<endl;
        return 0;
    }
    
    int cont[n+1];
    for(int i=1;i<=n;i++){
        if(S-acc[i-1] == S/3) cont[i]=1;
        else cont[i]=0;
    }
    int sums[n+1];
    sums[n]=cont[n];

    for(int i=n-1;i>=0;i--){
        sums[i]=sums[i+1]+cont[i];
    }

    ll ans=0;
    for(int i=1;i<=n-2;i++){
        if(acc[i]==S/3){
            ans+=sums[i+2];
        }
    }

    cout<<ans<<endl;


    return 0;
}