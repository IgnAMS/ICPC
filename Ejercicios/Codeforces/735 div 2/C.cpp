#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define repx(i,a,b) for(ll i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)


int main(){
    int t; cin>>t;
    //cout<<(69 & (1 <<6))<<'\n';
    while(t--){
        ll n, m; cin>>n>>m; m++;
        ll ans = 0;
        for(int k = 30; k>=0; k--){
            if((n & (1 << k)) == (m & (1 << k))) continue; // Reviso si estan ambos prendidos o apagados
            if(n & (1 << k)) break;
            if(m & (1 << k)) ans |= (1 << k);
        }
        cout<<ans<<'\n';
    }

    return 0;
}
