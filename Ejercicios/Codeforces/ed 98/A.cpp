#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int a,b; cin>>a>>b;
        int mini= min(a,b);
        int ans= 2*mini +2*(a-mini)+2*(b-mini) + (a==b? 0:-1);
        cout<<ans<<"\n";
    }




    return 0;
}