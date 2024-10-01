#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    int t; cin>>t;
    set<int> perf;
    rep(i,103){
        perf.insert(i*i);
    }
    while(t--){
        int n; cin>>n;
        ll A[n]; rep(i,n) cin>>A[i];
        bool flag=0;
        rep(i,n) if(!perf.count(A[i])) flag=1;
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";


    }

    return 0;
}