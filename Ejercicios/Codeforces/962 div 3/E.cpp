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

const ll MOD = 1e9+7;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        string s; cin>>s;
        ll n = s.length();
        ll ans = 0;
        map<ll, ll> mp;
        mp[0] = 1;
        ll curr = 0;
        rep(i, n) {
            curr += (s[i] == '0'? 1: -1);
            // cout<<mp[curr]<<' '<<n - i<<'\n';
            ans += mp[curr] * ll(n - i);
            ans %= MOD;
            mp[curr] += i + 2;
            mp[curr] %= MOD;
        }
        cout<<ans<<'\n';
    }

    return 0;
}