#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
typedef long long ll;
typedef vector<ll> vl;

const int mxN = 5e5+20;
ll Inv[mxN];
struct ST {
    ll S[4 * mxN], C[4 * mxN];
    void update(ll i, ll x, ll l, ll r, ll u) {
        if(l == r) {
            C[u] += x;
            S[u] += x * Inv[i];
        }
        else {
            ll m = (l + r) / 2;
            if(i <= m) update(i, x, l, m, 2 * u + 1);
            else update(i, x, m + 1, r, 2 * u + 2);
            C[u] = C[2 * u + 1] + C[2 * u + 2];
            S[u] = S[2 * u + 1] + S[2 * u + 2];
        }
    }
    ll mediana(ll i, ll l, ll r, ll u) {
        if(l == r) return l;

        ll m = (l + r) / 2;
        if(C[2 * u + 1] >= i) return mediana(i, l, m, 2 * u + 1);
        return mediana(i - C[2 * u + 1], m + 1, r, 2 * u + 2);
    } 
    ll contar(ll i, ll j, ll l, ll r, ll u) {
        if(i <= l and r <= j) return C[u];
        if(r < i or j < l) return 0;
        ll m = (l + r) / 2;
        return contar(i, j, l, m, 2 * u + 1) + contar(i, j, m + 1, r, 2 * u + 2);
    }
    ll suma(ll i, ll j, ll l, ll r, ll u) {
        if(i <= l and r <= j) return S[u];
        if(r < i or j < l) return 0;
        ll m = (l + r) / 2;
        return suma(i, j, l, m, 2 * u + 1) + suma(i, j, m + 1, r, 2 * u + 2);
    }
} st;



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll n, k; cin>>n>>k;
        rep(i, 4 * n + 20) st.S[i] = st.C[i] = 0;
        ll A[n];
        set<ll> S;
        rep(i, n) {
            cin>>A[i];
            A[i] -= i;
            S.insert(A[i]);
        } 
        vl X;
        unordered_map<ll, ll> mp;
        mp.reserve(n);
        for(auto u: S) {
            Inv[mp.size()] = u;
            mp[u] = mp.size();
        }

        ll r = -1;
        ll ans = 1;
        rep(i, n) {
            if(r < i) {
                st.update(mp[A[i]], 1, 0, n, 0);
                r = i;
            }
            bool oc = 1;
            while(oc and r <= n - 2) {
                st.update(mp[A[r + 1]], 1, 0, n, 0);
                ll largo = (r + 1) - i + 1;

                if(largo & 1) {
                    ll mediana = st.mediana((largo + 1) / 2, 0, n, 0);
                    ll count_left = st.contar(0, mediana, 0, n, 0);
                    ll count_right = st.contar(mediana, n, 0, n, 0);
                    ll sum_left = st.suma(0, mediana, 0, n, 0);
                    ll sum_right = st.suma(mediana, n, 0, n, 0);
                    ll val_med = Inv[mediana];

                    if(val_med * count_left - sum_left + sum_right - val_med * count_right > k) {
                        st.update(mp[A[r + 1]], -1, 0, n, 0);
                        oc = 0;
                    }
                    else r++;
                }
                else {
                    ll mediana = st.mediana((largo + 1) / 2, 0, n, 0);
                    ll count_left = st.contar(0, mediana, 0, n, 0);
                    ll count_right = st.contar(mediana, n, 0, n, 0);
                    ll sum_left = st.suma(0, mediana, 0, n, 0);
                    ll sum_right = st.suma(mediana, n, 0, n, 0);
                    ll val_med = Inv[mediana];
                    
                    ll mediana2 = st.mediana((largo + 1) / 2 + 1, 0, n, 0);
                    ll count_left2 = st.contar(0, mediana2, 0, n, 0);
                    ll count_right2 = st.contar(mediana2, n, 0, n, 0);
                    ll sum_left2 = st.suma(0, mediana2, 0, n, 0);
                    ll sum_right2 = st.suma(mediana2, n, 0, n, 0);
                    ll val_med2 = Inv[mediana2];

                    if(val_med * count_left - sum_left + sum_right - val_med * count_right <= k) {
                        r++;
                    }
                    else if(val_med2 * count_left2 - sum_left2 + sum_right2 - val_med2 * count_right2 <= k) {
                        r++;
                    }
                    else {
                        st.update(mp[A[r + 1]], -1, 0, n, 0);
                        oc = 0;
                    }
                }
            }
            // cout<<"el maximo de "<<i<<" es "<<r<<'\n';
            ans = max(ans, r - i + 1);
            st.update(mp[A[i]], -1, 0, n, 0);
        }
        cout<<ans<<'\n';

    }


    return 0;
}