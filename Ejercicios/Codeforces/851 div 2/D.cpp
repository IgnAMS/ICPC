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
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

ll mod = 1e9 + 7;
ll binpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vl A(n); rep(i, n) cin>>A[i];
    ll ans = 0;
    rep(i, n) repx(j, i + 1, n) {
        int p1 = 0, p2 = 0;
        auto it1 = lower_bound(A.begin(), A.end(), 2 * A[i] - A[j]);
        if(it1 != A.begin()) p1 = (it1 - A.begin());
        auto it2 = lower_bound(A.begin(), A.end(), 2 * A[j] - A[i]);
        p2 = (A.end() - it2);
        ans = (ans + binpow(2, p1 + p2)) % mod;
        // printf("rango: %ld, %ld\n", i, j);
        // printf("%d, %d\n\n", p1, p2);
    }
    cout<<ans<<'\n';





    return 0;
}