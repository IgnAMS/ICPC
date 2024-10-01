#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int a,b,c; cin>>a>>b>>c;
        int suma=a+b+c;
        if(suma%9!=0) { cout<<"NO\n"; continue; }
        int x=suma/9;
        if(a<x || b<x || c<x) cout<<"NO\n";
        else cout<<"YES\n";
    }




    return 0;
}