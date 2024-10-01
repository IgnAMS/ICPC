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


ll n, k;
vl mul[2005];
const ll MOD = 1e9+7;

ll DP[2005][2005];
ll dp(int i, int x) {
    if(i == k) return 1;
    if(DP[i][x] != -1) return DP[i][x];

    DP[i][x] = 0;
    for(auto y: mul[x]) {
        DP[i][x] += dp(i + 1, y);
        if(DP[i][x] >= MOD) DP[i][x] -= MOD;
    }
    
    // cout<<"i: "<<i<<", x: "<<x<<", DP: "<<DP[i][x]<<'\n';
    return DP[i][x];
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j += i) {
            mul[i].pb(j);
        }
    }

    memset(DP, -1, sizeof(DP));
    ll ans = dp(0, 1);
    cout<<ans<<'\n';





    return 0;
}