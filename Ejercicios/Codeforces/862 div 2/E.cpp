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

const int mxN = 1e5 + 5;

vl path, path_ind;
vector<pll> G[mxN]; // Graph (v, ind_path)

// Valores de los nodos
ll A[mxN];
map<ll, ll> cont1, cont2;
set<ll> mad1, mad2;

// Obtener el camino de u a target
bool path_u_v(ll u, ll target, ll p) {
    path.pb(u);
    if(u == target) return 1;
    for(auto [v, ind]: G[u]) if(v != p) {
        path_ind.pb(ind);
        if(path_u_v(v, target, u)) return true;
        path_ind.pop_back();
    }
    path.pop_back();
    return false;
}


void recalc(int u, int ban1, int ban2) {
    cont1[A[u]]++;
    if(cont1[A[u]] == 2) {
        mad1.insert(A[u]);
    }
    cont2[A[u]]--;
    if(cont2[A[u]] == 1) {
        mad2.erase(A[u]);
    }
    for(auto [v, ind]: G[u]) if(v != ban1 and v != ban2) {
        recalc(v, u, -1);
    } 
}

ll mad() {
    ll mx = 0;
    if(!mad1.empty()) mx = max(mx, *mad1.rbegin());
    if(!mad2.empty()) mx = max(mx, *mad2.rbegin());
    return mx;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb({v, i}); G[v].pb({u, i});
    }

    // mapa de vectores que guarda mp[k] = {u tq A[u] = k}
    map<ll, vl> mp; 
    ll mx = -1;
    rep(i, n) {
        cin>>A[i];
        if(!mp.count(A[i])) mp[A[i]] = vl();
        mp[A[i]].pb(i);
        cont2[A[i]]++;
        if(cont2[A[i]] == 2) mad2.insert(A[i]);
    }
    
    while(!mp.empty() and (*mp.rbegin()).second.size() == 1) {
        mp.erase(prev(mp.end()));
    }
    if(mp.empty()) {
        rep(i, n - 1) cout<<0<<' '; cout<<'\n';
        return 0;
    }
    if((*mp.rbegin()).second.size() >= 3) {
        rep(i, n - 1) cout<<(*mp.rbegin()).first<<" "; cout<<'\n';
        return 0;
    } 

    ll mad_val = (*mp.rbegin()).first;
    ll u = (*mp.rbegin()).second[0], v = (*mp.rbegin()).second[1];
    vl Ans(n - 1, mad_val);
    path_u_v(u, v, -1);
    
    // cerr<<"sobrevivi el dfs\n";
    // cerr<<path.size()<<' '<<path_ind.size()<<'\n';

    rep(i, path.size() - 1)  {
        if(i == 0) recalc(path[0], path[1], -1);
        else recalc(path[i], path[i - 1], path[i + 1]);
        Ans[path_ind[i]] = mad();
    }
    rep(i, n - 1) cout<<Ans[i]<<'\n';


    return 0;
}