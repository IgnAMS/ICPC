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

const int mxN = 1e5+5;
struct ST {
    ll T[4 * mxN], L[4 * mxN];
    void push(int l, int r, int u, ll x) {
        T[u] += (r - l + 1) * (x + L[u]);
        if(l != r) {
            int m = (l + r) / 2;
            L[2 * u + 1] += L[u] + x;
            L[2 * u + 2] += L[u] + x;
        }
        L[u] = 0;
    }

    void update(int i, int j, ll x, int l, int r, int u) {
        push(l, r, u, 0);
        if(i <= l and r <= j) {
            push(l, r, u, x);
            return;
        }
        if(r < i or j < l) return;
        int m = (l + r) / 2;
        update(i, j, x, l, m, 2 * u + 1), update(i, j, x, m + 1, r, 2 * u + 2);
        T[u] = T[2 * u + 1] + T[2 * u + 2];
        return;
    }

    ll query(int i, int j, int l, int r, int u) {
        push(l, r, u, 0);
        if(i <= l and r <= j) return T[u];
        if(r < i or j < l) return 0;
        int m = (l + r) / 2;
        return query(i, j, l, m, 2 * u + 1) + query(i, j, m + 1, r, 2 * u + 2);
    }
} st;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    ll P[n]; 
    rep(i, n) cin>>P[i], P[i]--;
    while(q--) {
        ll t; cin>>t;
        if(t <= 1) {
            ll l, r, c; cin>>l>>r>>c; l--, r--;
            if(t == 0) st.update(l, r, c, 0, n - 1, 0);
            else {
                repx(i, l, r + 1) st.update(P[i], P[i], c, 0, n - 1, 0);
            }
        }
        else {
            ll l, r; cin>>l>>r; l--, r--;
            if(t == 2) {
                cout<<st.query(l, r, 0, n - 1, 0)<<'\n';
            }
            else {
                ll aux = 0;
                repx(i, l, r + 1) aux += st.query(P[i], P[i], 0, n - 1, 0);
                cout<<aux<<'\n';
            }
        }
    }





    return 0;
}