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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<vl> G(n, vl());
    rep(i, n - 1) {
        int u, v; cin>>u>>v, u--, v--;
        G[u].pb(v); G[v].pb(u);
    }
    ll A[n]; rep(i, n) cin>>A[i], A[i]--;
    if(A[0] != 0) {
        cout<<"No\n";
        return 0;
    }

    int ind = 1;
    ll P[n]; 
    P[0] = -1;
    deque<ll> q = {0};
    bool pos = 1;
    while(!q.empty()) {
        auto u = q.front(); q.pop_front(); 
        set<ll> S;
        vl X;
        rep(i, G[u].size() - (u == 0? 0: 1)) {
            S.insert(A[ind]);
            X.pb(A[ind]);
            ind++;
        }
        for(auto v: G[u]) if(v != P[u] and !S.count(v)) {
            // cout<<"no encontre a "<<v + 1<<" en los hijos de "<<u + 1<<'\n';
            pos = 0;
        }
        if(!pos) break;
        for(auto v: X) {
            q.push_back(v);
            P[v] = u;
        }
    }
    cout<<(pos? "Yes": "No")<<'\n';

    return 0;
}