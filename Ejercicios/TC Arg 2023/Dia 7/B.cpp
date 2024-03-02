#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define ff first
#define ss second
#define rep(i, n) for(int i = 0; i < n; i++)
#define repx(i, a, b) for(int i = a; i < b; i++)


int main() {
    int n, m; cin>>n>>m;
    multiset<pll> S;
    ll unos = 0;
    vl suma(m, 0);
    vector<multiset<ll>> S2(m, multiset<ll>());
    rep(i, n) {
        ll p, c; cin>>p>>c; p--;
        suma[p]++;
        if(p != 0) {
            S.insert({c, p});
            S2[p].insert(c);
        }
    }
    ll mx = 0;
    ll ans = 0;
    repx(i, 1, m) mx = max(mx, suma[i]);
    while(mx >= suma[0]) {
        // Si o si me conviene tomarlo ya que corresponde a uno de los maximos
        if(mx == suma[S.begin()->ss]) {
            ll p = S.begin()->ss, valor = S.begin()->ff;
            ans += valor;
            suma[p]--;
            S2[p].erase(S2[p].find(valor));
            suma[0]++;
            
        }
        else {
            ll min_max_p = 0, indmin_max;
            repx(p, 1, m) {
                if(S2[p].size() == mx and min_max_p < *S2[p].begin()) {
                    min_max_p = *S2[p].begin();
                    indmin_max = p;
                }
            }
            // Deben haber dos elementos
            ll v1 = S.begin()->ff, p1 = S.begin()->ss;
            ll v2 = next(S.begin())->ff, p2 = next(S.begin())->ss;
            // Saco ambos elementos
            if(suma[0] + 1 > mx) {
                ans += v1;
                S.erase(S.begin());
                S2[p1].erase(S2[p1].find(v1));
                suma[p1]--;
                suma[0]++;
            }
            else if(v1 + v2 <= min_max_p) {
                ans += v1 + v2;
                S.erase(S.begin());
                S.erase(S.begin());
                S2[p1].erase(S2[p1].find(v1));
                S2[p2].erase(S2[p2].find(v2));
                suma[p1]--, suma[p2]--;
                suma[0] += 2;
            }
            else {
                ans += min_max_p;
                S.erase(S.find({min_max_p, indmin_max}));
                S2[indmin_max].erase(S2[indmin_max].find(min_max_p));
                suma[indmin_max]--;
                suma[0]++;
            }
        }
        mx = 0;
        repx(p, 1, m) mx = max(mx, (ll)S2[p].size());
    }
    // repx(p, 1, m) {
    //     for(auto u: S2[p]) cout<<u<<' '; cout<<'\n';
    // }
    // cout<<suma[0]<<' '<<mx<<'\n';
    cout<<ans<<'\n';

    return 0;
}