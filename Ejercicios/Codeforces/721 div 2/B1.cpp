#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)


int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        int cont=0;
        rep(i,n) if(s[i]=='0') cont++;
        if(cont%2==0 || cont == 1) cout<<"BOB\n";
        else cout<<"ALICE\n";
    }

    return 0;
}