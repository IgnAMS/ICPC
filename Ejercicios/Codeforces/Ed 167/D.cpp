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


const ll mxN = 1e6 + 5;
struct ST {
    ll T[4 * mxN];
    void update(ll i, ll x, ll l = 0, ll r = mxN, ll u = 0) {
        if(l == r) T[u] = x;
        else {
            ll m = (l + r) / 2;
            if(i <= m) update(i, x, l, m, 2 * u + 1);
            else update(i, x, m + 1, r, 2 * u + 2);
            T[u] = min(T[2 * u + 1], T[2 * u + 2]);
        }
    }
    ll query(ll i, ll j, ll l = 0, ll r = mxN, ll u = 0) {
        if(i <= l and r <= j) return T[u];
        if(r < i or j < l) return 1e10;
        ll m = (l + r) / 2;
        return min(query(i, j, l, m, 2 * u + 1), query(i, j, m + 1, r, 2 * u + 2));
    }
} st;   

ll DP[mxN];


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vector<array<ll, 2>> X(n);

    ll A[n]; rep(i, n) cin>>A[i];
    ll B[n]; rep(i, n) cin>>B[i];
    ll C[m]; rep(i, m) cin>>C[i];
    
    rep(i, n) X[i] = {A[i], A[i] - B[i]};
    pll best = {X[0][0], X[0][1]};
    rep(i, n) if(best.ss > X[i][1]) best = {X[i][0], X[i][1]}; 
    sort(X.begin(), X.end());
    rep(i, n) st.update(i, X[i][1]);

    ll ans = 0;
    DP[0] = 0;
    for(ll x = 1; x < mxN; x++) {
        auto it = lower_bound(X.begin(), X.end(), (array<ll, 2>){x, 10000000});
        if(it == X.begin()) {
            DP[x] = 0;
            continue;
        }
        it = prev(it);
        ll ind = it - X.begin();
        ll mn = st.query(0, ind);
        // cout<<"la mejor solucion con "<<x<<" es de "<<DP[x - mn] + 2<<'\n';
        DP[x] = DP[x - mn] + 2;
    }

    rep(i, m) {
        if(C[i] >= mxN) {
            // C[i] - best.ss * k < best.ff   <-> (C[i] - best.ff) / best.ss < k
            ll k = (C[i] - best.ff) / best.ss + 1;
            // cout<<"tomo "<<k<<" veces "<<best.ss<<' '<<best.ff<<" dejando "<<C[i]<<" en "<<C[i] - k * best.ss<<'\n';
            ans += 2 * k + DP[C[i] - k * best.ss];
        }
        else ans += DP[C[i]];
    }

    cout<<ans<<'\n';

    return 0;
}