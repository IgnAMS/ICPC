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
    int n, k, m; cin>>n>>k>>m;
    map<string, ll> mp;
    string S[n];
    rep(i, n) {
        cin>>S[i];
        mp[S[i]] = i;
    }
    ll Costs[n];
    rep(i, n) {
        cin>>Costs[i];
    } 

    ll rep[k];
    ll group[n];
    rep(i, k) {
        int x; cin>>x;
        rep[i] = -1;
        rep(j, x) {
            ll y; cin>>y; y--;
            group[y] = i;
            if(rep[i] == -1) rep[i] = y;
            else if(Costs[rep[i]] > Costs[y]) rep[i] = y;
        }
    }
    // rep(i, k) cout<<rep[i]<<' '; cout<<'\n';
    ll ans = 0;
    rep(i, m) {
        string s; cin>>s;
        // cout<<s<<' '<<S[rep[group[mp[s]]]]<<' '<<rep[group[mp[s]]]<<' '<<group[mp[s]]<<' '<<mp[s]<<'\n';
        ans += Costs[rep[group[mp[s]]]];
    }
    cout<<ans<<'\n';





    return 0;
}