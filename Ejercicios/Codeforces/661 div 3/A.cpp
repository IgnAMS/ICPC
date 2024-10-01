#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t; 
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr.begin(),arr.end());
        bool pasa=true;
        for(int i=0;i<n-1;i++){
            if(arr[i+1]-arr[i]>1){
                pasa=false;
                break;
            }
        }
        if(pasa){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }

    }


    return 0;
}