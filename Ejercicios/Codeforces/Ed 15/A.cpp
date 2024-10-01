#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    int n; cin>>n;
    int arr[n];
    rep(i,n) cin>>arr[i];
    int last=arr[0];
    int maxi=0;
    int low=0;
    int top=0;
    for(int i=1;i<n;i++){
        if(arr[i]>last){
            last=arr[i];
            top=i;
        }
        else{
            maxi=max(maxi,top-low+1);
            low=i;
            last=arr[i];
        }
    }
    maxi=max(maxi,top-low+1);
    cout<<maxi<<endl;


    return 0;
}