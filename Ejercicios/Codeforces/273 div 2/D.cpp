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

// DP[i][r][g] = DP[i - 1][r + i][g] + DP[i - 1][r][g + i]

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll R, G; cin>>R>>G;
    
    
    vl DP(R + 1, 0), DP2(R + 1, 0);
    DP[0] = 1;
    const ll MOD = 1e9+7;
    ll ans = 0;

    for(ll i = 1; i <= 1000; i++) {
        bool oc = 0;
        for(ll r = min(R, i * (i + 1) / 2); r >= 0; r--) {
            int g = G - max(0LL, i * (i + 1) / 2 - (R - r));
            if(r + G >= i * (i + 1) / 2) oc = 1;

            if(r >= i) DP2[r] = DP[r - i] + DP[r];
            else DP2[r] = DP[r];

            DP2[r] %= MOD;
        }

        if(!oc) {
            ans = 0;
            for(ll r = min(R, i * (i - 1) / 2); r >= 0; r--) {
                if(r + G >= i * (i - 1) / 2) {
                    ans += DP[r];
                    while(ans >= MOD) ans -= MOD;
                }
            }
            break;
        }
        rep(r, R + 1) DP[r] = DP2[r];
        DP2.assign(R + 1, 0);
    }
    cout<<ans<<'\n';


    return 0;
}