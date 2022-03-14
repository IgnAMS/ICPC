#pragma GCC optimize("Ofast")
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
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

struct P {
    ll x, y;
    P() {}
    P(ll x, ll y): x(x), y(y) {}
    P operator-(const P& p) const { return P(x - p.x, y - p.y); }
    ll operator^(const P& p) const { return x * p.y - y * p.x; }
    bool operator<(const P& p) const { return y < p.y; } 
};
bool half(P &p) {
    return p.y > 0 or (p.y == 0 and p.x > 0);
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    vector<pair<P, ll>> V(n);
    
    rep(i, n) cin>>V[i].ff.x>>V[i].ff.y;
    rep(i, n) V[i].ss = i;
    sort(V.begin(), V.end());
    vi I(n);
    rep(i, n) I[V[i].ss] = i;

    vector<pair<P, ii>> S;
    rep(i, n) repx(j, i + 1, n) 
        S.emplace_back(V[j].ff - V[i].ff, ii(V[i].ss, V[j].ss));
    sort(S.begin(), S.end(), [](auto& p1, auto& p2){
        int h1 = half(p1.ff), h2 = half(p2.ff);
        return h1 != h2? h1 > h2: (p1.ff ^ p2.ff) > 0;
    });


    ll ans = n * (n - 1) * (n - 2) * (n - 3) / 8;
    for(auto& e: S) { // n ^ 2
        ll i = e.ss.ff, j = e.ss.ss;
        // cout<<i<<' '<<j<<'\n';
        // rep(i, n) cout<<I[i]<<' '; cout<<"\n\n";
        ans -= min(I[i], I[j]) * (n - max(I[i], I[j]) - 1);
        swap(V[I[i]], V[I[j]]); swap(I[i], I[j]);
    }
    cout<<ans<<'\n';


    return 0;
}