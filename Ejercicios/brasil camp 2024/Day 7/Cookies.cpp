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

// i * a + j * b % n == 0 
// i * (a % n) + j * (b % n) == 0

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    ll a, b; cin>>a>>b;
    ll ans = min(n / __gcd(a, n), n / __gcd(b, n));
    a %= n, b %= n;
    if(b < a) swap(a, b);
    ll g = __gcd(a, b);
    repx(i, 1, 3000000) {
        pll out; 
        if(((ll)i * n) % g == 0 and diophantine(a, b, (ll)i * n, out)) {
            if(i <= n) cout<<out.ff<<' '<<out.ss<<' '<<a * out.ff + b * out.ss<<'\n';
            ll x = out.ff, y = out.ss;
            ans = min(ans, out.ff + out.ss);
        }
    }
    cout<<ans<<'\n';

    return 0;
}