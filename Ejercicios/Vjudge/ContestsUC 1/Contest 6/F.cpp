#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
#define ff first
#define ss second

pair<ll,ll> DP[100];
ll a[100];

int n;
pair<ll,ll> dp(ll i, ll x){
    if(n==1) return {0,0};
    if(i==0){
        //simplemente retorno el valor del 0
        return DP[0]= {a[0],a[0]};  
    }
    if(i==1){
        //si es 1, entonces debo multiplicar al 0
        return DP[i]={x*a[0],(x+a[0])%100};
    }
    if(DP[i].ff!=-1) return DP[i];
    auto p=dp(i-1,a[i-1]);
    DP[i] = {p.ff + p.ss*x, (p.ss+x)%100};
    
    if(i-2>=0){
        p=dp(i-2,a[i-2]);
        int aux=(x+a[i-1])%100;
        
        if(DP[i].ff > p.ff + p.ss*aux + a[i-1]*x){
            DP[i]={p.ff + p.ss*aux + a[i-1]*x, (aux+p.ss)%100};
        }
    }

    //cout<<"DP["<<i<<"]: "<<DP[i].ff<<endl;
    return DP[i];
}



int main(){
    while(cin>>n){
        rep(i,n) DP[i]={-1,0};
        rep(i,n) cin>>a[i];
        cout<<dp(n-1,a[n-1]).ff<<endl;
    }


    return 0;
}