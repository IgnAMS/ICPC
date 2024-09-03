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


const ll mxN = 1005;
int n;
ll A[1000][1000];
ll DP[1000][1000][2];
vector<pll> Cols[1000], Rows[1000];


struct ST {
    ll T[4 * mxN + 5];
    void update(ll i, ll x, ll l = 0, ll r = mxN, ll u = 0) {
        if(l == r) T[u] = x;
        else {
            ll m = (l + r) / 2;
            if(i <= m) update(i, x, l, m, 2 * u + 1);
            else update(i, x, m + 1, r, 2 * u + 2);
            T[u] = max(T[2 * u + 1], T[2 * u + 2]);
        }
    }
    ll query(ll i, ll j, ll l = 0, ll r = mxN, ll u = 0) {
        if(i <= l and r <= j) return T[u];
        if(r < i or j < l) return 0;
        ll m = (l + r) / 2;
        return max(query(i, j, l, m, 2 * u + 1), query(i, j, m + 1, r, 2 * u + 2));
    }

} st0[mxN], st1[mxN];

ll dp(ll i, ll j, ll dir) {
    if(DP[i][j][dir] != -1) return DP[i][j][dir];
    DP[i][j][dir] = 1;
    pll x = {A[i][j] + 1, 0};
    ll indr = lower_bound(Rows[i].begin(), Rows[i].end(), x) - Rows[i].begin();
    ll indc = lower_bound(Cols[j].begin(), Cols[j].end(), x) - Cols[j].begin();    
    if(dir == 0) {
        DP[i][j][dir] = st1[i].query(indr + 1, n) + 1;
        st0[j].update(indc, DP[i][j][dir]);
    }
    else {
        DP[i][j][dir] = st0[j].query(indc + 1, n) + 1;
        st1[i].update(indr, DP[i][j][dir]);
    }
    return DP[i][j][dir];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i, n) rep(j, n) cin>>A[i][j];
    ll ans = 0;
    rep(i, n) {
        rep(j, n) Rows[i].pb({A[i][j], j}), Cols[j].pb({A[i][j], i});
    }
    rep(i, n) {
        sort(Rows[i].begin(), Rows[i].end());
        sort(Cols[i].begin(), Cols[i].end());
    }

    rep(i, n) rep(j, n) rep(b, 2) DP[i][j][b] = -1;
    vector<array<ll, 3>> X;
    rep(i, n) rep(j, n) X.pb({A[i][j], i, j});
    sort(X.begin(), X.end());

    rep(i, n * n) {
        ll v1 = dp(X[n * n - i - 1][1], X[n * n - i - 1][2], 0);
        ll v2 = dp(X[n * n - i - 1][1], X[n * n - i - 1][2], 1);
        ans = max({ans, v1, v2});   
    }

    cout<<ans<<'\n';

    return 0;
}