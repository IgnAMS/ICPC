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

// 500 * 10^9 ~ 5e12
ll INF = 1e18; // 10^9 * 10^3


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, g; cin>>n>>g;
    ll T[n]; rep(i, n) cin>>T[i];
    ll Acc[n + 1]; 
    Acc[0] = 0;
    rep(i, n) Acc[i + 1] = Acc[i] + T[i];
    
    vl DP(n + 1, 0), DP2(n + 1, -INF);
    ll ans = 0;
    repx(i, 1, 505) {
        repx(j, i, n + 1) {
            DP2[j] = max({
                DP2[j], 
                DP[j - i] + g - (Acc[j] - Acc[j - i]),
                DP2[j - 1]
            });
            ans = max(ans, DP2[j]);
        }
        rep(j, n + 1) {
            DP[j] = DP2[j];
            DP2[j] = -INF;
        }
        // rep(j, n + 1) cout<<DP[j]<<' '; cout<<'\n';
    }
    cout<<ans<<'\n';



    return 0;
}