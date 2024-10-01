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
    // cout<<(1LL<<60)<<'\n';

    while(t--) {
        ll n, m; cin>>n>>m;
        ll first = 0;
        ll ans = 0;
        ll last = -1;
        for(int b = 60; b >= 0; b--) {
            ll dist = (1LL<<b) - n;
            if(first) {
                dist = min(dist, n + 1);
            }
            // cout<<b<<' '<<dist<<' '<<n<<'\n';
            if(dist <= m) ans += (1LL<<b);
            
            if(n & (1LL<<b)) {
                last = b;
                first = 1;
                n -= (1LL<<b);
            }
        }
        cout<<ans<<'\n';
    }
    





    return 0;
}