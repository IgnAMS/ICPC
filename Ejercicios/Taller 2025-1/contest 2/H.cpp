#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll k, n; cin>>n>>k;
    vl A(n); rep(i, n) cin>>A[i];
    
    ll l = 0, r = 2e5 + 1;
    while(l < r) {
        ll m = (l + r + 1) / 2;
        ll X[n + 1];
        X[0] = 0;
        rep(i, n) X[i + 1] = X[i] + (A[i] >= m? 1LL: -1LL);
        // quiero ver si existe
        ll mn = 1e6;
        bool pos = 0;
        rep(i, n + 1) {
            // cout<<i<<' '<<X[i]<<' '<<mn<<' '<<X[i] - mn<<'\n';
            if(i >= k) mn = min(mn, X[i - k]);
            if(0 < X[i] - mn) pos = 1;
        }
        // cout<<l<<' '<<r<<' '<<pos<<'\n';
        if(!pos) r = m - 1;
        else l = m;
    }
    cout<<l<<'\n';


    return 0;
}