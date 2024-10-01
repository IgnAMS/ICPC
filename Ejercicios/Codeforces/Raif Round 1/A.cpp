#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        ll x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        ll ans=abs(x1-x2)+abs(y1-y2);
        if(!(x1==x2 || y1==y2)) ans+=2;
        cout<<ans<<"\n";
    }



    return 0;
}