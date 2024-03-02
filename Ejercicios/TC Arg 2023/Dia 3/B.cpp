#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i<(int)n; ++i)
#define ll long long
#define vl vector<ll>
#define ff first
#define ss second
#define pb push_back

const int mxN = 3e5+5;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<pair<string, int>> Ops(n);
    rep(i, n) {
        cin>>Ops[i].ff;
        if(Ops[i].ff != "removeMin") cin>>Ops[i].ss;
        else Ops[i].ss = -1;
    }
    vector<pair<string, int>> ans;
    multiset<ll> S;
    for(auto u : Ops) {
        string op = u.ff; int x = u.ss;
        if(op == "insert") {
            S.insert(x);
        }
        if(op == "removeMin") {
            if(S.empty()) {
                ans.pb({"insert", 1e9});
                S.insert(1e9);
            }
            S.erase(S.find(*S.begin()));
        }
        if(op == "getMin") {
            while(!S.empty() and x > *S.begin()) {
                ans.pb({"removeMin", -1});
                S.erase(S.find(*S.begin()));
            }
            if(S.empty() or *S.begin() > x) {
                ans.pb({"insert", x});
                S.insert(x);
            }
        }
        ans.pb({op, x});
    }
    cout<<ans.size()<<'\n';
    for(auto u: ans) {
        string op = u.ff; int x = u.ss;
        cout<<op;
        if(op != "removeMin") cout<<" "<<x<<'\n';
        else cout<<'\n';    
    }


    return 0;
}