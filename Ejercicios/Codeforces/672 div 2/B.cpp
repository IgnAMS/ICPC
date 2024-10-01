#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<ll> arr(n);
        vector<ll> conts(int(log2(1e5))+1,0);
        ll ans=0;
        rep(i,n){
            cin>>arr[i];
            ans+=conts[int(log2(arr[i]))];
            conts[int(log2(arr[i]))]++;
        } 
        
    }
    
    return 0;
}