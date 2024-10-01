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
    int t; cin>>t;
    map<char, ll> mp = {{'B', 1}, {'G', 2}, {'R', 4}, {'Y', 8}};
    while(t--) {
        int n, q; cin>>n>>q;
        vl Ind[17];
        ll A[n];
        rep(i, n) {
            string s; cin>>s;
            ll x = mp[s[0]] + mp[s[1]];
            A[i] = x;
            rep(j, (1<<4)) {
                if(j & x) Ind[x].pb(i);
            }
        }

        while(q--) {
            int x, y; cin>>x>>y; x--, y--;
            ll ans = 1e7;
            if(A[x] & A[y]) ans = abs(x - y);
            else {
                // no tienen ni un solo color en comun
                rep(j, 4) rep(k, 4) if((A[x] & (1<<j)) and !(A[x] & (1<<k))) {
                    // tiene a j pero no tiene a k. Notamos que A[y] & (1<<k) != 0
                    ll comb = (1<<j) + (1<<k);
                    auto it = lower_bound(Ind[comb].begin(), Ind[comb].end(), x);
                    if(it != Ind[comb].end()) ans = min(ans, abs(x - *it) + abs(y - *it));
                    if(it != Ind[comb].begin()) ans = min(ans, abs(x - *prev(it)) + abs(y - *prev(it))); 
                }
            }
            if(ans != 1e7) cout<<ans<<'\n';
            else cout<<"-1\n";
        }
    }





    return 0;
}