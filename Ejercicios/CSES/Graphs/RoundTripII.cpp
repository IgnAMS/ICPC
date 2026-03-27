#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
#include<array>
#include<set>
#include<queue>
#include <algorithm>
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
// g++ -O2 RoundTripII.cpp && time ./a.out <input.txt> output.txt

const int mxN = 1e5+5;
int n, m;
vl G[mxN];
ll P[mxN];
ll V[mxN];
int Curr[mxN];
const ll INF = 1e17;

int s = -1, t = -1;
void dfs(int u, int p) {
    P[u] = p;
    V[u] = 1;
    Curr[u] = 1;
    for(auto v: G[u]) {
        if(V[v] and Curr[v]) s = u, t = v;
        else if(!V[v]) dfs(v, u);
    }
    Curr[u] = 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i, m) {
        int a, b; cin>>a>>b; a--, b--;
        G[a].pb(b);
    }
    rep(i, n) if(!V[i]) dfs(i, -1);
    if(s == -1) {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    vl X = {t, s};
    cerr<<"hola :)\n";
    int curr = s;
    while(curr != t and curr != -1) {
        X.pb(P[curr]);
        curr = P[curr];
    }
    cout<<X.size()<<"\n";
    reverse(X.begin(), X.end());
    for(auto u: X) cout<<u + 1<<" "; cout<<"\n"; 



    return 0;
}