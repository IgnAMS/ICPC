#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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

ll turn(pll a, pll b, pll c) {
    pll p1 = { b.ff - a.ff, b.ss - a.ss }; 
    pll p2 = { c.ff - a.ff, c.ss - a.ss };
    return abs(p1.ff * p2.ss - p1.ss * p2.ff);
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<pll> X(n); rep(i, n) cin>>X[i].ff>>X[i].ss;
    ll primer = 0, segundo = 0;
    rep(i, n) L[i] = (i - 1 + n) % n, R[i] = (i + 1) % n;
    vector<bool> V(n, 0); 
    rep(i, n - 2) {
        ll mn = 1e17, mnind = -1;
        rep(i, n) if(V[i] and turn(X[i], X[L[i]], X[R[i]]) < mn) mn = turn(X[i], X[L[i]], X[R[i]]), mnind = i;
        if(i % 2 == 0) primer += 
        R[L[i]] = L[i], L[R[i]] = L[i];
    }




    return 0;
}