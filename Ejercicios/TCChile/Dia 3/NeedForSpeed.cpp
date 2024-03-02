#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, t; cin>>n>>t;
    vl D(n), S(n); rep(i, n) cin>>D[i]>>S[i];
    db l = -1000000000.0, r = 1000000000.0;
    rep(i, n) l = max(l, db(-S[i]));
    rep(_, 100000) {
        db m = (l + r) * 0.5;
        db tm = 0;
        rep(i, n) tm += db(D[i]) / db(S[i] + m);
        // cout<<m<<' '<<tm<<' '<<t<<'\n';
        if(tm <= t) r = m;
        else l = m;
    }
    cout<<setprecision(9)<<fixed<<(l + r) * 0.5<<'\n';

    return 0;
}