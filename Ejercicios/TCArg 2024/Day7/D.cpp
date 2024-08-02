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

const int mxN = 5e5+5;
struct ST {
    vl T = vl(4 * mxN, 0);
    void update(ll i, ll x, ll l = 0, ll r = mxN - 1, ll u = 0) {
        if(l == r) T[u] = x;
        else {
            ll m = (l + r) / 2;
            if(i <= m) update(i, x, l, m, 2 * u + 1);
            else update(i, x, m + 1, r, 2 * u + 2);
            T[u] = T[2 * u + 1] + T[2 * u + 2];
        }
    }
    ll query(ll x, ll l = 0, ll r = mxN - 1, ll u = 0) {
        if(l == r) return l;
        // cerr<<x<<' '<<l<<' '<<r<<' '<<u<<' '<<T[u]<<' '<<2 * u + 1<<' '<<4 * mxN<<' '<<bool(2 * u + 1 < 4 * mxN)<<'\n';
        ll m = (l + r) / 2;
        if(T[2 * u + 1] >= x) return query(x, l, m, 2 * u + 1);
        return query(x - T[2 * u + 1], m + 1, r, 2 * u + 2);
    }
} st;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, q; cin>>n>>m>>q;
    set<pll> X;
    rep(i, m) X.insert({0, i});
    vl C(m, 0);
    rep(i, n) {
        ll x; cin>>x; x--;
        auto it = X.lower_bound({C[x], x});
        X.erase(it);
        C[x]++;
        X.insert({C[x], x});
    }
    
    vector<array<ll, 3>> E;
    rep(i, q) {
        ll t; cin>>t;
        E.pb({t, 1, i});
    }

    set<ll> S;
    ll time = n + 1, xd = 0;
    for(auto it = X.begin(); it != X.end(); it++) {
        auto [cant, ind] = *it;
        // cout<<"debo anadir a "<<ind<<" en el tiempo "<<time<<'\n';
        S.insert(ind);
        E.pb({time, 0, ind});
        if(next(it) == X.end()) break;

        if(it->ff == next(it)->ff) time += 0, xd++;
        else time += ll(S.size()) * (next(it)->ff - it->ff);
    }
    
    sort(E.begin(), E.end());

    // Eventos de los siguientes tipos: 
    // [tiempo, tipo, valor]
    pll last = {-1, -1}; // time, value
    ll Ans[q];
    ll contador = 0;
    for(auto [time2, type, index]: E) {
        // cout<<time<<' '<<type<<' '<<value<<'\n';
        if(type == 0) {
            last = {time2, index};
            contador++;
            st.update(index, 1);
        }
        else {
            ll valor = (time2 - last.ff) % contador;
            valor++;
            // cerr<<"en el tiempo "<<time2<<" tengo "<<contador<<" elementos y quiero el "<<valor<<"-esimo para la consulta "<<index<<"\n"; 
            ll x = st.query(valor);
            Ans[index] = x + 1;
        }
    }
    rep(i, q) cout<<Ans[i]<<'\n';


    return 0;
}