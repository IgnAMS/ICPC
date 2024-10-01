#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;


int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<ll> A(n); rep(i,n) cin>>A[i];
        ll ans = 0;
        rep(i,n-1) ans = max(ans, A[i] * A[i+1]);
        cout<<ans<<'\n';
    }




    return 0;
}