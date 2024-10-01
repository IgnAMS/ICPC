#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        ll arr[n];
        ll maxi=0;
        ll maxizq[n];
        maxizq[0]=0;
        rep(i,n) {
            cin>>arr[i]; 
            maxi=max(maxi,arr[i]);
            if(i)
                maxizq[i]=max(maxizq[i-1],arr[i]);
        }
        ll saltos=0;
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                saltos+= arr[i]-arr[i+1];
            }
        }
        cout<<saltos<<endl;
    }

    return 0;
}