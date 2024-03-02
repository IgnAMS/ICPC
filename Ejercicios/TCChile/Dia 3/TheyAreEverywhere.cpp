#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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
    string s; cin>>s;

    map<char, ll> mp;
    set<char> S;
    rep(i, n) S.insert(s[i]);
    ll i = 0;
    ll ans = n;
    rep(j, n) {
        if(!mp.count(s[j])) mp[s[j]] = 0;
        mp[s[j]]++;
        while(mp[s[i]] > 1) mp[s[i]]--, i++;
        if(mp.size() == S.size()) ans = min(ans, j - i + 1); 
    }
    cout<<ans<<'\n';

    return 0;
}