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

const int mxN = 2e5+5;
vl G[mxN];
ll P[mxN], A[mxN];
ll ans = 0;

void solve(ll u) {
    ll mn = 1e10;
    for(auto v: G[u]) {
        solve(v);
        mn = min(A[v], mn);
    }

    // if(A[u] >= mn and u != 0) {
    //     ll prev = A[u];
    //     ll k = (A[u] - mn) / 2;
    //     A[u] = min(A[u] - k, mn + k);
    // }
    if(mn != 1e10 and mn > A[u] and u != 0) {
        ll k = (mn - A[u]) / 2;
        ll prev = A[u];
        A[u] = min(A[u] + k, mn - k);
    }
    else if(mn != 1e10 and mn < A[u] and u != 0) A[u] = mn;  
    else if(u == 0) {
        A[u] += mn;
    }
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        rep(i, n) cin>>A[i];
        rep(i, n) G[i].clear();
        rep(i, n - 1) {
            int p; cin>>p, p--;
            P[i] = p;
            G[p].pb(i + 1);
        }
        // cout<<n<<'\n';
        // rep(i, n) cout<<A[i]<<' '; cout<<'\n';
        // rep(i, n - 1) cout<<P[i] + 1<<' '; cout<<'\n';
        

        solve(0);
        cout<<A[0]<<'\n';
    }





    return 0;
}