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

int n, c;
const int mxN = 1e5+5;
struct ST {
    ll T[4 * mxN];
    void update(ll i, ll x, ll l = 0, ll r = mxN, ll u = 0) {
        if(l == r) T[u] = x;
        else {
            ll m = (l + r) / 2;
            if(i <= m) update(i, x, l, m, 2 * u + 1);
            else update(i, x, m + 1, r, 2 * u + 2);
            T[u] = min(T[2 * u + 1], T[2 *u + 2]);
        }
    }
    ll query(ll i, ll j, ll l = 0, ll r = mxN, ll u = 0) {
        if(i <= l and r <= j) return T[u];
        if(r < i or j < l) return 1e10;
        ll m = (l + r) / 2;
        return min(query(i, j, l, m, 2 *u + 1), query(i, j, m + 1, r, 2 * u + 2)); 
    }

} st;


ll DP[mxN];
ll dp(ll i) {
    if(i == n) return 0;
    if(DP[i] != 1) return DP[i];
    DP[i] = dp(i + 1);
    if(i + c <= n) {
        DP[i] = min(DP[i], DP[i + c] - st.query(i, i + c - 1));
    }
    return DP[i];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>c;
    vl A(n); rep(i, n) cin>>A[i];
    ll suma = 0;
    rep(i, n) {
        DP[i] = 1;
        st.update(i, A[i]);
        suma += A[i];
    }
    cout<<suma + dp(0)<<'\n';

    return 0;
}