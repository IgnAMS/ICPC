#pragma GCC optimize("Ofast")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2")
#include<iostream>
#include<vector>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
typedef vector<int> vi;
#define ff first
#define ss second
#define pb push_back
const int mxN = 2e5 + 10;
vector<int> G[mxN];
ll DP[mxN];
int n;

ll dp(int u) {
    if(DP[u] != -1) return DP[u];
    DP[u] = 1;
    for(auto v: G[u]) DP[u] += dp(v);
    return DP[u]; 
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i, n+1) DP[i] = -1;
    rep(i, n - 1) {
        int p; cin>>p; p--;
        G[p].push_back(i+1);
    }

    rep(i, n) cout<<dp(i) - 1<<" "; cout<<"\n";

    return 0;
}
