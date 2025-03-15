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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll L, n, m; cin>>L>>n>>m;
    map<ll, ll> closedA, closedB;
    set<ll> X;
    rep(i, n) {
        char c; int x;
        cin>>c>>x;
        ll val = 0;
        if(c == 'U') val = 2 * L + (L - x);
        else val = L + x;
        X.insert(0), X.insert(val);
        closedA[val]++;
    }
    rep(i, m) {
        char c; int x;
        cin>>c>>x;
        ll val = 0;
        if(c == 'U') val = 2 * L + (L - x);
        else val = 3 * L + (L - x);
        X.insert(L), X.insert(val);
        closedB[val]++;
    }
    ll conta = 0, contb = m, ans = 0;
    for(auto u: X) {
        conta += closedA[u];
        contb -= closedB[u];
        if(closedA.count(u)) ans += closedA[u] * contb;
        if(closedB.count(u)) ans += closedB[u] * conta;
    }
    cout<<ans / 2 + n + m + 1<<'\n';

    return 0;
}