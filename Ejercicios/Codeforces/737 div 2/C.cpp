#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ul;
typedef pair<ll,ll> pll;
#define ff first
#define ss second

const ll MOD = 1e9 + 7;
const int MAXN = 1000002;

// MODULAR
inline ll add(ll x, ll y, ll M = MOD) { return (x + y) % M; }
inline ll mul(ll x, ll y, ll M = MOD) { return (x * y) % M; }

// EUCLID
// find (x, y) such that Ax + By = gcd(A, B), and |Ax|, |By| <= AB/gcd(A, B)
pll euclid(ll A, ll B){
    if (!B) return {1, 0};
    pll p = euclid(B, A % B);
    return {p.ss, p.ff - (A / B) * p.ss};
}

// find x in [0, M) such that Ax = 1 mod M
ll minv(ll A, ll M){
    pll p = euclid(A, M);
    assert(p.ff * A + p.ss * M == 1);
    return p.ff + (p.ff < 0) * M;
}

// By definition and euclid
ll F[MAXN];
ll choose(int n, int k){
    return mul(F[n], minv(mul(F[k], F[n - k]), MOD));
}


int main(){
    int t; cin>>t;
    vector<int> A(1000000); A[0] = 1; // ind -> 2 ^ ind
    repx(i, 1, 1000000) A[i] = mul(A[i - 1], 2, MOD);
    F[0] = 1;
    repx(i, 1, MAXN) F[i] = mul(i, F[i - 1], MOD);
    while(t--){
        int n, k; cin>>n>>k;
        if(k == 0) { cout<<1<<'\n'; continue; }
        ll ans = 0;
        rep(i, n/2) ans = add(choose(n, 2 * i + (n % 2)), ans, MOD); 
        if(n % 2) ans = add(ans, 1, MOD);
        ans = mul(ans, (A[k] - 1), MOD);
        cout<<add(ans, 1, MOD)<<'\n'; // le agrego el caso base de 0
    }


    return 0;
}