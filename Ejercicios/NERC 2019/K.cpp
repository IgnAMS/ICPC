#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repx(i, a, b) for(int i = a; i < b; i++)
#define pb push_back

int n;
const int mxN = 21;
vl F(mxN);
ll Factos[21];
map<pair<ll, vl>, ll> DP;
ll backtrack(ll i) {
    if(i == n) return 1;
    if(DP.count({i, F})) return DP[{i, F}];

    ll curr = 0;
    rep(j, i + 2) if(F[j]) {
        // la ultima posicion no puede ser un 0
        if(F[0] == n - i) continue;

        // cout<<"coloco un "<<j<<" en la posicion "<<i<<'\n';
        F[j]--;
        curr += backtrack(i + 1);
        F[j]++;
    }
    DP[{i, F}] = curr;
    return curr;
}

ll get_ans(ll xd) {
    ll ans = 1;
    ll acc = xd;
    for(int i = n; i >= 0; i--) if(F[i]) {
        // cerr<<n - i - acc - F[i]<<'\n';
        ll left = n - i + bool(i) - acc;

        if(left < 0 or left - F[i] < 0) {
            return 0;
        }

        ll aux = Factos[left] / Factos[left - F[i]];
        aux /= Factos[F[i]];
        ans *= aux;
        acc += F[i];
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    ll curr = 0;
    Factos[0] = 1;
    repx(i, 1, 21) Factos[i] = ll(i) * Factos[i - 1];
    while(t--) {
        ll x; cin>>x;
        ll ogx = x;
        vl A;
        rep(i, mxN) F[i] = 0;
        repx(i, 2, mxN) {
            A.pb(x % i);
            F[x % i]++;
            x /= i;
            if(x == 0) break;
        }
        n = A.size();
        // cerr<<ogx<<'\n';
        // for(auto u: A) cerr<<u<<' '; cerr<<'\n';
        ll ans = get_ans(0);
        if(F[0]) {
            F[0]--;
            ans -= get_ans(1);
            F[0]++;
        }
        // cerr<<"yahooo\n";
        // if(backtrack(0) != ans) cout<<"chutis: "<<ogx<<'\n';

        cout<<ans - 1<<'\n';

    }
}