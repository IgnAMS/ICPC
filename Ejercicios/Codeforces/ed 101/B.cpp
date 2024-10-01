#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int r; cin>>r;
        int R[r]; rep(i,r) cin>>R[i];
        int b; cin>>b;
        int B[b]; rep(i,b) cin>>B[i];
        
        int ans=0;
        int act=0,sum=0;
        rep(i,r){
            act+=R[i];
            sum=max(sum,act);
        }
        ans+=sum;
        act=0,sum=0;
        rep(i,b){
            act+=B[i];
            sum=max(sum,act);
        }
        ans+=sum;
        cout<<ans<<"\n";
    }



    return 0;
}