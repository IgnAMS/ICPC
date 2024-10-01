#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        rep(i,n) cin>>arr[i];
        bool flag=true;
        for(int i=1;i<n;i++){
            if(arr[i-1]<=arr[i]) flag=true;
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }



    return 0;
}