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
// g++ -O2 PlanetsQueriesI.cpp && time ./a.out <input.txt >output.txt

const int mxN = 2e5+5;
int n, m, q;
int adj[mxN], BinLift[mxN][32];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    rep(i, n) {
        int x; cin>>x; x--;
        adj[i] = x;
    }
    rep(u, n) {
        BinLift[u][0] = adj[u];
    }

    for(int bit = 1; bit <= 30; bit++) {
        rep(u, n) {
            BinLift[u][bit] = BinLift[BinLift[u][bit-1]][bit-1];
        }
    }
    while(q--) {
        int u, t; cin>>u>>t; u--;
        int ans = u;
        for(int bit = 29; bit >= 0; bit--) {
            if(t & (1<<bit)) {
                ans = BinLift[ans][bit];
            }
        }
        cout<<ans + 1<<"\n";
    }


    return 0;
}