#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    string s; cin>>s;
    set<char> S;
    for(auto u: s) S.insert(u);
    set<ll> Sint;
    map<char, deque<int>> mp;
    ll ans = 100000;
    rep(i, n) {
        if(!mp.count(s[i])) mp[s[i]] = {};
        mp[s[i]].push_back(i);
        Sint.insert(i);
        while(mp[s[i]].size() > 1) {
            Sint.erase(mp[s[i]][0]);
            mp[s[i]].pop_front();
        }
        if(mp.size() == S.size()) ans = min(ans, i - *Sint.begin() + 1LL);
    }
    cout<<ans<<'\n';



    return 0;
}