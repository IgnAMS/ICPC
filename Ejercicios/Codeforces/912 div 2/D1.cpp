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
    int n, q; cin>>n>>q;
    vl A(n); rep(i, n) cin>>A[i];
    rep(i, q) {
        ll k; cin>>k;
        ll l = 0, r = 1e18+1e6+10;
        while(l < r) {
            ll m = (l + r + 1) / 2;
            ll mxbit = 0;
            rep(i, 61) if(m & (1LL<<i)) mxbit = i;
            ll base = (1LL<<(mxbit+ 1)) - 1;
            ll ops = 0;
            
            rep(i, n) {
                ll sobra = 0;
                rep(j, mxbit + 1) {
                    if(!(m & (1LL<<j)) and A[i] & (1LL<<j)) sobra += A[i] & (1LL<<j);
                    if(m & (1LL<<j) and A[i] & (1LL<< j)) sobra = 0;
                    if((m & (1LL<<j)) and !(A[i] & (1LL<<j))) {
                        // if(m <= 10) cout<<i<<" aumenta en "<<(m & (1LL<<j)) - sobra<<'\n';
                        ops += (m & (1LL<<j)) - sobra;
                        sobra = 0;
                    }
                }
            }
            // if(m <= 10) {
            //     cout<<m<<" costo "<<ops<<" operaciones\n";
            // }
            if(ops <= k) {
                l = m;
            }
            else {
                r = m - 1;
            }
        }
        cout<<l<<'\n';
    }




    return 0;
}