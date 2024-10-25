#include<bits/stdc++.h>
using namespace std;

#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
typedef long long ll;
typedef pair<ll, ll> pll;



int main() {    
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    map<string, ll> mp;
    string ans = "uh-oh";
    rep(i, n) {
        string s; cin>>s;
        if(!mp.count(s)) mp[s] = 0;
        mp[s]++;
        if(mp[s] > n / 2) ans = s; 
    }
    cout<<ans<<'\n';

    return 0;
}

