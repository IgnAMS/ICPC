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
    int t; cin>>t;
    while(t--) {
        ll n, m, _; cin>>n>>m>>_;
        vector<pll> L(n);
        rep(i, n) cin>>L[i].ff>>L[i].ss;
        
        vector<pll> X(m);
        rep(i, m) cin>>X[i].ff>>X[i].ss;

        multiset<pll> S;
        ll ind = 0, jump = 1, ans = 0;
        bool pos = 1;
        rep(i, n) {
            while(ind < m and X[ind].ff <= L[i].ff) S.insert({X[ind].ss, X[ind].ff}), ind++;
            
            while(!S.empty() and jump < L[i].ss - L[i].ff + 2) {
                jump += S.rbegin()->ff;
                ans++;
                S.erase(S.find(*S.rbegin()));
            }
            
            if(S.empty() and jump < L[i].ss - L[i].ff + 2) {
                pos = 0;
                break;
            }
        }
        if(!pos) cout<<"-1\n";
        else cout<<ans<<'\n';
    }

    return 0;
}