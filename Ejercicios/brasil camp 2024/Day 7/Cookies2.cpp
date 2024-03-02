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
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

ll n, a, b;
ll DP[1001];
ll dp(ll u) {
    if((u + a) % n == 0) return 1;
    if((u + b) % n == 0) return 1;
    if(DP[u] != -1) return DP[u];
    

    DP[u] = 1000000;
    if(dp((u + a) % n) <= n) DP[u] = min(DP[u],  dp((u + a) % n) + 1);
    if(dp((u + b) % n) <= n) DP[u] = min(DP[u],  dp((u + b) % n) + 1);
    cout<<u<<' '<<DP[u]<<'\n';
    return DP[u];
}


pll euclid(ll A, ll B) {
    if (!B) return {1, 0};
    pll p = euclid(B, A % B);
    return {p.ss, p.ff - (A / B) * p.ss};
}

// A * x + B * y = R
bool diophantine(ll A, ll B, ll R, pll& out) {
    ll g = __gcd(A, B), x, y; 
    A /= g, B /= g, R /= g;
    tie(x, y) = euclid(A, B); x *= R, y *= R;
    if(A * x + B * y != R) return false;
    // -x / b <= k <= y / A
    //  a < b -> queremos minimizar k 

    ll mnk = -x / B - 1;
    while(x + mnk * B < 0) mnk++;
    ll mxk = y / A + 1;
    while(y - mxk * A < 0) mxk--;

    if(mnk > mxk) return false;

    ll k = mnk;
    x = x + k * B;
    y = y - k * A;
    out = {x, y};
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    cin>>a>>b;
    rep(i, 1001) DP[i] = -1;
    cout<<dp(0)<<'\n';

    repx(x, 1, 100) {
        a = rand(), b = rand();
        n = x;
        // cout<<n<<' '<<a<<' '<<b<<' '<<'\n';
        
        rep(i, 1001) DP[i] = -1;
        // cout<<dp(0)<<'\n';

        // ll ans = min(n / __gcd(a, n), n / __gcd(b, n));
        // if(b < a) swap(a, b);
        // ll g = __gcd(a, b);
        // pll aux = {0, 0};
        // repx(i, 1, 100000) {
        //     pll out; 
        //     if(((ll)i * n) % g == 0 and diophantine(a, b, (ll)i * n, out)) {
        //         // if(i <= n) cout<<out.ff<<' '<<out.ss<<' '<<a * out.ff + b * out.ss<<'\n';
        //         ll x = out.ff, y = out.ss;
        //         if(ans > out.ff + out.ss) aux = out;
        //         ans = min(ans, out.ff + out.ss);
        //     }
        // }
        // if(dp(0) != ans) {
        //     cout<<"no coinciden "<<n<<' '<<a<<' '<<b<<'\n';
        //     cout<<dp(0)<<' '<<ans<<' '<<aux.ff<<' '<<aux.ss<<'\n';
        // }
    }
    
    return 0;
}