#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<int> Rest(m,0);
        ll A[n]; rep(i,n) { cin>>A[i]; Rest[A[i]%m]++; }
        int ans=0;
        rep(i,m/2+1){
            if(i==0){
                ans+=Rest[0]? 1:0;
                continue;
            }
            //cout<<i<<" "<<Rest[i]<<" "<<Rest[m-i]<<"\n";
            int mini=min(Rest[i],Rest[m-i]);
            if(Rest[i]==0 && Rest[m-i]==0) { continue; }
            if(i==m/2 && m%2==0) { 
                ans++;
                continue;
            }
            ans++;
            ans+= (Rest[i]==mini? 0 : Rest[i]-mini-1);
            ans+= (Rest[m-i]==mini? 0 : Rest[m-i]-mini-1);
        }
        cout<<ans<<"\n";

    }






    return 0;
}