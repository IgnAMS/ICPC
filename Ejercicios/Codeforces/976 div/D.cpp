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

// 10+9+8+7+6+5+4+3+2+1
// para un segmento [a_i, k_i, d_i] quiero saber si lo puedo combinar con otro de

struct DSU {
    vl p;
    DSU(int n): p(n, -1) {}
    ll get(int u) { return p[u] < 0? u: p[u] = get(p[u]); }
    bool join(int u, int v) {
        if((u = get(u)) == (v = get(v))) return 0;
        if(p[u] > p[v]) swap(u, v); // u es mas pequeno
        p[u] += p[v], p[v] = u;
        return 1;
    }
};


int main() {  
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n, m; cin>>n>>m;
        DSU dsu(n + 1);
        set<pll> Segments[11][11];
        rep(i, m) {
            // cerr<<"holi\n";
            ll a, d, k; cin>>a>>d>>k; a--;
            // if(k == 0) continue;
            bool joined = 0;
            auto it = Segments[d][a % d].lower_bound({a, 0});
            // justo antes de a, [inicio, fin] inter [a, a + k * d]
            if(it != Segments[d][a % d].begin()) {
                auto [inicio, fin] = *prev(it);
                Segments[d][a % d].erase({inicio, fin});
                if(a <= fin) {
                    joined = 1;
                    // cout<<"junto los segmentos "<<a<<' '<<a + k * d<<" con "<<inicio<<", "<<fin<<" con salto "<<d<<'\n';
                    inicio = min(inicio, a);
                    fin = max(fin, a + k * d);
                }
                Segments[d][a % d].insert({inicio, fin});
            }
            // segmento que viene despues de a, [a, a + k * d] inter [inicio, fin]
            auto it2 = Segments[d][a % d].lower_bound({a, 0});
            if(it2 != Segments[d][a % d].end()) {
                auto [inicio, fin] = *it2;
                Segments[d][a % d].erase({inicio, fin});
                if(inicio <= a + k * d) {
                    joined = 1;
                    // cout<<"junto los segmentos "<<a<<' '<<a + k * d<<" con holi "<<inicio<<", "<<fin<<" con salto "<<d<<'\n';
                    inicio = min(inicio, a);
                    fin = max(fin, a + k * d); 
                }
                Segments[d][a % d].insert({inicio, fin});
            }
            if(!joined) {
                // cout<<"anado el segmento "<<a<<", "<<a + k * d<<' '<<d<<' '<<a % d<<'\n';
                Segments[d][a % d].insert({a, a + k * d});
                // cout<<d<<' '<<a % d<<' '<<Segments[d][a % d].size()<<'\n';
            }
        }


        ll ans = n;
        repx(d, 1, 11) {
            rep(shift, d) for(auto [inicio, fin]: Segments[d][shift]) {
                for(int i = inicio; i <= fin; i += d) ans -= dsu.join(inicio, i);
            }
        }
        cout<<ans<<'\n';

    }

    return 0;
}