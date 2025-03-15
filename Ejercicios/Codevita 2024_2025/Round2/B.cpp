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

int n, m;
vl E[51];
multiset<ll> S;
ll B[51], C[51];
ll curr = 0, ans = 0, peso = 0;
int w;

void backtrack(int i) {
    if(i == n) {
        ans = max(ans, curr);
        return;
    }
    backtrack(i + 1);
    if(!S.count(i) and peso + C[i] <= w) {
        for(auto e: E[i]) S.insert(e);
        curr += B[i];
        peso += C[i];
        backtrack(i + 1);
        curr -= B[i];
        peso -= C[i];
        for(auto e: E[i]) S.erase(S.find(e));
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m; // <= 50
    map<string, int> mp;
    rep(i, n) {
        string s; cin>>s;
        mp[s] = mp.size();
        ll benefit = 0;
        for(auto c: s) benefit += (c - 'a') + 1;
        B[i] = benefit;
    }
    rep(i, n) cin>>C[i];

    rep(i, m) {
        string s1, s2; cin>>s1>>s2;
        E[mp[s1]].pb(mp[s2]);
        E[mp[s2]].pb(mp[s1]);
        // cout<<mp[s1]<<' '<<mp[s2]<<'\n';
    }

    cin>>w; // <= 500


    backtrack(0);
    cout<<ans<<'\n';

    return 0;
}