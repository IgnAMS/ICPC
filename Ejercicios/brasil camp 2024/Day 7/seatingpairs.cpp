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

const int mxN = 200005;
vl G[mxN];
vl T[mxN];
ll C[mxN];

ll make_tree(int u) {
    if(C[u] != -1) return C[u];
    C[u] = 1;
    for(auto v: G[u]) if(C[v] == -1) {
        C[u] += make_tree(v);
        T[u].pb(v);
        T[v].pb(u);
    }
    return C[u];
}

vector<vl> Ans;
void sits(ll u, ll p) {
    // si soy par, entonces debo juntarme con un impar y junto el resto de los impares
    // si soy impar es que ya fui pintado y tengo una cantidad par de vecinos impares
    
    vl Imp;
    for(auto v: T[u]) if(v != p) {
        if((C[v] & 1)) {
            Imp.pb(v);
        }
        sits(v, u);
    }
    if((C[u] & 1) == 0) {
        Ans.pb({u, Imp.back(), -1});
        Imp.pop_back();
    }

    for(int i = 0; i < Imp.size(); i += 2) {
        Ans.pb({Imp[i], Imp[i + 1], u});
    }
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    n *= 2;
    int m; cin>>m;
    rep(i, m) {
        int u, v; cin>>u>>v;
        G[u].pb(v); 
        G[v].pb(u);
    }

    rep(u, n) C[u] = -1;
    bool pos = 1;
    vl Init;
    rep(u, n) {
        if(C[u] == -1) {
            // hay una componente impar
            if(make_tree(u) & 1) pos = 0;
            Init.pb(u);
        }
        
    }
    if(!pos) {
        cout<<"IMPOSSIBLE\n";
    }
    else {
el         cout<<"POSSIBLE\n";
        for(auto vec: Ans) {
            cout<<vec[0]<<' '<<vec[1]<<' '<<vec[2]<<'\n'; 
        }
    }


    return 0;
}