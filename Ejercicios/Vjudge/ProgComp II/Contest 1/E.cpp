#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
typedef pair<ll,ll> ii;
#define ff first
#define ss second

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    ll n;
    while(cin>>n){
        if(n==0) break;
        ll arr[n];
        ll maxi=0;
        stack<ii> q;
        ll right[n];
        ll left[n];
        rep(i,n) cin>>arr[i];

        memset(left,0,sizeof(left));
        rep(i,n){
            while(!q.empty() && q.top().ff >= arr[i]){
                left[i]+=left[q.top().ss]+1;
                q.pop();
            }

            if(arr[i]) q.push({arr[i],i});
        }
        while(!q.empty()) q.pop();

        memset(right,0,sizeof(right));
        for(int i=n-1;i>=0;i--){
            while(!q.empty() && q.top().ff >= arr[i]){
                right[i]+=right[q.top().ss]+1;
                q.pop();
            }

            if(arr[i]) q.push({arr[i],i});
        }
        

        for(int i=0;i<n;i++){
            maxi=max(maxi, arr[i]*(left[i]+1+right[i]));
        }


    
        cout<<maxi<<endl;   
    }

    return 0;
}