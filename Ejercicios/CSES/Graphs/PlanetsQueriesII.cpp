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
// g++ -O2 PlanetsQueriesII.cpp && time ./a.out <input.txt >output.txt

const int mxN = 2e5+5;
int n, m, q;
vector<vl> Cycles;
vl invG[mxN];
vl Comps;
int adj[mxN], BinLift[mxN][32], V[mxN], P[mxN], Comp[mxN], V2[mxN], D[mxN], inCycle[mxN];


void dfs(int u, int p = -1) {
    V[u] = 1, P[u] = p;

    // Anadir un nuevo ciclo
    if(V[adj[u]] and Comp[adj[u]] == -1) {
        int x = u;
        vl new_cycle = {};
        while(x != adj[u]) {
            new_cycle.pb(x);
            x = P[x];
        }
        new_cycle.pb(x);
        reverse(new_cycle.begin(), new_cycle.end());

        for(auto x: new_cycle) {
            Comp[x] = Cycles.size();
            inCycle[x] = 1;
        }
        Cycles.pb(new_cycle);
    }
    if(!V[adj[u]]) dfs(adj[u], u);

    Comp[u] = Comp[adj[u]];
}

void invDfs(int u, int d) {
    D[u] = d;
    for(auto v: invG[u]) if(D[v] == -1) {
        invDfs(v, d + 1);
    }
}

int bin_jump(int u, int d) {
    int curr = u;
    for(int b = 29; b >= 0; b--) {
        if(d & (1<<b)) curr = BinLift[curr][b];
    }
    return curr;
}

int get_first_in_cycle(int u) {
    int l = 0, r = mxN;
    while(l < r) {
        int m = (l + r) / 2;
        int curr = bin_jump(u, m);

        if(inCycle[curr]) r = m;
        else l = m + 1;
    }
    int curr = bin_jump(u, l);
    return curr;
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    rep(i, n) {
        int x; cin>>x; x--;
        adj[i] = x;
        Comp[i] = -1;
        D[i] = -1;
        invG[x].pb(i);
    }
    rep(i, n) if(!V[i]) dfs(i);

    for(auto cycle: Cycles) {
        invDfs(*cycle.begin(), 0);
        // cout<<"nuevo ciclo:\n";
        // for(auto u: cycle) cout<<u<<", "; cout<<"\n\n";
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
        int u, v; cin>>u>>v; u--, v--;
        int cycle_size = Cycles[Comp[u]].size();
        if(Comp[u] != Comp[v]) {
            // cerr<<"Entre caso 0\n";
            cout<<"-1\n";
        }
        else if(inCycle[u] and inCycle[v]) {
            // cerr<<"entre caso 1\n";
            cout<<(D[u] - D[v] + cycle_size) % cycle_size<<"\n";
        }
        else if(inCycle[v]) {
            // cerr<<"entre caso 2\n";
            // Conseguir el primero en el ciclo
            int first_cycle = get_first_in_cycle(u);
            int d_cycle = (D[first_cycle] - D[v] + cycle_size) % cycle_size;
            cout<<D[u] - D[first_cycle] + d_cycle<<"\n";
        }
        else {
            // cerr<<"entre caso 3\n";
            // ninguno esta en el ciclo!
            if(D[v] > D[u]) cout<<"-1\n";  // v esta mas "arriba"
            // -> D[v] - D[u] <= 0 -> 0 <= D[u] - D[v]
            else if(v == bin_jump(u, D[u] - D[v])) cout<<D[u] - D[v]<<"\n";
            else cout<<"-1\n";
        }
    }


    return 0;
}