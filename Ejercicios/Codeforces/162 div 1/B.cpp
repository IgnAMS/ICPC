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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    vl div[100005];
    vl P(100005, 1);
    for(int i = 2; i <= 100000; i++) {
        if(!P[i]) continue;
        for(int j = i; j <= 100000; j += i) {
            P[j] = 0;
            div[j].pb(i);
        }
    }
    
    int n; cin>>n;
    vl A(n); rep(i, n) cin>>A[i];

    vl Ans(100005, 1);
    vl X(100005, 0);
    ll ans = 1;
    rep(i, n) {
        for(auto d: div[A[i]]) {
            if(X[d]) Ans[A[i]] = max(Ans[A[i]], Ans[d] + 1);
        }
        for(auto d: div[A[i]]) {
            Ans[d] = max(Ans[d], Ans[A[i]]);
            X[d] = 1;
        }
        ans = max(ans, Ans[A[i]]);
    }
    cout<<ans<<'\n';


    return 0;
}