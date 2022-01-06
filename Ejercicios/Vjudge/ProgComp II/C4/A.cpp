#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef unsigned long long ll;
typedef pair<vector<ll>,ll> pvi;
#define ff first
#define ss second
int m;

ll back2(int x, vector<int>& A, vector<pvi>& B,vector<int>& conts){
    if(x==B.size()) return 0;
    bool flag=1;
    ll ans=0;
    //ans=back2(x+1,A,B,conts);
    rep(i,conts[x]+1){
        rep(j,31){
            if(A[j]-i*B[x].ff[j]<0) flag=0;
        }
        if(!flag) break;
        //cerr<<"hago "<<i<<" veces "<<B[x].ss<<"\n";
        rep(j,31)
            A[j]-=i*B[x].ff[j];
        ans=max(back2(x+1,A,B,conts)+i*B[x].ss,ans);
        rep(j,31)
            A[j]+=i*B[x].ff[j];
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        ll n; cin>>n>>m;
        vector<pvi> stick(n,pvi());
        rep(i,n){
            int k, b; cin>>k;
            stick[i].ff.assign(101,0);
            int aux;
            rep(j,k) { cin>>aux; stick[i].ff[--aux]++; }
            cin>>b;
            stick[i].ss=b;
        }
        vector<ll> mine(31,0);
        rep(i,m) cin>>mine[i];
        ll aux=0;
        //rep(i,n) cout<<stick[i].ss<<" "; cout<<"\n";
        for(int i=0;i<n;i++){
            ll mini=1e6;
            for(int j=0;j<31;j++){
                if(stick[i].ff[j]==0) continue;
                mini= min(mini,mine[j]/stick[i].ff[j]);
            }
            aux+=mini*stick[i].ss;
        }
        cout<<aux<<"\n";
        //rep(i,31) cerr<<mine[i]<<" "; cerr<<"\n";
        //cout<<back2(0,mine,stick,conts)<<"\n";
    }

    return 0;
}