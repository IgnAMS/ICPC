#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back

const int mxN = 5e5 + 5;
struct ST {
    ll T[4 * mxN] = {0}; 

    void update(ll i, ll x, ll l = 0, ll r = mxN - 1, ll u = 0) {
        if (l == r) T[u] = x;
        else {
            ll m = (l + r) / 2;
            if (i <= m) update(i, x, l, m, 2 * u + 1);
            else update(i, x, m + 1, r, 2 * u + 2);
            T[u] = T[2 * u + 1] + T[2 * u + 2];
        }
    }

    ll query(ll x, ll l = 0, ll r = mxN - 1, ll u = 0) {
        if (l == r) return l;
        ll m = (l + r) / 2;
        if (T[2 * u + 1] >= x) return query(x, l, m, 2 * u + 1);
        return query(x - T[2 * u + 1], m + 1, r, 2 * u + 2);
    }
} st;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin>>n>>m>>q;

    set<pll> X;
    rep(i, m) X.insert({0, i});
    vl C(m, 0);
    rep(i, n) {
        ll x;
        cin>>x; x--;
        auto it = X.lower_bound({C[x], x});
        X.erase(it);
        C[x]++;
        X.insert({C[x], x});
    }

    vector<array<ll, 3>> E;
    rep(i, q) {
        ll t; cin >> t;
        E.pb({t, 1, i});
    }

    set<ll> S;
    ll time = n + 1, xd = 0;
    for (auto it = X.begin(); next(it) != X.end(); it++) {
        auto [cant, ind] = *it;
        // cout << "debo anadir a " << ind << " en el tiempo " << time << '\n';
        S.insert(ind);
        E.pb({time, 0, ind});
        if (it->ff == next(it)->ff) time += 0, xd++;
        else time += ll(S.size()) * (next(it)->ff - it->ff);
    }
    // cout << "debo anadir a " << X.rbegin()->ss << " en el tiempo " << time << '\n';
    E.pb({time, 0, X.rbegin()->ss});
    sort(E.begin(), E.end());

    pll last = {-1, -1};
    vector<ll> Ans(q, 0); 
    ll contador = 0;

    for (auto [time2, type, value] : E) {
        if (type == 0) {
            last = {time2, value};
            contador++;
            st.update(value, 1);
        } else {
            ll valor = (time2 - last.ff) % contador + 1;
            // cerr << contador << '\n';
            // cerr << "en el tiempo " << time2 << " tengo " << contador << " elementos y quiero el " << valor << "-esimo para la consulta " << value << "\n";
            ll x = st.query(valor);
            Ans[value] = x + 1;
        }
    }
    rep(i, q) cout << Ans[i] << '\n';

    return 0;
}
