#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) for(int i=0; i<n; i++);
typedef long long ll;
typedef pair<ll,ll> ii;
#define ff first
#define ss second


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    vector<ii> A(n, {0,0});
    A[0].ss;
    for(int i=0; i<n; i++) cin>>A[i].ss>>A[i].ff;
    //rep(i,n) cin>>A[i].ss>>A[i].ff;

    sort(A.begin(), A.end());

    ll j = n-1, i = 0;
    ll k = 0, ans = 0;
    while(i <= j){
        ll dif = min(max(A[i].ff - k, 0LL), A[j].ss);
        k += dif;
        A[j].ss -= dif; ans += 2 * dif;
        if(A[i].ff <= k) { k += A[i].ss; ans += A[i++].ss; }
        if(A[j].ss == 0) j--;
    }
    cout<<ans<<'\n';




    return 0;
}