#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string str;
        cin>>str;
        bool imp=false, par=false;
        for(int i=0;i<n;i++){
            if(i%2==1 && (str[i]-'0')%2==0) par=true;
            if(i%2==0 && (str[i]-'0')%2==1) imp=true;
        }
        if(n%2==0){ //breach tiene la ultima jugada
            if(par) cout<<2<<"\n";
            else cout<<1<<"\n";
        }
        else{
            if(imp) cout<<1<<"\n";
            else cout<<2<<"\n";
        }
    }


    return 0;
}