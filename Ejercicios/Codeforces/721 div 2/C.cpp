#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
#define ff first
#define ss second

int main(){
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        map<ll, ll> mapa;
        int A[n]; 
        ll ans = 0;
        ll x = 0;
        rep(i,n) {
            cin>>A[i];
            if(!mapa.count(A[i])) mapa[A[i]] = 0;
            x += mapa[A[i]];
            mapa[A[i]] += i+1;  
            ans += x;
            
        }
        cout<<ans<<"\n";


    }



    return 0;
}