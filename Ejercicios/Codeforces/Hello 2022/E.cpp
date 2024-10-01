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

const int mxN = 1e5+20;
const ll INF = 1e8;

struct ST {
    ll T[4 * mxN], L[4 * mxN];

    void push(ll l, ll r, ll u, ll x) {
        T[u] += x;
        L[u] = 0;
        if(l != r) {
            L[2 * u + 1] += x;
            L[2 * u + 2] += x;
        }
    }
    
    void update(ll i, ll j, ll x, ll l = 0, ll r = mxN, ll u = 0) {
        push(l, r, u, L[u]);
        if(i <= l and r <= j) {
            push(l, r, u, x);
            return;
        }
        if(r < i or j < l) return;
        ll m = (l + r) / 2;
        update(i, j, x, l, m, 2 * u + 1);
        update(i, j, x, m + 1, r, 2 * u + 2);
        T[u] = min(T[2 * u + 1], T[2 * u + 2]);
    }

    ll query(ll i, ll j, ll l = 0, ll r = mxN, ll u = 0) {
        push(l, r, u, L[u]);
        if(i <= l and r <= j) return T[u];
        if(r < i or j < l) return INF;
        ll m = (l + r) / 2;
        return min(query(i, j, l, m, 2 * u + 1), query(i, j, m + 1, r, 2 * u + 2));
    }
} st;



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll n, m; cin>>n>>m;
        ll A[n];
        rep(i, n) {
            cin>>A[i];
            st.update(0, A[i], 1);
        }
        vl X[m];
        ll K[m], S[m];
        rep(i, m) {
            S[i] = 0;
            cin>>K[i];
            X[i].resize(K[i]);
            rep(j, K[i]) cin>>X[i][j], S[i] += X[i][j]; 
            ll val = (S[i] + K[i] - 1) / K[i];
            st.update(0, val, -1);
        }

        string ans = "";
        rep(i, m) {
            ll val = (S[i] + K[i] - 1) / K[i];
            st.update(0, val, 1);
            rep(j, K[i]) {
                ll new_val = (S[i] - X[i][j] + K[i] - 2) / (K[i] - 1);
                st.update(0, new_val, -1);
                ans += '0' + bool(st.query(0, 100000) >= 0);
                st.update(0, new_val, 1);
            }
            st.update(0, val, -1);
        }

        rep(i, n) st.update(0, A[i], -1);
        rep(i, m) {
            ll val = (S[i] + K[i] - 1) / K[i];
            st.update(0, val, 1);
        }

        cout<<ans<<'\n';
    }

    return 0;
}