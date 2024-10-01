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
const ll mxN = 1e6 + 5;
ll cant[mxN], u[mxN];
vl D[mxN];

ll coprimes(ll x) {
    ll ans = 0;
    for(auto d: D[x]) ans += cant[d] * u[d];
    return ans;
}

void update(ll a, ll x) {
    for(auto d: D[a]) cant[d] += x;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // gcd(a, b) == g <-> a y b son multiplos de g y para todo primo p a y b no son multiplos de p * g
    // dado g fijo puedo encontrar todos los pares tales que a y b cooprimos?
    // dado g fijo y a fijo puedo encontrar todos los b's tales que a y b son coorpimos? 

    for(int i = 1; i < mxN; i++) {
        for(int j = i; j < mxN; j += i) D[j].pb(i);
        if(i == 1) u[i] = 1;
        else if((i / D[i][1]) % D[i][1] == 0) u[i] = 0;
        else u[i] = -u[i / D[i][1]];
        
    }


    int t; cin>>t;
    while(t--) {
        ll n, m; cin>>n>>m;
        rep(i, n + 1) cant[i] = 0; 

        vl C(n + 2, 0);
        C[n + 1] = 0;
        // C[g] = cantidad de pares (a, b) que tienen gcd(a, b) = g
        for(int g = n; g >= 2; g--) {
            C[g] = C[g + 1];
            ll prev = n / (g + 1);
            while(n / g > prev) {
                C[g] += coprimes(prev + 1);
                update(prev + 1, 1);
                prev++;
            }
        }

        ll ans = 0;
        for(ll g = min(n, 6722LL); g >= 2; g--) {
            ll x = min(C[g] / (g - 1), m / (g - 1));
            ans += x * g;
            m -= x * (g - 1);
        }
        
        if(m == 0) cout<<ans<<'\n';
        else cout<<"-1\n";
    }


    return 0;
}