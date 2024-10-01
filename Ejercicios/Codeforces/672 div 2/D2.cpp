#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef unsigned long long ul;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt



const ll MOD = 998244353;
const int MAXN = 1000000;

// find (x, y) such that Ax + By = gcd(A, B), and |Ax|, |By| <= AB/gcd(A, B)
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

inline ll add(ll x, ll y, ll M = MOD) { return (x + y) % M; }
inline ll mul(ll x, ll y, ll M = MOD) { return (x * y) % M; }

ll binPow(ll a, ll b, const ll M)
{
    if (b == 0) return 1;
    ll r = binPow(a, b / 2, M); r = mul(r, r, M);
    return (b & 1) ? mul(r, a, M) : r;
}

// If multiplication goes over ll

ul modMul(ul a, ul b, const ul M)
{
    ll r = a * b - M * (ul)((db)a * b / M);
    return r + ((r < 0) - (r >= (ll)M)) * M;
}

ul modPow(ul a, ul b, const ul M)
{
    if (b == 0) return 1;
    ul r = modPow(a, b / 2, M); r = modMul(r, r, M);
    return b & 1 ? modMul(r, a, M) : r;
}

// By definition and euclid
ll F[MAXN];
ll choose(int n, int k)
{
    return mul(F[n], minv(mul(F[k], F[n - k]), MOD));
}

// Multinomial Coefficient
ll multinomial(vector<int> K)
{
    ll n = 0, ans = 1;
    for (int k : K) n += k, ans = mul(ans, choose(n, k));
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    vector<pll> A(2 * n); 
    rep(i, n) {
        cin>>A[2 * i].ff>>A[2 * i + 1].ff;
        A[2 * i].ss = 0, A[2 * i + 1].ss = 1;
    }
    sort(A.begin(), A.end());
    ll cont = 0, ans = 0;
    F[0] = 1;
    repx(i, 1, 1000000) F[i] = modMul(F[i - 1], i, MOD);
    
    rep(i, 2 * n) {
        if(A[i].ss == 1) { cont--; continue; }
        ll x = A[i].ff, s = 0;
        while(i < 2 * n and A[i].ss == 0 and A[i].ff == x) i++, cont++, s++;
        i--;
        if(cont >= k) {
            ans = (ans + choose(cont, k) - (cont - s >= k? choose(cont - s, k): 0) + MOD) % MOD;
            // cout<<x<<": "<<choose(cont, k) - (cont - s >= k? choose(cont - s, k): 0)<<'\n';
        }
    }
    cout<<ans<<'\n';



    return 0;
}