#include<bits/stdc++.h>
#define rep(i,n)
ll mod=1e9+7;


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        ordered_set<int> superset;
        ll a,b,c,n;
        cin>>a>>b>>c>>n;
        ll F[n];
        F[0]=1;
        superset.insert(1);
        ll sum=F[0];
        for(int i=1;i<n;i++){
            F[i]=((a*(*superset.find_by_order((i-1)/2)))%mod + (b*(i+1))%mod + c)%mod;
            sum+=F[i];
        }
        cout<<sum<<endl;


    }

    return 0;
}
