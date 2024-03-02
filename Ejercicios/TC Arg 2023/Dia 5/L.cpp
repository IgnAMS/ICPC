#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define rep(i, n) for(int i = 0; i < n; i++)


int main() {
    set<ll> S;
    rep(i, 2000) S.insert(i * i);
    
    ll x, y; cin>>x>>y;
    if(S.count(x * x + y * y) or y == 0 or x == 0) {
        cout<<"black\n";
        return 0;
    }

    ll l = 0, r = 1e4;
    while(l < r) {
        ll m = (l + r) / 2;
        if(x * x + y * y <= m * m) r = m;
        else l = m + 1;
    }
    if(x * y >= 0) {
        if(l % 2 == 1) cout<<"black\n";
        else cout<<"white\n";
    }
    else {
        if(l % 2 == 1) cout<<"white\n";
        else cout<<"black\n";
    }

    return 0;
}