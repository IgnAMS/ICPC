#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        rep(i,n) cin>>arr[i];
        for(int i=n-1;i>=0;i--){
            cout<<arr[i]<<" ";
        }
        cout<<"\n"
    }



    return 0;
}