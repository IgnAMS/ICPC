#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(ll i=a; i<b; i++)
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
    const ll mxN = 2e5 + 5;
    vector<vl> Div(mxN, vl());
    for(ll i = 1; i < mxN; i++) {
        for(ll j = i; j < mxN; j += i) {
            Div[j].pb(i);
        }
    }

    ll n; cin>>n;
    ll A[n]; 
    vl F(mxN, 0);
    
    ll ans = 0;
    rep(i, n) {
        cin>>A[i];
        F[A[i]]++;
        if(A[i] == 0) ans += n - 1;
    }

    ll cont = 0;
    for(ll i = 1; i < mxN; i++) {
        set<ll> S;
        rep(j1, Div[i].size()) repx(j2, j1 + 1, Div[i].size()) {
            ll prev = ans;
            ll d = Div[i][j1] * Div[i][j2];
            if(d > i or i * i / d >= mxN) continue;
            if(S.count(d)) continue;
            // cout<<d<<' '<<i * i / d<<'\n';
            if(d == i) ans += F[d] * (F[d] - 1) / 2;
            else ans += F[d] * F[i * i / d];
            S.insert(d);
            // if(ans - prev != 0) cout<<d<<' '<<i * i / d<<' '<<ans - prev<<'\n';
        }
        for(auto d: Div[i]) if(i * i / (d * d) < mxN and d * d < mxN and d * d < i) {
            if(S.count(d * d)) continue;
            ll prev = ans;
            ans += F[d * d] * F[i * i / (d * d)];
            // if(ans > prev) cout<<d * d <<' '<<i * i / (d * d)<<' '<<ans - prev<<'\n';
        }
    }
    cout<<ans<<'\n';

    return 0;
}