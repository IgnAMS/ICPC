#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        vector<bool> visited(n,0);
        int maxi=0;
        int ind=0;
        rep(i,n) {
            cin>>arr[i]; 
            if(arr[i]>maxi){
                maxi=max(maxi,arr[i]);
                ind=i;
            }
        }
        vector<int> ans(n);
        visited[ind]=true;
        int div=maxi;
        ans[0]=maxi;

        for(int i=1;i<n;i++){
            int maxi=0;
            for(int j=0;j<n;j++){
                if(visited[j]) continue;
                if(__gcd(div,arr[j])>maxi){
                    maxi=__gcd(div,arr[j]);
                    ind=j;
                }
            }
            visited[ind]=true;
            div=maxi;
            ans[i]=arr[ind];
        }
        rep(i,n) cout<<ans[i]<<" "; cout<<"\n";
    }


    return 0;
}