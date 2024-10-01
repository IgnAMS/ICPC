#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll cont=0;
    ll mul=1;
    for(ll i=1;i<=(n/2-1);i++) mul*=i;
    
    if(n==2) cout<<1<<"\n";
    if(n==4) cout<<3*mul*mul<<"\n"; 
    if(n==6) cout<<mul*mul*10<<"\n";
    if(n==8) cout<<mul*mul*35<<"\n";
    if(n==10) cout<<mul*mul*126<<"\n";
    if(n==12) cout<<mul*mul*462<<"\n";
    if(n==14) cout<<mul*mul*1716<<"\n";
    if(n==16) cout<<mul*mul*6435<<"\n";
    if(n==18) cout<<mul*mul*24310<<"\n";
    if(n==20) cout<<mul*mul*92378<<"\n";

    return 0;
}

