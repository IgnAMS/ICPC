#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        if(n-k==1){
            rep(i,k-2) cout<<i+1<<" ";
            cout<<k<<" "<<k-1<<"\n";
        }
        else{
            rep(i,k) cout<<i+1<<" ";
            cout<<"\n";
        }
        
    }


    return 0;
}