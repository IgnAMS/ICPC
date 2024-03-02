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
// g++ -O2 J.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<pll> X(n);
    rep(i, n) {
        cin>>X[i].ff>>X[i].ss;
    }
    sort(X.begin(), X.end(), [&](const pll a, const pll b) {
        return a.ff > b.ff; 
    });

    // for(auto u: X) cout<<u.ff<<' '; cout<<'\n';
    pll ans = {0, 1};
    pll last = X[0];

    for(int i = 1; i < n; i++) {
        // lo alcanza
        if(X[i].ss > last.ss) {
            // db curr = db(last.ff - X[i].ff) / db(X[i].ss - last.ss);
            if((last.ff - X[i].ff) * ans.ss > ans.ff * (X[i].ss - last.ss)) {
                ans = {last.ff - X[i].ff, X[i].ss - last.ss};
            }
        }
        // X[i].ss <= last.ss guardo el mas lento que este mas a la izquierda
        else last = X[i];
    }

    cout<<setprecision(14)<<fixed<<db(ans.ff) / db(ans.ss)<<'\n';

    return 0;
}