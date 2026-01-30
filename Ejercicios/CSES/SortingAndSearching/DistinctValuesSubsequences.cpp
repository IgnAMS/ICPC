#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<string.h>
#include<set>
#include<map>
#include<algorithm>
#include<array>
#include<unordered_map>
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
// g++ -std=c++17 MissingCoinSum.cpp -o a && ./a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 DistinctValuesSubsequences.cpp && time ./a.out <input.txt> output.txt


const int INF = 1e9+1;
const ll MOD = 1e9+7;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    map<ll, ll> mp;
    rep(i, n) {
        ll x; cin>>x;
        if(!mp.count(x)) mp[x] = 0;
        mp[x]++;
    }
    ll ans = 1;
    for(auto [_, freq]: mp) {
        ans *= (freq + 1);
        ans %= MOD;
    }
    cout<<(ans - 1 + MOD) % MOD<<"\n";
    
    return 0;
}