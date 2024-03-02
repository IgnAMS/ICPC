#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
typedef vector<db> vd;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

#define PI acos(-1.0L)

typedef complex<double> C;
void fft(vector<C> &a) {
    int n = a.size(), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1);
    for (static int k = 2; k < n; k *= 2)
    {
        R.resize(n); rt.resize(n);
        auto x = polar(1.0L, PI / k);
        repx(i, k, 2 * k) rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
    }
    vl rev(n);
    rep(i, n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2) for (int i = 0; i < n; i += 2 * k) rep(j, k)
    {
        auto x = (double *)&rt[j + k], y = (double *)&a[i + j + k];
        C z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);
        a[i + j + k] = a[i + j] - z, a[i + j] += z;
    }
}

vl convMod(const vl &a, const vl &b, ll M) {
    if (a.empty() || b.empty()) return {};
    vl res(a.size() + b.size() - 1);
    int B = 32 - __builtin_clz(res.size()), n = 1 << B, cut = int(sqrt(M));
    vector<C> L(n), R(n), outs(n), outl(n);
    rep(i, a.size()) L[i] = C((int)a[i] / cut, (int)a[i] % cut);
    rep(i, b.size()) R[i] = C((int)b[i] / cut, (int)b[i] % cut);
    fft(L), fft(R);
    rep(i, n)
    {
        int j = -i & (n - 1);
        outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
        outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
    }
    fft(outl), fft(outs);
    rep(i, res.size())
    {
        ll av = ll(real(outl[i]) + .5), cv = ll(imag(outs[i]) + .5);
        ll bv = ll(imag(outl[i]) + .5) + ll(real(outs[i]) + .5);
        res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
    }
    return res;
}


ll mod = 998244353;
ll binpow(ll a, ll b, ll M=mod) {
    if(a == 0) return 1;
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}

ll minv(ll a, ll M=mod) {
    return binpow(a, M-2);
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k; cin>>n>>k; n++;
    vl A(n); rep(i, n) cin>>A[i];
    vl B(n); rep(i, n) cin>>B[i];
    if(k == 0) {
        rep(i, n) cout<<(A[i] + B[i]) % mod<<' '; 
        cout<<'\n';
        return 0;
    }
    if(k < 0) {
        swap(A, B);
        k = -k;
    }

    ll kp[n]; kp[0] = 1;
    repx(i, 1, n) kp[i] = (kp[i - 1] * k) % mod;
    
    ll Fact[n]; Fact[0] = 1; 
    repx(i, 1, n) Fact[i] = (Fact[i - 1] * (ll)i) % mod;

    vl FA1(n); 
    rep(i, n) FA1[i] = ((Fact[i] * kp[i] % mod) * A[i]) % mod;
    reverse(FA1.begin(), FA1.end());

    vl FA2(n);
    rep(i, n) FA2[i] = minv(Fact[i]);
    
    vl convA = convMod(FA1, FA2, mod);
    vl A2(n);


    rep(i, n) A2[i] = (convA[n - i - 1] * minv(Fact[i]) % mod) * minv(kp[i]) % mod; 
    // rep(i, n) cout<<A2[i]<<' '; cout<<'\n';

    vl FB1(n); 
    rep(i, n) {
        FB1[i] = ((Fact[i] * kp[i] % mod) * B[i]) % mod;    
        if(i % 2 == 0) FB1[i] = (-FB1[i] + mod) % mod;
    }   
    reverse(FB1.begin(), FB1.end());
    vl FB2(n);
    rep(i, n) FB2[i] = minv(Fact[i]);
    vl convB = convMod(FB1, FB2, mod);

    vl B2(n);
    rep(i, n) {
        B2[i] = convB[n - i - 1] * minv(Fact[i]) % mod * minv(kp[i]) % mod; 
        if(i % 2 == 0) B2[i] = (-1 * B2[i] + mod) % mod;
    }
    // rep(i, n) cout<<B2[i]<<' '; cout<<'\n';

    rep(i, n) {
        // cout<<A2[i]<<' '<<B2[i]<<'\n';
        cout<<(A2[i] + B2[i] + 2 * mod) % mod<<' '; // cout<<'\n';
    }
    return 0;
}