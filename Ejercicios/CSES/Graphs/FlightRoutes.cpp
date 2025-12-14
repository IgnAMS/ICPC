#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<iostream>
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
// g++ -std=c++17 A.cpp -o a && ./a <input.txt> output.txt   
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

const int mxN = 1e5+5;
int n, m, k;
vector<pll> G[mxN];
const ll INF = 1e17;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    rep(i, m) {
        ll u, v, w; cin>>u>>v>>w; u--, v--;
        G[u].pb({v, w});
    }

    vl Ans;
    vl Cont(n, 0);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 0});
    while(!pq.empty() and Cont[n-1] < k) {
        auto [d, u] = pq.top(); pq.pop();
        if(u == n - 1) Ans.pb(d);
        Cont[u]++;
        if(Cont[u] > k) continue;
        for(auto [v, w]: G[u]) {
            pq.push({d + w, v});
        }
    }
    rep(i, k) cout<<Ans[i]<<" "; cout<<"\n";

    return 0;
}