#include<bits/Stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        int maxi=0;
        bool dif=false;
        int id=-1;
        rep(i,n){
            cin>>arr[i];
            if(i && arr[i]!=arr[i-1]) dif=true;
            maxi=max(maxi,arr[i]);
        }
        if(!dif) { cout<<-1<<"\n"; continue; } 
        //cout<<"aaaa\n";
        rep(i,n){
            if(arr[i]==maxi && ((i>0 && arr[i]>arr[i-1]) || (i+1<n && arr[i]>arr[i+1]))){
                //cout<<"asd "<<i<<"\n";
                id=i+1;
            }
        }

        cout<<id<<"\n"; 
    }




    return 0;
}