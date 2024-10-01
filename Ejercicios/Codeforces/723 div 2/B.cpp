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


// find (x, y) such that Ax + By = gcd(A, B), and |Ax|, |By| <= AB/gcd(A, B)
pll euclid(ll A, ll B)
{
    if (!B) return {1, 0};
    pll p = euclid(B, A % B);
    return {p.ss, p.ff - (A / B) * p.ss};
}

// find (x, y)'s such that Ax + By = R where R is multiplle of gcd(A, B);
pair<pll, pll> diophantine(ll A, ll B, ll R)
{
    ll g = __gcd(A, B), x, y; A /= g, B /= g, R /= g;
    tie(x, y) = euclid(A, B); x *= R, y *= R;
    assert(A * x + B * y == R);
    return {{x, y}, {-B, A}}; // solutions: p+t*ans.snd
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    // Se puede escribir x = 11 * a + 111 * b con, a, b >= 0?
    // 10000
    while(t--) {
        ll x; cin>>x;
        ll a = 11, b = 111;
        auto [ans, notans] = diophantine(a, b, x);
        // cout<<ans.ff<<' '<<ans.ss<<'\n';
        // Respuestas son del estilo: x0 + k * b, y0 - k * a
        if(ans.ff < 0) {
            // Quiero: x0 + k * b >= 0 -> k >= -x0 / b
            ll k = (-ans.ff + b - 1) / b;
            while(k * b < ans.ff) k++;

            ans.ff += k * b;
            ans.ss -= k * a;
        }
        if(ans.ss < 0) {
            // Quiero: y0 - k * a >= 0 -> y0 / a >= k 
            ll k = ans.ss / a;
            while(k * a > ans.ss) k--;
            ans.ff += k * b;
            ans.ss += k * a;
        }

        // cout<<ans.ff<<' '<<ans.ss<<'\n';
        if(ans.ff >= 0 and ans.ss >= 0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    





    return 0;
}