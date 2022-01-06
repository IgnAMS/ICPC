#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    ll max = log2(1e9);
    ll ans=0;
    int primer=-1;
    for(int i=max;i>=0;i--){
        if((n & (1<<i))) {
            if(primer==-1) primer=i;
            ans+=(1<<(primer-i));
            
        }
    }
    
    cout<<ans<<"\n";





    return 0;
}