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

ll n, m, k, l;;
const ll MOD = 1e9+7;
struct Matrix {
    ll M[1000];
    Matrix() {
        memset(M, 0, sizeof(M));
        M[0] = 1;
    }
    Matrix operator*(Matrix& B) {
        Matrix res;
        res.M[0] = 0;
        rep(i, n) rep(j, n) {
            res.M[i] += M[(i - j + n) % n] * B.M[j] % MOD;
            res.M[i] %= MOD;
        }
        return res;
    }
    void print() {
        rep(i, 1) {
            rep(j, n) cout<<M[(j - i + n) % n]<<' '; cout<<'\n';
        }
        cout<<'\n';
    }
};

Matrix binpow(Matrix M, ll b) {
    Matrix res;
    while(b) {
        if(b & 1) res = res * M;
        M = M * M;
        b >>= 1;
    }
    return res;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll minv(ll x) { return binpow(x, MOD - 2); }


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k>>l;
    Matrix M;
    M.M[0] = 0;
    rep(i, k) {
        int x; cin>>x;
        M.M[x]++, M.M[(n - x)]++;
    }
    ll Y[l];
    rep(i, l) cin>>Y[i];

    rep(i, n) M.M[i] *= minv(2 * k);
    
    // M.print();
    // {
    //     Matrix Transition = M;
    //     rep(i, m + 3) {
    //         // Transition = Transition * M;
    //         Matrix Transition = binpow(M, i + 2);
    //         Transition.print();
    //     }
    // }

    Matrix Transition = binpow(M, m);
    ll ans = 0;
    rep(i, l) ans += Transition.M[Y[i]], ans %= MOD;
    cout<<ans<<'\n';

    return 0;
}