#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(ll i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    vi A(n); // bits que puede tener
    vi B(n); // bits que debe tener
    ll inf = (1LL<<30) - 1;
    rep(i, n) A[i] = inf;
    vector<vi> E(q, vi(3));
    rep(i, q) cin>>E[i][0]>>E[i][1]>>E[i][2];
    rep(i, q) E[i][0]--, E[i][1]--;
    for(auto& e: E) {
        ll i, j, x; i = e[0], j = e[1], x = e[2];
        if(i == j) B[i] = x;
        A[i] = (A[i] & x);
        A[j] = (A[j] & x);
    }
    for(auto& e: E) {
        ll i, j, x; i = e[0], j = e[1], x = e[2];
        ll x1 = x & (inf ^ A[i]); // bits que no son de A[i]
        ll x2 = x & (inf ^ A[j]); // bits que no son de A[j]
        B[i] |= x2;
        B[j] |= x1;
        A[i] = (A[i] & x);
        A[j] = (A[j] & x);
    }
    
    vi Ans(n, 0);
    rep(i, n) {
        Ans[i] = B[i];
        
        
    }






    return 0;
}