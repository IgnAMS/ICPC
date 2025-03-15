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

vl D[1000001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k; cin>>n>>k;
    for(int i = 2; i < 1000001; i++) {
        if(D[i].size() == 0) {
            for(int j = i; j < 1000001; j += i) {
                D[j].pb(i);
            }
        }
    }

    vl C1(1000001, 0);

    rep(i, n) {
        ll y; cin>>y;
        for(auto u: D[y]) {
            ll x = y, cont = 0;
            while(x % u == 0) cont++, x /= u;
            C1[u] = max(C1[u], cont);
        }
    }

    vl C2(1000001, 0);
    for(auto u: D[k]) {
        ll x = k, cont = 0;
        while(x % u == 0) cont++, x /= u;
        C2[u] = cont;
    }

    bool pos = 1;
    rep(u, 1000001) {
        if(C1[u] < C2[u]) {
            cout<<"No\n";
            return 0;
        }
    }
    cout<<"Yes\n";

    return 0;
}