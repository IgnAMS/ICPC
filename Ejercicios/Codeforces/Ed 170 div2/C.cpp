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
        int n, k; cin>>n>>k;
        map<ll, ll> mp;
        rep(i, n) {
            ll x; cin>>x;
            if(!mp.count(x)) mp[x] = 0;
            mp[x]++;   
        }

        set<ll> S;
        ll ans = 0, curr = 0;
        for(auto [x, y]: mp) {
            if(!S.empty() and x != *S.rbegin() + 1) {
                while(!S.empty() and *S.begin() < x) {
                    curr -= mp[*S.begin()];
                    S.erase(*S.begin());
                }
            }
            S.insert(x);
            curr += y;
            while(*S.begin() <= x - k) {
                curr -= mp[*S.begin()];
                S.erase(*S.begin());
            }
            ans = max(ans, curr);
        }
        cout<<ans<<'\n';
    }



    return 0;
}