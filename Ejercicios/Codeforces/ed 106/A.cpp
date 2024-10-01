#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int n,k1,k2; cin>>n>>k1>>k2;
        int w,b; cin>>w>>b;
        int a1=n-k1, a2=n-k2;
        int maxw= max( min(k1,k2)+(max(k1,k2)-min(k1,k2))/2, k1/2+k2/2 );
        int maxb= max( min(a1,a2)+(max(a1,a2)-min(a1,a2))/2, a1/2+a2/2 );
        //cout<<maxw<<" "<<maxb<<"\n";
        if(maxw>=w && maxb>=b) cout<<"YES\n";
        else cout<<"NO\n";
    }




    return 0;
}