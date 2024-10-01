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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, q; cin>>n>>q;
    vl A(n); rep(i, n) cin>>A[i];
    // cout<<(1LL<<61)<<'\n';

    ll Acc[n][62];
    rep(i, n) {
        Acc[i][0] = 1 & A[i];
        for(ll j = 1; j < 62; j++) {
            Acc[i][j] = Acc[i][j - 1] + (A[i] & (1LL<<j));
        }
    }

    rep(i, q) {
        ll k; cin>>k;
        ll ans = 0;
        ll currops = 0;
        vl E(n, 1);
        for(ll b = 59; b >= 0; b--) {
            
            ll ops = 0;
            bool flag = 0;
            rep(i, n) {
                ll prev = ops;
                ll ops_i = 0;
                if(E[i]) ops_i += max(0LL, (1LL<<b) - Acc[i][b]);
                else ops_i += (1LL<<b);
                // if(b <= 4) cout<<"el costo para "<<(1LL<<b)<<" para "<<i<<" es de "<<ops - prev<<'\n';
                if(ops > k - ops_i) {
                    flag = 1;
                    break;
                }

                ops += ops_i;
                if(currops + ops > k) {
                    flag = 1;
                    break;
                }
            }
            if(flag) continue;

            if(currops + ops <= k) {
                // cout<<"anado a la base a "<<(1LL<<b)<<" con un costo de "<<ops<<'\n';
                ans += (1LL<<b);
                currops += ops;
                rep(i, n) if(!((1LL<<b) & A[i])) E[i] = 0;
            }
        }
        cout<<ans<<'\n';
    }





    return 0;
}