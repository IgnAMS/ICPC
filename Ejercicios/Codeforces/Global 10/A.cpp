#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        deque<ll> q1(n),q2;
        bool dif=false;
        rep(i,n){
            cin>>q1[i];
            if(i>0 && q1[i]!=q1[i-1]) {dif=true; break;} 
        } 
        if(dif) cout<<1<<endl;
        else cout<<n<<endl;
    } 


    return 0;
}