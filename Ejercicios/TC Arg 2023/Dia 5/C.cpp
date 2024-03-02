#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define rep(i, n) for(int i = 0; i < n; i++)


const int mxN = 3e5+5;

int n, m, V[mxN], col[mxN];
vector<int> G[mxN];


int main() {
    cin >> n >> m;
    rep(i, m)   {
        int a, b;
        cin >> a >> b, --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    memset(col, 0, sizeof(col));
    memset(V, 0, sizeof(V));
    set<ll> S;
    
    rep(i, n) {
        if(G[i].size() >= 2) {
            S.insert(i);
        }
        V[i] = G[i].size();
    }

    ll cont = 0;
    while(!S.empty()) {
        ll u = *S.begin();
        col[u] = col[u] ^ 1;
        S.erase(S.begin());
        for(auto v: G[u]) {
            V[v] = V[v] + (col[u] == 1? -1: 1);
            if((G[v].size() - V[v]) * col[v] <= 1 and V[v] * (1 - col[v]) <= 1) {
                S.erase(v);
            }
            if((G[v].size() - V[v]) * col[v] > 1 or V[v] * (1 - col[v]) > 1) {
                S.insert(v);
            }
        }
    }
    rep(i, n) cout<<col[i]; cout<<'\n';
    
}