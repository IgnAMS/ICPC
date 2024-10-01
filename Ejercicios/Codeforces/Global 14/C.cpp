#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n, m, x; cin>>n>>m>>x;
        int A[n]; rep(i,n) cin>>A[i];
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        rep(i,m) pq.push({0,i});
        vector<int> ans(n);
        rep(i,n){
            ii u = pq.top(); pq.pop();
            // cout<<u.ff<<"\n";
            ans[i]=u.ss;
            pq.push({u.ff+A[i],u.ss});
        }
        cout<<"YES\n";
        rep(i,n) cout<<ans[i]+1<<" "; cout<<"\n";
        // while(!pq.empty()) { cout<<pq.top().ff<<" "; pq.pop(); } cout<<"\n";
    }



    return 0;
}