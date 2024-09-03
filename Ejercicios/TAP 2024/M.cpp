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
// g++ -O2 M.cpp && time ./a.out <input.txt> output.txt


const ll mxN = 2e5 + 10;
const ll INF = 1e17;
struct Mx {
    ll id, v;
    Mx(): id(-INF), v(-INF) {}
    Mx(ll i, ll v): id(i), v(v) {}
    Mx(Mx a, Mx b) {
        if(a.v == b.v) id = max(a.id, b.id), v = a.v;
        else if(a.v > b.v) id = a.id, v = a.v;
        else id = b.id, v = b.v; 
    }
};

struct Mn {
    ll id, v;
    Mn(): id(INF), v(INF) {}
    Mn(ll i, ll v): id(i), v(v) {}
    Mn(Mn a, Mn b) {
        if(a.v == b.v) id = max(a.id, b.id), v = a.v;
        else if(a.v < b.v) id = a.id, v = a.v;
        else id = b.id, v = b.v; 
    }
};


struct ST {
    vector<Mx> TMx;
    vector<Mn> TMn;
    vl LMx, LMn;
    int n;

    ST(int N, vl& V, vl& C) {
        TMx.assign(4 * N, Mx()); TMn.assign(4 * N, Mn());
        LMx.assign(4 * N, 0), LMn.assign(4 * N, 0);
        n = N;
        build(0, n - 1, 0, V, C);
    }

    void build(ll l, ll r, ll u, vl& V, vl& C) {
        if(l == r) {
            TMx[u] = Mx(l, V[l]);
            TMn[u] = Mn(l, C[l]);
            return;
        }
        ll m = (l + r) / 2;
        build(l, m, 2 * u + 1, V, C);
        build(m + 1, r, 2 * u + 2, V, C);
        TMx[u] = Mx(TMx[2 * u + 1], TMx[2 * u + 2]);
        TMn[u] = Mn(TMn[2 * u + 1], TMn[2 * u + 2]);
    }

    void pushMx(ll l, ll r, ll u, ll x) {
        // cout<<"el rango "<<l<<" "<<r<<" lo disminuyo en "<<x<<'\n';
        TMx[u].v += x;
        if(l != r) {
            LMx[2 * u + 1] += x;
            LMx[2 * u + 2] += x;
        }
        LMx[u] = 0;
    }
    
    void updateMx(ll i, ll j, ll l, ll r, ll u, ll x) {
        if(LMx[u] != 0) pushMx(l, r, u, LMx[u]);
        if(i <= l and r <= j) {
            pushMx(l, r, u, x);
            return;
        }
        if(r < i or j < l) return;

        ll m = (l + r) / 2;
        updateMx(i, j, l, m, 2 * u + 1, x);
        updateMx(i, j, m + 1, r, 2 * u + 2, x);
        TMx[u] = Mx(TMx[2 * u + 1], TMx[2 * u + 2]);
    }



    void pushMn(ll l, ll r, ll u, ll x) {
        TMn[u].v += x;
        if(l != r) {
            LMn[2 * u + 1] += x;
            LMn[2 * u + 2] += x;
        }
        LMn[u] = 0;
    }

    void updateMn(ll i, ll j, ll l, ll r, ll u, ll x) {
        if(LMn[u] != 0) pushMn(l, r, u, LMn[u]);
        if(i <= l and r <= j) {
            pushMn(l, r, u, x);
            return;
        }
        if(r < i or j < l) return;

        ll m = (l + r) / 2;
        updateMn(i, j, l, m, 2 * u + 1, x);
        updateMn(i, j, m + 1, r, 2 * u + 2, x);
        TMn[u] = Mn(TMn[2 * u + 1], TMn[2 * u + 2]);
    }

    
    
    Mx mx(ll i, ll j, ll l, ll r, ll u = 0) {
        if(LMx[u] != 0) pushMx(l, r, u, LMx[u]);
        if(i <= l and r <= j) return TMx[u];
        if(r < i or j < l) return Mx();
        ll m = (l + r) / 2;
        return Mx(mx(i, j, l, m, 2 * u + 1), mx(i, j, m + 1, r, 2 * u + 2));
    }

    Mn mn(ll i, ll j, ll l, ll r, ll u = 0) {
        if(LMn[u] != 0) pushMn(l, r, u, LMn[u]);
        if(i <= l and r <= j) return TMn[u];
        if(r < i or j < l) return Mn();
        ll m = (l + r) / 2;
        return Mn(mn(i, j, l, m, 2 * u + 1), mn(i, j, m + 1, r, 2 * u + 2));
    }


    ll get_max(ll &k, vl& P) {
        // Obtengo el maximo mx
        Mx mxnode = mx(0, n - 1, 0, n - 1, 0);
        // rep(i, n) cout<<mx(i, i, 0, n - 1, 0).v<<' '; cout<<'\n';
        if(mxnode.v <= 0) {
            k = 0;
            return 0;
        }
        // Busco el minimo
        Mn mnnode = mn(0, mxnode.id, 0, n - 1, 0);
        ll mn_val = min(k, mnnode.v);
        if(k <= mn_val) {
            ll ans = k * mxnode.v;
            k = 0;
            return ans;
        }

        // rep(i, mxnode.id + 1) cout<<mn(i, i, 0, n - 1, 0).v<<' '; cout<<'\n'; 

        // Caso contrario actualizo todos los puntos que llegaorn a 0
        while(true) {
            // todo a la derecha lo resto por P[mn.id]
            // cout<<"actualizo el rango "<<mnnode.id<<' '<<n - 1<<" con "<<-P[mnnode.id]<<'\n';
            updateMx(mnnode.id, n - 1, 0, n - 1, 0, -P[mnnode.id]);
            // actualizo el punto con infinito
            updateMn(mnnode.id, mnnode.id, 0, n - 1, 0, INF);
            
            mnnode = mn(0, mxnode.id, 0, n - 1, 0);
            if(mnnode.v != mn_val) break;
        }

        // Actualizo todo el rango del contador
        updateMn(0, mxnode.id, 0, n - 1, 0, -mn_val);
        k -= mn_val;
        return mn_val * mxnode.v;
    }
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k; cin>>n>>k;
    vl V(n), C(n), P(n);
    rep(i, n) cin>>V[i];
    rep(i, n) cin>>C[i];
    rep(i, n) cin>>P[i];

    ST st(n, V, C);


    ll ans = 0;
    while(k > 0) {
        ans += st.get_max(k, P);
    }
    cout<<ans<<'\n';



    return 0;
}