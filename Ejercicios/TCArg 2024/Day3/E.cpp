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

struct RBS {
    ll ans, inside, curr, limits, prefix;
    RBS(ll ans, ll inside, ll curr, ll limits, ll prefix): 
        ans(ans), inside(inside), curr(curr), limits(limits), prefix(prefix) {}
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<RBS> X;
    ll ans = 0;
    rep(i, n) {
        string s; cin>>s;
        ll best = 0, inside = 0, limits = 0, curr = 0;
        ll prefix = 0, greater = 1;
        char active = s[0];
        for(auto c: s) {
            // if(active == '(' and c == ')') best++;
            if(active == ')' and c == '(') inside++;
            if(curr < 0) greater = 0;
            active = c;
            curr += (c == ')'? -1: 1);
            limits = max(limits, -curr);
            if(curr == 0 and greater) prefix++;
        }
        
        X.pb(RBS(best, inside, curr, limits, prefix));
        // cout<<ans<<' '<<inside<<' '<<curr<<' '<<limits<<'\n';
    }
    sort(X.begin(), X.end(), [](const RBS& a, const RBS& b){
        return a.curr > b.curr;
    });
    ll ans = 0;
    for(auto rbs: X) {
        cout<<rbs.ans<<' '<<rbs.inside<<' '<<rbs.curr<<' '<<rbs.limits<<' '<<rbs.prefix<<'\n';
    
    }





    return 0;
}