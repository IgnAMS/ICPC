#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        string linea;
        int n; 
        cin>>n>>linea;
        int cont1=0, cont0=0;
        for(auto x: linea){
            if(x=='0') cont0++;
            else cont1++;
        }
        if(cont1>cont0){
            for(int i=0;i<n;i++){
                cout<<1;
            }
            cout<<endl;
        }
        else{
            for(int i=0;i<n;i++){
                cout<<0;
            }
            cout<<endl;
        }
    }




}