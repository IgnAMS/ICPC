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

const int mxN = 2e5 + 5;
vector<pll> E[mxN];


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<pll> Pos(n);
    vector<string> Dir(n);
    map<ll, vector<pll>> X, Y;  
    rep(i, n) {
        cin>>Pos[i].ff>>Pos[i].ss;
        cin>>Dir[i];
        if(!X.count(Pos[i].ff)) X[Pos[i].ff] = {}; 
        if(!Y.count(Pos[i].ss)) Y[Pos[i].ss] = {}; 
        X[Pos[i].ff].pb({Pos[i].ss, i});
        Y[Pos[i].ss].pb({Pos[i].ff, i});
    }

    for(auto [x, vec]: X) {
        sort(vec.begin(), vec.end());
        int v = -1;
        for(auto [y, u]: vec) {
            // cout<<u<<", pos: ("<<x<<", "<<y<<"), dir: "<<Dir[u]<<'\n';
            if(v != -1) {
                if(Dir[u] == "abajo") E[u].pb({v, 0});
                else E[u].pb({v, 1});

                if(Dir[v] == "arriba") E[v].pb({u, 0});
                else E[v].pb({u, 1}); 
            } 
            v = u;
        }
    }
    for(auto [y, vec]: Y) {
        sort(vec.begin(), vec.end());
        int v = -1;
        for(auto [x, u]: vec) {
            // cout<<u<<", pos: ("<<x<<", "<<y<<"), dir: "<<Dir[u]<<'\n';
            if(v != -1) {
                if(Dir[u] == "izquierda") E[u].pb({v, 0});
                else E[u].pb({v, 1});

                if(Dir[v] == "derecha") E[v].pb({u, 0});
                else E[v].pb({u, 1}); 
            }
            v = u;
        }
    }

    // rep(u, n) {
    //     for(auto [v, w]: E[u]) cout<<u<<" conecta con "<<v<<" con peso "<<w<<'\n';
    //     cout<<"\n";
    // }


    vl D(n, 1e8);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 0});
    D[0] = 0;
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        // cout<<"entre a "<<u<<" con costo "<<d<<'\n';
        if(D[u] < d) continue;
        for(auto [v, w]: E[u]) if(D[v] > d + w) {
            D[v] = d + w;
            pq.push({D[v], v});
        }
    }
    cout<<(D[n - 1] == 1e8? -1: D[n - 1])<<'\n';


    return 0;
}