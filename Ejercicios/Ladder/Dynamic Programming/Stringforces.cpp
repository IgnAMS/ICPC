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

int n, k; 
string s;

ll DP[1<<17];

const int mxN = 2e5+5;
ll a[mxN][17], c[mxN][17];
const ll inf = 1e10;

ll posible(ll x) {
    rep(j, k) a[n + 1][j] = inf;

    // minimal position such that I can place x elements of the type j from the position i
    rep(j, k) for(int i = n; i; i--) {
        a[i][j] = a[i + 1][j];
        if(i + x - 1 <= n and c[i - 1][j] == c[i + x - 1][j]) a[i][j] = i + x - 1;    
    }
    
    // DP[C] = min_{j \in C} {a[DP[C \ {j}] + 1][j]}
    // DP[C] = min position such that I can place all the elements of C
    repx(mask, 1, 1<<k) {
        DP[mask] = inf;
        rep(j, k) if((1<<j) & mask and DP[mask ^ (1<<j)] <= n) {
            DP[mask] = min(DP[mask], a[DP[mask ^ (1<<j)] + 1][j]);
        }
    }

    return DP[(1<<k) - 1] <= n;
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin>>n>>k>>s;
    rep(j, k) rep(i, n) {
        c[i + 1][j] = c[i][j];
        if(s[i] != '?' and s[i] - 'a' != j) c[i + 1][j]++;
    }

    ll l = 0, r = n / k;
    while(l < r) {
        int m = (l + r + 1) / 2;
        if(posible(m)) l = m;
        else r = m - 1;
    }
    cout<<l<<'\n';

    return 0;
}