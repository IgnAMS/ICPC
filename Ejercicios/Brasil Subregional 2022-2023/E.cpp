#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define rep(i, n) for(int i = 0; i<(int)n; ++i)
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define ff first
#define ss second


// #pragma GCC target("avx,avx2,fma") // could make sigill runtime error

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vl A(n); rep(i, n) cin>>A[i];
    multiset<pll> S;
    rep(i, n) S.insert({A[i], i});
    map<ll, set<ll>> mp;
    rep(i, n) mp[A[i]].insert(i);
    ll ans = 0; 
    while(!S.empty()) {
        ans++;
        pll x = *S.rbegin();
        vector<pll> E = {x};
        pll s = x;
        while(mp[s.ff - 1].lower_bound(s.ss) != mp[s.ff-1].end()) {
            ll nw = *mp[s.ff - 1].lower_bound(s.ss);
            s = {s.ff - 1, nw};
            E.push_back(s);
        }
        for(auto u: E) {
            S.erase(u);
            mp[u.ff].erase(u.ss);
        }
    }
    cout<<ans<<'\n';



}