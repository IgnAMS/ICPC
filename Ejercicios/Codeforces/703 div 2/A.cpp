#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        ll A[n]; rep(i,n) cin>>A[i];
        ll sum=0;
        bool oc=1;
        rep(i,n) { sum+=A[i]; if(sum<i*(i+1)/2) oc=0; }
        if(oc) cout<<"YES\n";
        else cout<<"NO\n";
    }



    return 0;
}