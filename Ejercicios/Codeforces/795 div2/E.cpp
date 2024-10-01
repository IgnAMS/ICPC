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

struct DSU {
    vl p; DSU(int N) : p(N, -1) {}
    int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -p[get(x)]; }
    void unite(int x, int y) {
        if ((x = get(x)) == (y = get(y))) return;
        if (p[x] > p[y]) swap(x,y);
        p[x] += p[y], p[y] = x;
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        
        vector<array<ll, 5>> E;
        rep(i, n) {
            int c, l, r; cin>>c>>l>>r;
            E.pb({l, 0, c, r, i}); // Evento de abrir
            E.pb({r, 1, c, r, i}); // Evento de cerrar
        }
        sort(E.begin(), E.end());
        DSU dsu(n);

        set<pll> Col[2];
        for(auto& [x, type, col, right, index]: E) {
            if(type == 0) {
                Col[col].insert({right, index});
                auto it = Col[1 ^ col].lower_bound({x, 0});
                vector<pll> Erase;
                for(; it != Col[1 ^ col].end(); it++) {
                    Erase.pb(*it);
                    dsu.unite(index, it->ss);
                }
                if(Erase.size()) Erase.pop_back();
                for(auto par: Erase) Col[1 ^ col].erase(par);
            }
            else {
                pll curr = {x, index};
                if(Col[col].count(curr)) Col[col].erase({x, index});
            }
        }
        set<ll> S;
        rep(i, n) S.insert(dsu.get(i));
        cout<<S.size()<<'\n';


    }





    return 0;
}