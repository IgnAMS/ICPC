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
    void update(ll i, ll x, ll l = 0, ll r = mxN, ll u = 0) {
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
    ll mediana(ll i, ll l = 0, ll r = mxN, ll u = 0) {
        if(l == r) return l;

        ll m = (l + r) / 2;
        if(C[2 * u + 1] >= i) return mediana(i, l, m, 2 * u + 1);
        return mediana(i - C[2 * u + 1], m + 1, r, 2 * u + 2);
    } 
    ll contar(ll i, ll j, ll l = 0, ll r = mxN, ll u = 0) {
        if(i <= l and r <= j) return C[u];
        if(r < i or j < l) return 0;
        ll m = (l + r) / 2;
        return contar(i, j, l, m, 2 * u + 1) + contar(i, j, m + 1, r, 2 * u + 2);
    }
    ll suma(ll i, ll j, ll l = 0, ll r = mxN, ll u = 0) {
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
        rep(i, 4 * n + 10) st.S[i] = st.C[i] = 0;
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
        vl C(n + 1, 0);
        ll mediana = 0, sum_right = 0, sum_left = 0, count_right = 0, count_left = 0;

        rep(i, n) {
            if(r < i) {
                // st.update(mp[A[i]], 1);
                mediana = mp[A[i]];
                C[mp[A[i]]]++;
                sum_right = 0, sum_left = 0, count_right = 0, count_left = 0;
                r = i;
            }
            bool oc = 1;
            while(oc and r <= n - 2) {
                // Actualizaciones
                st.update(mp[A[r + 1]], 1);
                C[mp[A[r + 1]]]++;
                
                // debo mover la medina a la derecha
                if(st.contar(0, mediana) < (n + 1) / 2) {
                    sum_left += Inv[mediana] * C[mediana];
                    sum_right -= Inv[mediana + 1] * C[mediana + 1];
                    count_left += C[mediana];
                    count_right -= C[mediana];
                    mediana = st.mediana((n + 1) / 2);
                }
                else if(st.contar(0, mediana) > (n + 1) / 2) {
                    sum_left -= Inv[mediana] * C[mediana];
                    sum_right += Inv[mediana + 1] * C[mediana + 1];
                    count_left -= C[mediana];
                    count_right += C[mediana];
                    mediana = st.mediana((n + 1) / 2);
                }
                ll largo = (r + 1) - i + 1;

                if(largo & 1) {
                    // ll mediana = st.mediana((largo + 1) / 2);
                    // ll count_left = st.contar(0, mediana - 1);
                    // ll count_right = st.contar(mediana + 1, n);
                    // ll sum_left = st.suma(0, mediana - 1);
                    // ll sum_right = st.suma(mediana + 1, n);
                    // ll val_med = Inv[mediana];
                    ll val_med = Inv[mediana];

                    if(val_med * count_left - sum_left + sum_right - val_med * count_right > k) {
                        // Actualizaciones
                        st.update(mp[A[r + 1]], -1);
                        C[mp[A[r + 1]]]++;
                        if(st.contar(0, mediana) < (n + 1) / 2) {
                            sum_left += Inv[mediana] * C[mediana];
                            sum_right -= Inv[mediana + 1] * C[mediana + 1];
                            count_left += C[mediana];
                            count_right -= C[mediana];
                            mediana = st.mediana((n + 1) / 2);
                        }
                        else if(st.contar(0, mediana) > (n + 1) / 2) {
                            sum_left -= Inv[mediana] * C[mediana];
                            sum_right += Inv[mediana + 1] * C[mediana + 1];
                            count_left -= C[mediana];
                            count_right += C[mediana];
                            mediana = st.mediana((n + 1) / 2);
                        }
                        oc = 0;
                    }
                    else r++;
                }
                else {
                    // ll mediana = st.mediana((largo + 1) / 2);
                    // ll count_left = st.contar(0, mediana - 1);
                    // ll count_right = st.contar(mediana + 1, n);
                    // ll sum_left = st.suma(0, mediana - 1);
                    // ll sum_right = st.suma(mediana + 1, n);
                    ll val_med = Inv[mediana];
                    
                    
                    bool oc2 = 0;
                    if(val_med * count_left - sum_left + sum_right - val_med * count_right <= k) {
                        r++;
                        oc2 = 1;
                    }

                    ll mediana2 = st.mediana((largo + 1) / 2 + 1);
                    ll count_left2 = st.contar(0, mediana2 - 1);
                    ll count_right2 = st.contar(mediana2 + 1, n);
                    ll sum_left2 = st.suma(0, mediana2 - 1);
                    ll sum_right2 = st.suma(mediana2 + 1, n);
                    ll val_med2 = Inv[mediana2];


                    if(!oc2 and val_med2 * count_left2 - sum_left2 + sum_right2 - val_med2 * count_right2 <= k) {
                        r++;
                        oc2 = 1;
                    }


                    if(!oc2) {
                        // Actualizaciones
                        st.update(mp[A[r + 1]], -1);
                        C[mp[A[r + 1]]]++;
                        if(st.contar(0, mediana) < (n + 1) / 2) {
                            sum_left += Inv[mediana] * C[mediana];
                            sum_right -= Inv[mediana + 1] * C[mediana + 1];
                            count_left += C[mediana];
                            count_right -= C[mediana];
                            mediana = st.mediana((n + 1) / 2);
                        }
                        else if(st.contar(0, mediana) > (n + 1) / 2) {
                            sum_left -= Inv[mediana] * C[mediana];
                            sum_right += Inv[mediana + 1] * C[mediana + 1];
                            count_left -= C[mediana];
                            count_right += C[mediana];
                            mediana = st.mediana((n + 1) / 2);
                        }
                        oc = 0;
                    }
                }
            }
            // cout<<"el maximo de "<<i<<" es "<<r<<'\n';
            ans = max(ans, r - i + 1);
            st.update(mp[A[i]], -1);
        }
        cout<<ans<<'\n';
    }

    return 0;
}

