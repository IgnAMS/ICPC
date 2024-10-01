#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        int H[n]; rep(i,n) cin>>H[i];
        int mn=H[0], mx=H[0];
        bool ok=1;
        rep(i,n){
            cout<<mn<<" "<<mx<<"\n";
            mn= min(mn-k+1, H[i]);
            mx= max(mx+k-1, H[i]);
            if(mn > mx){ ok=0; break; }
        }
        cout<<mn<<" "<<mx<<"\n";
        if(!(mn<=H[n-1] && H[n-1]<=mx)) ok=0;
        cout<<(ok? "YES\n":"NO\n"); 
    }




}