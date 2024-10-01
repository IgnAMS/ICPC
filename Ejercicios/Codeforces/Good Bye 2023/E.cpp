#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(ll i=a; i<b; i++)
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

const ll mxN = 3e5+5;

vector<int> G[mxN];
ll A[mxN], I[mxN], E[mxN];
vector<int> Last[mxN], Rem[mxN];

ll id = 0;
void dfs(ll u, ll p) {
    I[u] = id++;
    if(Last[A[u]].size()) Rem[Last[A[u]].back()].pb(u);
    Last[A[u]].pb(u);
    for(auto v: G[u]) dfs(v, u);
    Last[A[u]].pop_back();
    E[u] = id;
}

struct ST {
    ll T[4 * mxN + 20], X[4 * mxN + 20];
    void update(ll i, ll j, ll x, ll l = 0, ll r = mxN, ll u = 0) {
        if(i <= l and r <= j) {
            // cout<<"actualizo con aumento el nodo que tenia "<<l<<" "<<r<<" con el valor de "<<x<<'\n';
            X[u] += x, T[u] += x;
            return;
        }
        if(r < i or j < l) return;

        ll m = (l + r) / 2;
        update(i, j, x, l, m, 2 * u + 1);
        update(i, j, x, m + 1, r, 2 * u + 2);
        T[u] = X[u] + max(T[2 * u + 1], T[2 * u + 2]);
    }
    ll query(ll i, ll j, ll l = 0, ll r = mxN, ll u = 0) {
        if(i <= l and r <= j) {
            return T[u];
        }
        if(r < i or j < l) return -1e6;
        ll m = (l + r) / 2;
        return X[u] + max(query(i, j, l, m, 2 * u + 1), query(i, j, m + 1, r, 2 * u + 2));
    }
} st;



ll ans = 1;
void solve(ll u, ll p) {
    st.update(I[u], E[u] - 1, 1);
    for(auto v: Rem[u])  {
        st.update(I[v], E[v] - 1, -1);
    }
    multiset<ll> S = {1};
    for(auto v: G[u]) {
        S.insert(st.query(I[v], E[v] - 1));
    }
    if(S.size() > 1) {
        ll best1 = *S.rbegin();
        ll best2 = *next(S.rbegin());
        ans = max(ans, best1 * best2);
    }
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        // id = 0;
        rep(u, n) G[u].clear(), Last[u].clear(), Rem[u].clear();
        ans = 1;
        
        rep(i, n - 1) {
            int p; cin>>p; p--;
            G[p].pb(i + 1);
        }
        rep(i, n) cin>>A[i], A[i]--;
        
        dfs(0, -1);
        for(int u = n - 1; u >= 0; u--) solve(u, -1);
        
        cout<<ans<<'\n';
        
    }




    return 0;
}