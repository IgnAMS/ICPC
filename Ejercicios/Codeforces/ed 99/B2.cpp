#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int sum=0, ans=0;
        for(int i=1;i<=n;i++){
            sum+=i; ans++;
            if(sum>=n) break;
        }
        
        if(sum!=n+1) cout<<ans<<"\n";
        else cout<<ans+1<<"\n";
    }
    return 0;
}

