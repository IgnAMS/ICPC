#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int a,b,c; cin>>a>>b>>c;
        ll z=1;
        rep(i,c-1) z*= 10;
        if(c!=1) z+=1;
        //cout<<z<<"\n";
        ll aux1=1, aux2=1;
        rep(i,a-c) aux1*=10;
        rep(i,b-c) aux2*=10;
        aux1++, aux2++;
        //cout<<z<<" "<<aux1<<" "<<aux2<<"\n";
        while(z!=1 && aux2%z==0) aux2++;
        while(z!=1 && aux1%z==0) aux1++;
        while(__gcd(aux1,aux2)!=1) aux1++;
        cout<<z*aux1<<" "<<z*aux2<<"\n";
    }
    





    return 0;
}