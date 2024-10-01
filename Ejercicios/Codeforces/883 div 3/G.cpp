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


const ll mxN = (1<<10) + 5;

struct Med {
    ll d, cure, disease;
};

struct Edge {
    ll v, w;
};

vector<Edge> G[mxN];
ll D[mxN];



ll toint(string& s, int n) {
    ll ans = 0;
    rep(i, n) {
        ans *= 2;
        if(s[i] == '1') ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        rep(i, mxN) G[i].clear();
        
        int n, m; cin>>n>>m;
        string sinit; cin>>sinit;
        ll init = toint(sinit, n);
        
        vector<Med> M(m);
        rep(i, m) {
            ll d; cin>>d;
            string scure; cin>>scure;
            string ssympton; cin>>ssympton;
            M[i] = {d, toint(scure, n), toint(ssympton, n)};
            // cout<<toint(scure, n)<<' '<<toint(ssympton, n)<<'\n';
        }
        // 10^3 * 10^3 * 10 ~ 10^7
        rep(mask, (1<<n)) {
            for(auto& m: M) {
                ll v = 0;
                ll aux = 1;
                rep(i, n) {
                    if((m.disease & (1<<i))) v += aux;
                    else if((mask & (1<<i)) and !(m.cure & (1<<i))) v += aux;
                    aux *= 2;
                }
                // cout<<"puedo ir desde "<<mask<<" hasta "<<v<<" con costo "<<m.d<<'\n';
                G[mask].pb({v, m.d});
            }
        }

        // (10^3 + 10^6) * 
        rep(i, (1<<n)) D[i] = 1e15;
        D[init] = 0;
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push({0, init});
        while(!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            for(auto& [v, w]: G[u]) if(d + w < D[v]) {
                D[v] = d + w;
                pq.push({D[v], v});
            }
        }
        if(D[0] == 1e15) cout<<"-1\n";
        else cout<<D[0]<<'\n';

    }





    return 0;
}