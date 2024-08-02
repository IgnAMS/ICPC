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


const ll MOD = 1e9+7;
ll binpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll x, y; cin>>x>>y;
    if(y % x != 0) {
        cout<<"0\n";
        return 0;
    }

    set<ll> Divs; Divs.insert(1);
    y /= x;
    for(ll i = 1; i * i <= y; i++) {
        if(y % i == 0) {
            Divs.insert(i);
            if(y / i != i) Divs.insert(y / i);
        }
    }
    // cout<<Divs.size()<<'\n';
    ll cont = 0;

    map<ll, ll> DP;
    for(auto u: Divs) DP[u] = binpow(2, u - 1);

    for(auto u: Divs) if(u > 1) {
        // cout<<u<<' ';
        for(ll d = 1; d * d <= u; d++) {
            cont++;
            if(u % d == 0) {
                // cout<<"descuento en "<<u<<" una cantidad de "<<DP[d]<<'\n';
                DP[u] -= DP[d];
                if(u / d != d and u / d != u) {
                    DP[u] -= DP[u / d];
                    // cout<<"descuento adicional de "<<DP[u / d]<<'\n';
                }
            }
            DP[u] = (DP[u] + 2 * MOD) % MOD;
        }
    }
    // cout<<'\n';
    // cout<<cont<<'\n';
    cout<<DP[y]<<'\n';


    return 0;
}