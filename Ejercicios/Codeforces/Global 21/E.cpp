#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
typedef pair<ll, ll> pll;
typedef unsigned long long ul;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt


pll euclid(ll A, ll B)
{
    if (!B) return {1, 0};
    pll p = euclid(B, A % B);
    return {p.ss, p.ff - (A / B) * p.ss};
}

// find x in [0, M) such that Ax = 1 mod M
ll minv(ll A, ll M)
{
    pll p = euclid(A, M);
    assert(p.ff * A + p.ss * M == 1);
    return p.ff + (p.ff < 0) * M;
}

const ll MOD = 1e9 + 7;

inline ll add(ll x, ll y, ll M = MOD) { return (x + y) % M; }
inline ll mul(ll x, ll y, ll M = MOD) { return (x * y) % M; }


const ll MAXN = 1e6;
// By definition and euclid
ll F[MAXN];
ll choose(int n, int k) {
    return mul(F[n], minv(mul(F[k], F[n - k]), MOD));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    vi A(n + 1); rep(i, n + 1) cin>>A[i];
    F[0] = 1;
    repx(i, 1, 1e6) F[i] = mul(F[i - 1], i);

    ll ans = 0;
    rep(i, n + 1) if(A[i]) ans = add(ans, choose(A[i] + i, A[i] - 1));
    cout<<ans<<'\n';


    return 0;
}