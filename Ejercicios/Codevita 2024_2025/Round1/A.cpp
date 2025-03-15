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
    ll init; cin>>init;
    int n; cin>>n;
    vector<pair<string, ll>> X(n);
    vector<pair<string, pll>> transactions;
    rep(i, n) {
        string s; cin>>s;
        if(s == "read" or s == "commit") X[i] = {s, 0};
        else {
            ll x; cin>>x;
            X[i] = {s, x};
            if(s == "credit") transactions.pb({"credit", {x, i}});
            if(s == "debit") transactions.pb({"debit", {x, i}});
        }
    }


    ll curr = init;
    bool commit = 0;
    vector<pll> last_commit;
    int ind_commit = 0;
    rep(i, n) {
        if(X[i].ff == "abort") {
            // cout<<X[i].ss - 1<<' '<<transactions.size()<<'\n';
            if(ind_commit <= transactions[X[i].ss - 1].ss.ss) {
                if(transactions[X[i].ss - 1].ff == "credit") curr -= transactions[X[i].ss - 1].ss.ff;
                else curr += transactions[X[i].ss - 1].ss.ff;
            }
        }
        if(X[i].ff == "credit") curr += X[i].ss;
        if(X[i].ff == "debit") curr -= X[i].ss;
        if(X[i].ff == "read") cout<<curr<<'\n';
        if(X[i].ff == "commit") last_commit.pb({i, curr}), ind_commit = i;

        if(X[i].ff == "rollback") {
            ind_commit = last_commit[X[i].ss - 1].ff;
            curr = last_commit[X[i].ss - 1].ss;
        }
    }


    return 0;
}