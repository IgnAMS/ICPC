#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        ll a,b,c,r; cin>>a>>b>>c>>r;
        if(b<a) swap(b,a);
        ll dist=b-a;
        if(c<=a && c+r>a) dist-=min(b-a,c+r-a);
        else if(a<=c && c<=b) dist-=min(c-a,r)+min(b-c,r);
        else if(c>b && c-r<b) dist-=min(b-a,b-(c-r));
        cout<<dist<<"\n";
    }
    





    return 0;
}