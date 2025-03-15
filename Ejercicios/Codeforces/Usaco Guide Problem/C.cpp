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
    int n; cin>>n;
    ll A[n], B[n], Pos[n + 1]; 
    rep(i, n) cin>>A[i];
    rep(i, n) cin>>B[i], Pos[B[i]] = i;

    rep(i, n) A[i] = Pos[A[i]];
    // rep(i, n) cout<<A[i]<<' '; cout<<'\n';
    
    vl X(n + 1, n + 2);
    vl Y(n, -1);
    ll ans = 0;
    rep(i, n) {
        ll ind = lower_bound(X.begin(), X.end(), A[i]) - X.begin();
        X[ind] = A[i];
        Y[A[i]] = ind? X[ind - 1]: -1;
        ans = max(ans, ind + 1);
    }
    cout<<ans<<'\n';

    // ll curr = X[ans - 1];
    // vl Ans;
    // while(curr != -1) {
    //     Ans.pb(B[curr]);
    //     curr = Y[curr];
    // }
    // reverse(Ans.begin(), Ans.end());
    // for(auto u: Ans) cout<<u<<' '; cout<<'\n';



    return 0;
}