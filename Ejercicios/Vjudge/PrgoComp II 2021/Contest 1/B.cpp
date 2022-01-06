#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll,ll> ii;
typedef double db;
#define ff first
#define ss second



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, q; cin>>n>>q;
    deque<ll> A; rep(i, n) { int h; cin>>h; A.push_back(h); }
    
    ll maxind, maxi = -1; 
    rep(i, n) if(maxi < A[i]) maxind = i, maxi = A[i];
    vector<ii> ans; // para todo i < maxind
    rep(i, maxind){
        int a = A[0], b = A[1];
        ans.push_back({a, b});
        A.pop_front(); A.pop_front();
        A.push_front(max(a, b));
        A.push_back(min(a, b));
    }
    //rep(i, n) cout<<A[i]<<' '; cout<<'\n';
    rep(_, q){
        ll m; cin>>m;
        if(m-1 < maxind) cout<<ans[m-1].ff<<' '<<ans[m-1].ss<<'\n';
        else cout<<A[0]<<' '<<A[(m - maxind - 1)%(n-1) + 1]<<'\n';
    } 





    return 0;
}