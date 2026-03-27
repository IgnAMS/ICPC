#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<iostream>
#include <algorithm>
#include<set>
#include<array>
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
int n, m;
vl G[mxN];
int V[mxN];
int In[mxN];
set<ll> Vis;

const ll INF = 1e17;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i, m) {
        int a, b; cin>>a>>b; a--, b--;
        G[a].pb(b);
        In[b]++;
    }
    vl X;
    rep(i, n) if(In[i] == 0) Vis.insert(i);

    while(not Vis.empty()) {
        int u = *Vis.begin();
        X.pb(u);
        Vis.erase(u);
        V[u] = 1;
        for(auto v: G[u]) {
            In[v]--;
            if(In[v] == 0) Vis.insert(v);
        }
    }
    if(X.size() != n) {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    for(auto u: X) cout<<u + 1<<" "; cout<<"\n";


    return 0;
}