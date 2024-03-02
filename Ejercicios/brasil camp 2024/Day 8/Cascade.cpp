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


const int mxN = 1e5+5;
const int mxnum = 1000005;
ll C[mxN], P[mxN], K[mxN];

ll M = 1e9+7;

ll binpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}

ll minv(ll a) { return binpow(a, M - 2); }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i, n) cin>>C[i];
    rep(i, n) cin>>P[i];
    rep(i, n) cin>>K[i];
    
    vector<vl> Cascade(mxnum, vl()); 
    vector<vl> NotCascade(mxnum, vl()); 
    rep(i, n) {
        if(K[i]) Cascade[C[i]].pb(P[i]);
        else NotCascade[C[i]].pb(P[i]);
    }

    ll ans = 0, acc = 0, cont = 0;
    rep(c, mxnum) {
        ll newacc = 0;
        for(auto u: Cascade[c]) {
            newacc += (u + (acc * minv(cont) % M)) % M;
            newacc %= M;
        }
        acc += newacc;
        acc %= M;
        for(auto u: NotCascade[c]) {
            acc += u;
            acc %= M;
        }
        cont += Cascade[c].size() + NotCascade[c].size();
    }
    ans += (acc * minv(cont) % M);
    ans %= M;
    cout<<ans<<'\n';

    return 0;
}