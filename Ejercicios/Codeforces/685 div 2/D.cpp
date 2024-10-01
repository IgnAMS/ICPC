#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        int i=0,j=0;
        bool sw=0;
        for(int i=0;i<n;i++){
            
        }
        while(1){
            //cout<<i<<" "<<j<<" ";
            //cout<<"le toca jugar a "<<(sw==0? "Ashish":"Utkarsh")<<"\n";
            if(sw==0) i+=k;
            else j+=k;
            sw=!sw;
            if(i*i+j*j>n*n) break;
        }
        if(sw==1) cout<<"Utkarsh\n";
        else cout<<"Ashish\n";
        //cout<<"\n";
    }

    return 0;
}