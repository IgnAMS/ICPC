#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

using namespace std;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define pb push_back
// g++ -O2 A.cpp && time ./a.out <input.txt> output.txt

const int mxN = 1e6+6;

struct ST {
    pll T[4 * mxN];
    ll L[4 * mxN];
    void push(ll l, ll r, ll u, ll x) {
        T[u].first += L[u] + x;
        if(l != r) {
            L[2 * u + 1] += L[u] + x;
            L[2 * u + 2] += L[u] + x;
        }
        L[u] = 0;
    }


    void update(ll i, ll j, ll x, ll l, ll r, ll u) {
        push(l, r, u, 0);
        if(l == r) T[u].second = l;
        if(i <= l and r <= j) {
            push(l, r, u, x);
            return;
        }
        if(r < i or j < l) return;

        int m = (l + r) / 2;
        update(i, j, x, l, m, 2 * u + 1), update(i, j, x, m + 1, r, 2 * u + 2);
        T[u] = min(T[2 * u + 1], T[2 * u + 2]);
    }

    pll query(ll i, ll j, ll l, ll r, ll u) {
        push(l, r, u, 0);
        if(i <= l and r <= j) return T[u];
        if(r < i or j < l) return {mxN, mxN};
        int m = (l + r) / 2;
        return min(query(i, j, l, m, 2 * u + 1), query(i, j, m + 1, r, 2 * u + 2));
    }
} st;



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll A[n]; 
    ll mxa = 0, suma = 0;
    rep(i, n) {
        cin>>A[i];
        mxa = max(mxa, A[i]), suma += A[i];
    }

    vl Ans(suma + 1, 1);
    repx(i, mxa, suma + 1) {
        st.update(i, i, i, 0, suma, 0);
    }

    ll curr = 0;
    rep(i, n) {
        st.update(mxa, suma, -A[i], 0, suma, 0);
        curr += A[i];
        auto [x, id] = st.query(mxa, curr, 0, suma, 0);
        ll cont = 0;
        while(x < 0) {
            Ans[id]++;
            // x + y = id - A[i]
            // -> y = id - A[i] - x
            st.update(id, id, id - A[i] - x, 0, suma, 0);
            tie(x, id) = st.query(mxa, curr, 0, suma, 0);
        }
    }

    int q; cin>>q;
    while(q--) {
        int t; cin>>t;
        if(t < mxa) cout<<"Impossible\n";
        else cout<<Ans[t]<<'\n';
    }

    return 0;
}


