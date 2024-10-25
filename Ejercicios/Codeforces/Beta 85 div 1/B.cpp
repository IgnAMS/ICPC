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
    const int mxN = 1e5+5;
    vl div[mxN];
    for(int i = 1; i < mxN; i++) {
        for(int j = i; j < mxN; j += i) {
            div[j].pb(i);
        }
    }

    int n; cin>>n;
    vl A(mxN, 0);
    rep(i, n) {
        int x, y; cin>>x>>y;
        ll ans = 0;
        for(auto u: div[x]) {
            if(A[u] < i - y + 1) ans++;
            A[u] = i + 1;
        }
        cout<<ans<<'\n';

    }

    return 0;
}