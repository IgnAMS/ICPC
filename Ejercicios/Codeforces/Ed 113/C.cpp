#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef unsigned long long ul;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt

const ll MOD = 998244353;
const ll MAXN = 200006;

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

// find (x, y)'s such that Ax + By = R where R is multiplle of gcd(A, B);
pair<pll, pll> diophantine(ll A, ll B, ll R)
{
    ll g = __gcd(A, B), x, y; A /= g, B /= g, R /= g;
    tie(x, y) = euclid(A, B); x *= R, y *= R;
    assert(A * x + B * y == R);
    return {{x, y}, {-B, A}}; // solutions: p+t*ans.snd
}

ll F[MAXN];
ll choose(int n, int k){
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
    ll F[200006]; F[1] = 1; F[0] = 0;
    repx(i, 2, 200004) F[i] = (F[i-1] * i) % 998244353;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<ll> A(n); rep(i, n) cin>>A[i];
        sort(A.begin(), A.end());
        
        int cont = 0, cont2 = 0;
        rep(i, n) if(A[i] == A[n-1]) cont++;
        rep(i, n) if(A[i] == A[n-2]) cont2++;
        
        ll prev = 0;
        for(int i = n-2; i>=0; i--){ // maxi en la posicion i
            if(n-1-cont2 >= i) prev = add(mul(mul(choose(n-1-cont2, i), F[i], MOD) * F[n-i-1], MOD), prev, MOD);
        }

        if(cont == 1 and A[n-1] - A[n-2] > 1) cout<<"0\n";
        else if(cont == 1 and cont2 > 1){
            cout<<prev<<"\n";
        }
        else cout<<F[n]<<"\n";
    }

    return 0;
}