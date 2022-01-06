#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int mod=1000000007;



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    if(n==1) { cout<<0<<"\n"; return 0; }
    else if(n==2) { cout<<3<<"\n"; return 0; }
    else if(n==3) { cout<<6<<"\n"; return 0; }
    
    ll a2 = 3, a3 = 6;
    ll n_1=a3, n_2=a2, n_3=0;
    ll actual=1;
    for(int i=4;i<=n;i++){
        actual = (a2*n_2 + a3*n_3)%mod;
        ll mult=1;
        rep(j,i-2) mult= (mult*2)%mod;
        mult = (mult*3)%mod;
        actual = (actual+mult)%mod;
        //cout<<actual<<"\n";
        n_3 = n_2, n_2=n_1, n_1=actual;
    }
    cout<<actual<<"\n";

    return 0;
}