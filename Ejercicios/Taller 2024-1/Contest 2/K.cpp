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
    string s; cin>>s;
    int n = s.length();
    vl X;
    char last = s[0];
    rep(i, n) {
        if(s[i] != last) X.pb(2 * i + 1);
        last = s[i];
    }
    ll sign = (s[0] == 'H'? 1: -1);
    vl ans(1);
    ans[0] = sign;
    rep(i, X.size()) {
        vl ans2(i + 2, 0);
        rep(j, i + 2) {
            if(j == 0) ans2[j] = -ans[j] * X[i];
            else if(j <= i) ans2[j] = ans[j - 1] - ans[j] * X[i];
            else ans2[j] = ans[j - 1];
        }
        ans = ans2;
    }

    reverse(ans.begin(), ans.end());
    if((int(ans.size()) & 1) == 0) {
        for(auto& u: ans) u = -u;
    }
    
    cout<<ans.size() - 1<<'\n';
    for(auto u: ans) cout<<u<<' '; cout<<'\n';




    return 0;
}