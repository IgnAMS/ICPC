#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long  ll;

int n;
vector<ll> H;
vector<ll> C;

ll cost(ll x){
    ll sum = 0;
    rep(i, n) sum += C[i] * abs(x - H[i]);
    return sum;
}

int min_search(int l, int r) {
    while (l < r) {
        int m = (l+r)/2;
        ll slope = cost(m+1) - cost(m);
        if (slope >= 0) r = m;
        else l = m+1;
    }
    return cost(l);
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>n; H.resize(n); C.resize(n);
        ll mini=1e5, maxi=0;
        rep(i, n) { cin>>H[i]; mini=min(mini, H[i]), maxi=max(H[i], maxi); }
        rep(i, n) cin>>C[i];

        cout<<min_search(mini, maxi)<<"\n";
    }

    return 0;
}