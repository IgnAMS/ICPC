#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); 
    int t; cin>>t;
    while(t--){
        int a,b; cin>>a>>b;
        int aux=a; a=max(a,b); b=min(aux,b);
        cout<<min({a, b, (a+b)/3})<<"\n";
    }

    return 0;
}