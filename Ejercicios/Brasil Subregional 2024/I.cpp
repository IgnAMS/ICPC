#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define pb push_back

const int mxN = 1000001;
ll mu[1000001];
ll sign[1000001];
ll Cont[1000001];

const ll MOD = 1e9+7;;
ll binpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // a lo mas 7 primos
    sign[1] = 1;
    for(int i = 2; i < mxN; i++) if(mu[i] == 0) {
        for(int j = i; j < mxN; j += i) {
            if(mu[j] == 0) mu[j] = i, sign[j] = -1;
            else sign[j] = -sign[j / mu[j]];
        }
    }

    int n; cin>>n;
    vl A(n);
    rep(i, n) {
        cin>>A[i];
        vl p;
        ll x = A[i];
        while(x != 1) {
            p.pb(mu[x]);
            ll d = mu[x];
            while(x % d == 0) x /= d;
        }
        rep(mask, (1<<p.size())) {
            ll mul = 1;
            rep(j, p.size()) if(mask & (1<<j)) mul *= p[j];
            Cont[mul] += 1;
        }
    }

    int q; cin>>q;
    while(q--) {
        ll x; cin>>x;
        vl p;
        while(x != 1) {
            p.pb(mu[x]);
            ll d = mu[x];
            while(x % d == 0) x /= d;
        }
        // cout<<"divisores: ";
        // for(auto d: p) cout<<d<<' '; cout<<'\n';
        ll ans = 0;
        rep(mask, (1<<p.size())) {
            ll mul = 1;
            rep(j, p.size()) if(mask & (1<<j)) mul *= p[j];
            ll cantidad = __builtin_popcount(mask);
            if(cantidad % 2 == 0) ans += Cont[mul];
            else ans -= Cont[mul];
        }
        // 2^{n - ans}
        cout<<binpow(2, ans)<<'\n';
    }

    
    return 0;
}