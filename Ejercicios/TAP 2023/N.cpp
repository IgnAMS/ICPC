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

// Opciones: 
// [1 0 0 1]
// [0 1 1 0]
// [2 0 1 0]
// [1 2 0 0]
// [3 1 0 0]
// [5 0 0 0]

// puedo hacer busqueda binaria sobre la respuesta
// para la busqueda binaria debo asignar los pesos y ver si es factible

vl A[] = {
    {1, 0, 0, 1},
    {0, 1, 1, 0},
    {1, 2, 0, 0},
    {2, 0, 1, 0},
    {3, 1, 0, 0},
    {5, 0, 0, 0}
};

ll ans = 0;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vl C(5, 0);
    rep(i, n) {
        ll x; cin>>x;
        C[x % 5]++;
    }
    
    ans += C[0];

    // Elimino [1 0 0 1]
    ll k = min(C[1], C[4]);
    C[1] -= k, C[4] -= k, ans += k;

    // Elimino los [0 1 1 0]
    k = min(C[2], C[3]);
    C[2] -= k, C[3] -= k, ans += k;

    // Me quedan C[2] y por ende no me quedan C[3]
    if(C[2]) {
        // [1 2 0 0]
        // [3 1 0 0]
        ll best = 0;
        for(ll k1 = 0; k1 <= min(C[1] / 3, C[2]); k1++) {
            ll k2 = min(C[1] - k1 * 3, (C[2] - k1) / 2);
            ll k3 = (C[1] - k1 * 3 - k2) / 5;
            // cout<<k1<<' '<<k2<<' '<<k3<<'\n';
            best = max(best, k1 + k2 + k3);
        }
        ans += best;
    }
    // Caso contrario me quedan C[3]
    else {
        // [2 0 1 0]
        ll k1 = min(C[1] / 2, C[3]);
        ll k2 = (C[1] - k1 * 2) / 5;
        ans += k1 + k2;
    }

    cout<<ans<<'\n';

    return 0;
}