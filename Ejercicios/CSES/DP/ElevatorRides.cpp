#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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

const ll mxN = 1<<20;
ll C[mxN];
pll DP[mxN];
ll n, x;
ll W[mxN];

// ll dp(ll w, ll mask) {    
//     // if(mask == (1<<n) - 1) return 0;
//     if(mask == 0) return 0;
//     if(DP[mask] != -1) return DP[mask];
//     
//     // cout<<mask<<'\n';
// 
// 
//     DP[mask] = 21;
// 
//     
//     // for(int submask = mask; submask; submask = (submask - 1) & mask) { 
//     //     if(C[submask] <= x) DP[mask] = min(DP[mask], dp(mask ^ submask) + 1);
//     // }
// 
//     // vl A;
//     // rep(i, n) if(!(mask & (1<<i))) A.pb(i);
//     // repx(mask2, 1, 1<<int(A.size())) {
//     //     ll cost = 0;
//     //     ll new_mask = mask;
//     //     rep(i, A.size()) if(1<<i & mask2) cost += W[A[i]], new_mask += 1<<A[i];
//     //     if(cost <= x) DP[mask] = min(DP[mask], dp(new_mask) + 1); 
//     // }
// 
//     // cout<<mask<<' '<<DP[mask]<<'\n';
//     return DP[mask];
// }


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>x;
    rep(i, n) cin>>W[i];
    // rep(i, mxN) DP[i] = -1;

    rep(mask, mxN) {
        ll c = 0;
        rep(i, n) if(mask & (1<<i)) c += W[i];
        C[mask] = c;
    }

    DP[0] = {1, 0};
    repx(mask, 1, 1<<n) {
        DP[mask] = {21, 0};
        rep(i, n) if(mask & (1<<i)){
            ll k, w; tie(k, w) = DP[mask ^ (1<<i)];
            if(w + W[i] > x) {
                k += 1;
                w = min(W[i], w);
            }
            else {
                w += W[i];
            }
            DP[mask] = min(DP[mask], {k, w});
        }
    }

    cout<<DP[(1<<n) - 1].ff<<'\n';
    // cout<<dp(0, (1<<n) - 1)<<'\n';

    return 0;
}