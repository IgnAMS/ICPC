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

const int mxN = 1e5;
struct ST {
    vl T;
    int n;
    ST(vl &A, ll N) {
        n = N;
        T.resize(4 * n, 0);
        build(A, 0, n - 1, 0);
    }
    void build(vl& A, ll l, ll r, ll u) {
        if(l == r) T[u] = A[l];
        else {
            ll m = (l + r) / 2;
            build(A, l, m, 2 * u + 1);
            build(A, m + 1, r, 2 * u + 2);
            T[u] = min(T[2 * u + 1], T[2 * u + 2]);
        }
    }
    ll query(ll i, ll j) { return query(i, j, 0, n - 1, 0); }
    ll query(ll i, ll j, ll l, ll r, ll u) {
        if(i <= l and r <= j) return T[u];
        if(r < i or j < l) return 1e10;
        ll m = (l + r) / 2;
        return min(query(i, j, l, m, 2 * u + 1), query(i, j, m + 1, r, 2 * u + 2));
    }
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vl A(2 * n); 
    ll mx = 0, idmax = 0;
    rep(i, n) {
        cin>>A[i];
        A[n + i] = A[i];
        if(A[i] > A[idmax]) mx = A[i], idmax = i;
    }
    bool infinite = 1;
    rep(i, n) {
        if(A[i] < (A[idmax] + 1) / 2) infinite = 0;
    }
    if(infinite) {
        rep(i, n) cout<<"-1 "; 
        cout<<'\n';
        return 0;
    }

    ST st(A, 2 * n);
    vl Ans(2 * n);
    vector<pll> S; S.reserve(n + 1);
    S.pb({2 * n, 1e10});
    for(int i = idmax; i >= 0; i--) {
        while(A[i] > S.back().ss) S.pop_back();
        ll l = i + 1, r = S.back().ff;
        while(l < r) {
            ll m = (l + r) / 2;
            if(st.query(l, m) < (A[i] + 1) / 2) r = m;
            else l = m + 1;
        }
        if(l == S.back().ff) Ans[i] = Ans[l] + l - i;
        else Ans[i] = l - i;
        Ans[n + i] = Ans[i];
        S.push_back({i, A[i]});
    }
    repx(i, 1, S.size() + 1) S[i].ff += n;
    // for(auto [a, b]: S) cout<<a<<' '<<b<<'\n';

    for(int i = n - 1; i > idmax; i--) {
        while(A[i] > S.back().ss) S.pop_back();
        ll l = i + 1, r = S.back().ff;
        while(l < r) {
            ll m = (l + r) / 2;
            if(st.query(l, m) < (A[i] + 1) / 2) r = m;
            else l = m + 1;
        }
        if(l == S.back().ff) Ans[i] = Ans[l] + l - i;
        else Ans[i] = l - i;
        S.push_back({i, A[i]});
    }

    rep(i, n) cout<<Ans[i]<<' '; cout<<'\n';

    return 0;
}