#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<string.h>
#include<set>
#include<map>
#include <algorithm>
#include <unordered_map>
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
// g++ -std=c++17 MissingCoinSum.cpp -o a && ./a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 MovieFestival.cpp && time ./a.out <input.txt> output.txt

const int INF = 1e9+1;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    pll A[n];
    unordered_map<ll, ll> DP;
    DP.reserve(n);
    set<ll> S = {INF};
    DP[INF] = 0;
    rep(i, n) {
        cin>>A[i].ff>>A[i].ss;
        S.insert(A[i].ff);
        // S.insert(A[i].ss);
        DP[A[i].ff] = 0;
        DP[A[i].ss] = 0;
    }
    unordered_map<ll, ll> nxt;
    nxt.reserve(n);
    rep(i, n) {
        auto it = S.lower_bound(A[i].ss);
        if(!nxt.count(A[i].ff)) nxt[A[i].ff] = INF;
        nxt[A[i].ff] = min(nxt[A[i].ff], *it);
    }
    vl I = vector<ll>(S.begin(), S.end());
    ll ans = 0;
    for(int i = I.size() - 2; i >= 0; i--) {
        DP[I[i]] = max(DP[nxt[I[i]]] + 1, DP[I[i+1]]);
        ans = max(ans, DP[I[i]]);
        // cout<<I[i]<<" "<<nxt[I[i]]<<" "<<DP[I[i]]<<"\n";
    }
    cout<<ans<<"\n";

    
    return 0;
}