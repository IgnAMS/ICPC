#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<iostream>
#include<algorithm>
#include<numeric>
#include <cmath>
#include<set>
#include<array>
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
// g++ -std=c++17 A.cpp -o a && ./a <input.txt> output.txt   
// ulimit -s 1000000
// g++ -std=c++17 -O2 B.cpp && time ./a.out <input.txt> output.txt

const int mxN = 2e5+5;
int n, m;

void solve() {
    ll p, q; cin>>p>>q;
    ll largo = p + 2 * q; 
    // 10^8 + 2 * 10^8 = 3 * 10^8
    // (a + 1) * b + (b + 1) * a -> 2 * a * b + a + b
    // p + 2 * q = 2 * a * b + a + b = b (2 * a + 1) + a
    // -> b = (p + 2 * q - a) / (2 * a + 1)
    ll tope = sqrt(p / 2 + q) + 5;
    repx(i, 1, tope) {
        ll base = 1LL * 3 * i + 1;
        if(base > largo) break;
        if((largo - base) % (2 * i + 1) != 0) continue;
        ll j = (largo - base) / (2 * i + 1) + 1;
        if(j and abs(j - i) <= p) {
            cout<<i<<" "<<j<<"\n";
            return;
        }
    }
    cout<<"-1\n";
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
