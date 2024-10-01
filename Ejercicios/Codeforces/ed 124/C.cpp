#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt


ll best(int a, set<ii>& S) {
    ll ans = 1e15;
    auto it = S.lower_bound({a, 0}); 
    if(it != S.end()) ans = min(ans, abs(a - (*it).ff)); // primero mayor o igual
    if(it != S.begin()) ans = min(ans,  abs(a - (*prev(it)).ff)); // primero menor
    return ans;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll n; cin>>n;
        vi A(n); rep(i, n) cin>>A[i];
        vi B(n); rep(i, n) cin>>B[i];
        set<ii> Sa, Sb;
        rep(i, n) Sa.insert({A[i], i});
        rep(i, n) Sb.insert({B[i], i});
        // { (a1, b1), (an, bn) }, {(a1, bn), (an, bn) }
        ll ans = 1e15;
        // best a1
        ll a1 = best(A[0], Sb);
        ll an = best(A[n - 1], Sb);
        ll b1 = best(B[0], Sa);
        ll bn = best(B[n - 1], Sa);
        // cout<<a1<<' '<<an<<' '<<b1<<' '<<bn<<'\n';
        vi L = {
            abs(A[0] - B[0]) + abs(A[n - 1] - B[n - 1]),
            abs(A[0] - B[n - 1]) + abs(A[n - 1] - B[0]),
            abs(A[0] - B[0]) + an + bn, 
            abs(A[0] - B[n - 1]) + an + b1,
            abs(A[n - 1] - B[0]) + a1 + bn,
            abs(A[n - 1] - B[n - 1]) + a1 + b1,
            a1 + b1 + an + bn
        };
        // for(auto u: L) cout<<u<<'\n';
        ans = min({
            abs(A[0] - B[0]) + abs(A[n - 1] - B[n - 1]),
            abs(A[0] - B[n - 1]) + abs(A[n - 1] - B[0]), 
            abs(A[0] - B[0]) + an + bn, 
            abs(A[0] - B[n - 1]) + an + b1,
            abs(A[n - 1] - B[0]) + a1 + bn,
            abs(A[n - 1] - B[n - 1]) + a1 + b1,
            a1 + b1 + an + bn
        });
        cout<<ans<<'\n';
    }

    return 0;
}