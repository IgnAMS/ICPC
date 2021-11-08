#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
typedef pair<ll, ll> pll;
typedef unsigned long long ul;
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt


const ll MOD = 1e9 + 7;

inline ll add(ll x, ll y, ll M = MOD) { return (x + y) % M; }
inline ll mul(ll x, ll y, ll M = MOD) { return (x * y) % M; }

ll binPow(ll a, ll b, const ll M){
    if (b == 0) return 1;
    ll r = binPow(a, b / 2, M); r = mul(r, r, M);
    return (b & 1) ? mul(r, a, M) : r;
}

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


const int MAXN = 1000005;
// By definition and euclid
ll F[MAXN];
ll choose(int n, int k){
    return mul(F[n], minv(mul(F[k], F[n - k]), MOD));
}

// Multinomial Coefficient
ll multinomial(vector<int> K){
    ll n = 0, ans = 1;
    for (int k : K) n += k, ans = mul(ans, choose(n, k));
    return ans;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    F[1] = 1; repx(i, 2, MAXN) F[i] = mul(i, F[i-1]);
    vector<ii> P(n);
    rep(i, n) cin>>P[i].ff>>P[i].ss;
    set<ii> S; rep(i, n) S.insert(P[i]);
    
    map<ii, int> mapa;
    rep(i, n) repx(j, i+1, n) {
        if(!mapa.count({P[i].ff + P[j].ff, P[i].ss + P[j].ss})) mapa[{P[i].ff + P[j].ff, P[i].ss + P[j].ss}] = 0;
        mapa[{P[i].ff + P[j].ff, P[i].ss + P[j].ss}]++;
    }

    vi ans(n, 0);
    ans[0] = n;
    for(auto u: mapa){
        if(u.ff.ff % 2 == 0 and u.ff.ss % 2 == 0 and S.count({u.ff.ff/2, u.ff.ss/2})){
            repx(i, 1, u.ss) 
                ans[i * 2] = add(ans[i * 2], choose(u.ss, i));
            ans[2*u.ss] = add(ans[2*u.ss], 1);
        }
        repx(i, 1, u.ss) 
            ans[i*2-1] = add(ans[i*2-1], choose(u.ss, i));
        ans[u.ss*2-1] = add(ans[u.ss*2-1], 1);
    }
    rep(i, n) cout<<ans[i]<<" \n"[i == n-1];

    return 0;
}