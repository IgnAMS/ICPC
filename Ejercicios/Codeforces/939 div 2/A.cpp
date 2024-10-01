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
    while(t--) {
        int k, q; cin>>k>>q;
        ll mn = 100;
        ll K[k];
        rep(i, k) {
            cin>>K[i];
            mn = min(mn, K[i]);
        }

        rep(_, q) {
            ll n; cin>>n;
            ll ans = n;
            ll xd = 100;
            while(ans >= mn and xd-- >= 0) {
                ll cont = 0;
                rep(j, k) {
                    if(ans >= K[j]) cont++;
                }
                
                ans -= cont;
            }

            cout<<ans<<' ';
        }
        cout<<'\n';
    } 

    return 0;
}