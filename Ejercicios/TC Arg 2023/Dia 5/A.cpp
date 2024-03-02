#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define rep(i, n) for(int i = 0; i < n; i++)

const int mxN = 2e5+5;

ll n, m, d;
int ans[mxN];
int main() {
    cin >> n >> m >> d;
    set<pair<ll, int>> s;
    rep(i, n){
        ll x;
        cin >> x;
        s.insert({x, i});
    }
    int cc = 0;
    while(s.size()){
        ll f = -1e10;
        cc++;
        while(true){
            auto it = s.lower_bound({f+d+1, 0});
            if(it == s.end()){
                break;
            }
            f = it -> first;
            ans[it -> second] = cc;
            s.erase({it->first, it->second});
        }
    }
    cout << cc << "\n";
    rep(i, n){
        cout << ans[i] << " ";
    }
}