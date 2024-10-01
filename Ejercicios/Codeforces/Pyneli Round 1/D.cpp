#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt


const ll M = 1e9+7;

ll mul(ll a, ll b, ll mod = M) { return (a * b) % mod; }
ll suma(ll a, ll b, ll mod = M) { return (a + b + 2 * mod) % mod; }

ll bpow(ll a, ll b, ll mod = M) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}

pll euclid(ll A, ll B) {
    if (!B) return {1, 0};
    pll p = euclid(B, A % B);
    return {p.ss, p.ff - (A / B) * p.ss};
}

ll minv(ll A, ll M) {
    pll p = euclid(A, M);
    assert(p.ff * A + p.ss * M == 1);
    return p.ff + (p.ff < 0) * M;
}

// By definition and euclid
const int mxN = 1e6+10;
ll F[mxN], IF[mxN];
ll choose(int n, int k) {
    if(k > n or n < 0 or k < 0) return 0;
    return mul(F[n], mul(IF[k], IF[n - k]), M);
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    F[0] = 1;
    repx(i, 1, mxN) F[i] = mul(i, F[i - 1]);
    if(k == 0) {
        cout<<bpow(3, n)<<'\n';
        return 0;
    }
    IF[mxN-1] = bpow(F[mxN-1], M - 2);
	for(ll i=mxN-2; i >= 0; i--) IF[i]=(IF[i+1] * (i+1))%M;
    ll ans = 0;
    for(int q = 1; q <= n and q <= 2 * k; q++) { 
        // cerr<<n - k<<' '<<(q + 1) / 2<<'\n';
        // cerr<<choose(2, 1)<<'\n';
        // cerr<<bpow(3, n - q)<<' '<<(q / 2 == 0? 1 : choose(k - 1, (q + 1) / 2 - 1))<<' '<<choose(n - k + 1 - 1, (q + 2) / 2 - 1)<<'\n';
        ll aux = bpow(3, n - q);
        aux = mul(aux, (q / 2 == 0? 1 : choose(k - 1, (q + 1) / 2 - 1)));
        aux = mul(aux, choose(n - k + 1 - 1, (q + 2) / 2 - 1));
        ans = suma(ans, aux);
    }
    cout<<ans<<'\n';
    
    return 0;
}