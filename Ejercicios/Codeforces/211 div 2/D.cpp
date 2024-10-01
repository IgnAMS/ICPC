#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second

ll n, m, a;
vector<ll> B, P;

ll f(int k){
    ll aux = a, gasto = 0;
    bool oc = 1;
    rep(i, k){
        if(B[n - k + i] >= P[i]) gasto += P[i];
        else if(B[n - k + i] + aux >= P[i]) {
            gasto += B[n - k + i];
            aux -= P[i] - B[n - k + i];
        }
        else oc = 0;
        //cout<<i<<' '<<aux<<' '<<P[i] - B[n - k + i]<<'\n';
    }
    if(oc) return max(0LL, gasto - aux);
    return -1;
}


int main(){
    cin>>n>>m>>a;
    B.resize(n); rep(i,n) cin>>B[i];
    P.resize(m); rep(i,m) cin>>P[i];
    sort(P.begin(), P.end());
    sort(B.begin(), B.end());
    int aux = 0;
    rep(i, 23) aux += max(0LL, P[i] - B[n - 23 + i]);
    //cout<<aux<<'\n';
    int l = 0, r = min(n, m);
    ll ans;
    while(l < r){
        int k = (l + r)/2;
        ans = f(k);
        cerr<<l<<' '<<r<<' '<<k<<' '<<ans<<'\n';
        if(ans == -1) r = k;
        else l = k + 1;
    }
    cerr<<l<<' '<<r<<'\n';
    // cout<<(l + r) / 2<<' '<<f((l + r) / 2)<<'\n';
    if(f((l + r) / 2) == -1) cout<<(l + r) / 2 - 1<<' '<<f((l + r) / 2 - 1)<<'\n';
    else cout<<(l + r) / 2 <<' '<< f((l + r) / 2)<<'\n';



    return 0;
}