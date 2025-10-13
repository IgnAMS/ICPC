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
    int n; cin>>n;
    ll P[2 * n - 1]; 
    rep(i, n) cin>>P[i];
    rep(i, n - 1) P[n + i] = P[i];

    map<ll, vector<pll>> mp;
    ll ans = 0;
    rep(i, 2 * n - 1) {
        if(!mp.count(i + P[i])) mp[i + P[i]] = {};
        mp[i + P[i]].pb({i, P[i]});
    }
    
    rep(i, n) {
        auto upper = upper_bound(mp[i + P[i]].begin(), mp[i + P[i]].end(), pll(i + n, 0));
        if(upper != mp[i + P[i]].end()) upper = prev(upper);

        auto lower = lower_bound(mp[i + P[i]].begin(), mp[i + P[i]].end(), pll(1LL * i + 1, 0));
        ll curr = upper - lower;
        // cout<<i<<' '<<curr<<'\n';
        ans += curr;
    }

    cout<<2 * ans + n<<'\n';

    // ll ans2 = 0;
    // rep(i, n) {
    //     ll cont = 0;
    //     repx(j, i + 1, i + n) if(i != j and i - j == P[j] - P[i]) cont++;
    //     cout<<i<<' '<<cont<<'\n';
    //     ans2 += cont;
    // }
    // cout<<ans2<<'\n';

    return 0;
}