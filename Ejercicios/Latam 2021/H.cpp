#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<iostream>
#include<algorithm>
#include<numeric>
#include <unordered_map>
#include <cmath>
#include<set>
#include<array>
using namespace std;
// g++ -std=c++17 H.cpp -o a && ./a <input.txt> output.txt   
// ulimit -s 1000000
// g++ -std=c++17 -O2 H.cpp && time ./a.out <input.txt> output.txt


#define ll long long
#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define repx(i, a, b) for(int i = (int)a; i < (int)b; ++i)
#define pb push_back
typedef pair<ll, ll> pll; 
typedef vector<int> vi;

const int mxN = 505;
const ll INF = 1e15;

// time: O(F V E)            F is the maximum flow
//       O(V E + F E log V)  if bellman-ford is replaced by johnson
struct Flow {
    struct Edge {
        int u, v;
        ll c, w, f = 0;
    };

    int N, s, t;
    vector<vector<int>> G;
    vector<Edge> E;
    vector<ll> d, b;
    vector<int> p;

    Flow() {}
    Flow(int N, int s, int t) : N(N), s(s), t(t), G(N) {}

    void add_edge(int u, int v, ll c, ll w) {
        G[u].push_back(E.size());
        E.push_back({u, v, c, w});
        G[v].push_back(E.size());
        E.push_back({v, u, 0, -w});
    }

    // johnsons potentials: O(E log V)
    void calcdists() {
        if (b.empty()) {
            b.assign(N, 0);
        }
        p.assign(N, -1), d.assign(N, INF), d[s] = 0;
        priority_queue<pair<ll, int>> q;
        q.push({0, s});
        while (!q.empty()) {
            auto [w, u] = q.top();
            q.pop();
            if (d[u] < -w + b[u]) continue;
            for (int ei : G[u]) {
                auto e = E[ei];
                ll n = d[u] + e.w;
                if (e.f < e.c && n < d[e.v]) {
                    d[e.v] = n, p[e.v] = ei;
                    q.push({b[e.v] - n, e.v});
                }
            }
        }
        b = d;
    }

    ll solve() {
        b.clear();
        ll total_cost = 0;
        ll ff = 0;
        while (true) {
            calcdists();
            if (p[t] == -1) break;

            ll f = INF;
            for (int cur = t; p[cur] != -1; cur = E[p[cur]].u)
                f = min(f, E[p[cur]].c - E[p[cur]].f);
            for (int cur = t; p[cur] != -1; cur = E[p[cur]].u)
                E[p[cur]].f += f, E[p[cur] ^ 1].f -= f;

            ll path_cost = 0;
            for (int cur = t; p[cur] != -1; cur = E[p[cur]].u)
                path_cost += E[p[cur]].w;

            total_cost += f * path_cost;
            ff += f;
        }
        return total_cost;
    }
};


int main() {
    int n; cin>>n;
    ll cost[n][n];
    rep(i, n) rep(j, n) cin>>cost[i][j];
    ll nodes = (n + 1) / 2 + (n + 1) / 2 + 2;
    int s = 0, t = nodes - 1;
    Flow F(nodes, s, t);
    for(int i = 1, ict = 1; i <= n; i += 2, ict++) {
        for(int j = 2, jct = (n+1)/2 + 1; j <= n + (n % 2); j += 2, jct++) {
            ll w;
            if(j == n + 1) w = 0;
            else w = cost[i - 1][j - 1];
            if(j > 2) w += cost[i - 1][j - 3];
            // cout<<i<<' '<<j<<' '<<w<<'\n';

            F.add_edge(ict, jct, 1, w);
        }
    }
    for(int i = 1, ict = 1; i <= n; i += 2, ict++) F.add_edge(s, ict, 1, 0);
    for(int j = 2, jct = (n+1)/2 + 1; j <= n + (n % 2); j += 2, jct++) F.add_edge(jct, t, 1, 0);
    cout<<F.solve()<<"\n";
}