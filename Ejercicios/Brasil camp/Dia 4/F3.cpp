#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

ll DP[400005];
ll Lower[400005];
vector<vector<ll>> G(400005, vector<ll>());

ll checkpath(ll u) {
    if(G[u].empty()) return 1;
    if(DP[u] != 0) {
        ll suma = 0, v2 = -1, notvis = 0, l = 0;
        for(auto v: G[u]) {
            if(DP[v] == 0) notvis++, v2 = v, l += Lower[v];
            else suma += DP[v];
        }
        if(suma + l > DP[u]) {
            cerr<<suma + l<<' '<<DP[u]<<'\n';
            cerr<<"soy menor a mi lowerbound\n";
            return -1;
        }
        // all the childs to sum up
        else if(suma + l == DP[u]) {
            for(auto v: G[u]) {
                ll aux = DP[v];
                // cerr<<"asignare a "<<v<<" con "<<DP[v]<<'\n';
                if(aux == 0) DP[v] = Lower[v];
                if(aux == 0 and checkpath(v) == -1) {
                    cerr<<"no puedo asignar a "<<v<<" con "<<DP[v]<<'\n';
                    return -1;
                }
            }
        }
        // doesnt sum up and there is more than one child
        else if(suma + l < DP[u] and notvis > 1) {
            cerr<<"tengo incognitas abajo mio\n";
            return -1;
        }
        // one unkown children
        else if(suma + l < DP[u] and notvis == 1) {
            DP[v2] = DP[u] - suma, Lower[v2] = DP[v2];
            if(checkpath(v2) == -1) {
                cerr<<"no puedo resolver a "<<v2<<" con "<<DP[v2]<<'\n';
                return -1;
            }
        }
        // the flow doesnt match up
        else if(suma + l < DP[u] and notvis == 0) {
            cerr<<"soy mayor a lo que esta abajo mio\n";
            return -1;
        }
    }
    else {
        ll notvis = 0, suma = 0;
        for(auto v: G[u]) {
            if(DP[v] == 0) notvis++;
            else suma += DP[v];
        }
        if(notvis == 0) DP[u] = suma, Lower[u] = suma;
    }
    return 1;
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    int P[n];
    repx(i, 1, n) {
        int p; cin>>p; p--;
        P[i] = p;
        G[p].push_back(i);
        
    }
    rep(i, n) cin>>DP[i];
    rep(i, n) {
        if(DP[i] != 0) Lower[i] = DP[i];
        else if(G[i].empty()) Lower[i] = 1;
        else Lower[i] = 0;
    }
    bool pos = 1;
    for(int u = n - 1; u >= 0; u--) {
        // rep(i, n) cerr<<DP[i]<<' '; cerr<<'\n';
        if(DP[u] == 0) checkpath(u);
        if(u != 0 and DP[P[u]] == 0) Lower[P[u]] += Lower[u];
    }
    rep(u, n) {
        if(checkpath(u) == -1) pos = 0;
    }
    // cerr<<pos<<'\n';
    rep(i, n) if(DP[i] == 0) pos = 0;
    if(!pos) cout<<"impossible\n";
    else {
        rep(i, n) cout<<DP[i]<<'\n';
    }


    return 0;
}