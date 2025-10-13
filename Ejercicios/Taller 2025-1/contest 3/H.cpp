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
    int n, k; cin>>n>>k;
    ll A[n]; rep(i, n) cin>>A[i];
    ll L[n], R[n];
    rep(i, n) L[i] = i - 1, R[i] = i + 1;
    set<pll> S; 
    rep(i, n) S.insert({A[i], i});

    ll turn = 1;
    ll Ans[n];
    while(!S.empty()) {
        auto [x, id] = *S.rbegin();
        vector<pll> E;
        E.pb({x, id});
        ll l = L[id], r = R[id];
        for(int i = 0; i < k and l >= 0; i++, l = L[l]) {
            E.pb({A[l], l});
        }
        for(int i = 0; i < k and r < n; i++, r = R[r]) {
            E.pb({A[r], r});
        }
        if(l != -1) R[l] = r;
        if(r != n) L[r] = l;
        for(auto u: E) {
            S.erase(u);
            Ans[u.ss] = turn;
        }
        turn ^= 3;
    }
    rep(i, n) cout<<Ans[i]; cout<<'\n';


    return 0;
}