    #pragma GCC optimize("Ofast")
    #include<bits/stdc++.h>
    using namespace std;

    #define ll long long 
    #define rep(i, n) for(int i = 0; i<(int)n; ++i)
    typedef vector<ll> vl;
    typedef pair<ll, ll> pll;
    #define ff first
    #define ss second


    // #pragma GCC target("avx,avx2,fma") // could make sigill runtime error

    ll n, x, y;
    ll ans = 1e17;
    vector<pll> V(4);

    void solve(int i, int j, ll d) {
        if(d >= 14) return;
        if(i == x and j == y) {
            ans = min(ans, d);
            return;
        }
        for(auto &v: V) {
            if(i & 1 or j & 1) continue;
            ll ni = (i + v.ff) / 2, nj = (j + v.ss) / 2;
            solve(ni, nj, d + 1);
        }

    }

    int main(){
        ios::sync_with_stdio(0); cin.tie(0);
        cin >> n >> x >> y;
        ll d = 0;
        ll n2 = (1<<n);
        while(x != n2 / 2 and y != n2 / 2) {
            // cout<<x<<' '<<y<<' '<<n2/2<<'\n';
            if(x >= n2 / 2) x = n2 - x;
            if(y >= n2 / 2) y = n2 - y;
            n2 /= 2;
            d++;
        }
        cout<<d<<'\n';
    }