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

pll euclid(ll A, ll B)
{
    if (!B) return {1, 0};
    pll p = euclid(B, A % B);
    return {p.ss, p.ff - (A / B) * p.ss};
}

pll CRT(pll a, pll b)
{
    if (a.ss < b.ss) swap(a, b);
    ll x, y; tie(x, y) = euclid(a.ss, b.ss); 
    ll g = a.ss * x + b.ss * y, l = a.ss / g * b.ss;
    if ((b.ff - a.ff) % g) return {-1, -1}; // no solution
    x = (b.ff - a.ff) % b.ss * x % b.ss / g * a.ss + a.ff; 
    return {x + (x < 0) * l, l};
}

pll CRT(vector<pll> &v)
{
    int N = v.size(); pll ans = v[0];
    rep(i, N) if (i) ans = CRT(ans, v[i]);
    return ans;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t; cin>>t;
    while(t--) {
        ll a, n, b, m; cin>>a>>n>>b>>m;
        vector<pll> A = {{a, n}, {b, m}};
        auto x = CRT(A);
        if(x.ff == -1) {
            cout<<"no solution\n";
        }
        else cout<<x.ff<<' '<<x.ss<<'\n';

    }    

    return 0;
}