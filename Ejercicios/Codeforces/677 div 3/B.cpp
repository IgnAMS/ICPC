#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        bool primer=true, one=true;
        int cont0=0;
        int cont=0;
        rep(i,n){
            cin>>arr[i];
            if(arr[i]==1 && primer) {primer=false; cont=0;}
            else if(arr[i]==1 && !primer){
                one=false;
                cont0+=cont; cont=0;
            } 
            if(arr[i]==0) cont++;
        }
        if(one) cout<<0<<"\n";
        else cout<<cont0<<"\n";
    }



}