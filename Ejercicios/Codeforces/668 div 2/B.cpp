#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        ll arr[n];
        rep(i,n) cin>>arr[i];
        ll cost=0;
        ll acc=0;
        bool primer=true;
        for(int i=n-1;i>=0;i--){
            if(arr[i]<0) {acc+=arr[i]; primer=false;}
            if(arr[i]>0 && !primer) acc= min(ll(0),acc+arr[i]);
        }
        cout<<-acc<<"\n";
    }



    return 0;
}