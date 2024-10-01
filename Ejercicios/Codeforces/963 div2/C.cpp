#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) repx(i,0,n)
typedef long long ll;
#define repx(i,a,b) for(ll i=a; i<b; i++)
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
    int t; cin>>t;
    while(t--) {
        ll n, k; cin>>n>>k;
        vl A(n);
        ll mx = 0;
        vl Open(2 * k, 0), Closed(2 * k, 0);
        rep(i, n) {
            cin>>A[i];
            mx = max(mx, A[i]);
            ll x = A[i] % (2 * k);
            if(x + k == 2 * k) {
                Open[x]++;
            } 
            else if(x + k > 2 * k) {
                Open[0]++;
                Closed[(x + k) % (2 * k)]++;
                Open[x]++;
            }
            else if(x + k < 2 * k) {
                Open[x]++;
                Closed[x + k]++;
            }
        }
        ll curr = 0;
        ll ans = 1e15;
        rep(i, 2 * k) {
            curr += Open[i] - Closed[i];
            // cout<<i<<' '<<curr<<'\n';
            if(curr == n) {
                // mx % (2 * k) > i  -> debo dar la vuelta completa ;c
                if(mx % (2 * k) > i) ans = min(ans, mx + i + (2 * k - (mx % (2 * k))));
                // mx % (2 * k) <= i -> No doy la vuelta completa y completo lo que me falta :) 
                else ans = min(ans, mx + i - (mx % (2 * k)));
            }
        }
        if(ans == 1e15) cout<<"-1\n";
        else cout<<ans<<'\n';
    }


    return 0;
}