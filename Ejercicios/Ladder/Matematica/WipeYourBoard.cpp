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

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) return false;

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return 1;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll r, s, q; cin>>r>>s>>q;
        ll a, b, g;
        find_any_solution(r, s, q, a, b, g);
        // cout<<g<<'\n';
        // cout<<a<<' '<<r<<", "<<b<<' '<<s<<": "<<q<<'\n';
        ll f1 = s / g, f2 = -r / g;
        // ll k = min(, (b - 1) * g / r);
        // cout<<s / g<<' '<<-r / g<<'\n';
        // cout<<((a - 1)) / abs(f1)<<' '<<((b - 1)) / abs(f2)<<'\n'; 
        ll aux1 = ((a - 1) + (a <= 0? f1 + 1: 0)) / abs(f1);
        ll aux2 = ((b - 1) + (b <= 0? f2 + 1: 0)) / abs(f2);
        ll k = min(aux1, aux2);
        cout<<a + f1 * k<<' '<<b + f2 * k<<'\n';
        // a - f1 * k 
        // a = a + k * s / g, b = b - k * r / g;
        // a >= 1 -> a + (-f1) * k >= 1 -> a - 1 >= |f1| * k -> (a - 1) / |f1| >= k
        // b >= 1 -> b + (-f2) * k >= 1 -> b - 1 >= |f2| * k -> (b - 1) / |f2| >= k
        // cout<<a<<' '<<r<<", "<<b<<' '<<s<<": "<<q<<'\n';
        // cout<<a<<' '<<b<<'\n';
        // cout<<'\n';
    }

    return 0;
}