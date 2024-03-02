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

ll n;

const ll mxN = 2e5+10;
ll A[mxN];

ll T[4 * mxN];
void update(ll i, ll x, ll l = 0, ll r = mxN-5, ll u = 0) {
    if(l == r) T[u] = x;
    else {
        ll m = (l + r) / 2;
        if(i <= m) update(i, x, l, m, 2 * u + 1);
        else update(i, x, m + 1, r, 2 * u + 2);
        T[u] = max(T[2 * u + 1], T[2 * u + 2]);
    }
}

ll query(ll i, ll j, ll l = 0, ll r = mxN-5, ll u = 0) {
    if(i > r or j < l) return 0;
    if(i <= l and r <= j) return T[u];
    ll m = (l + r) / 2;
    return max(query(i, j, l, m, 2 * u + 1), query(i, j, m + 1, r, 2 * u + 2));
}




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;

    vl A(n); 
    set<int> S;
    rep(i, n) {
        cin>>A[i];
        S.insert(A[i]);
    }
    map<ll, ll> mp;
    ll id = 1;
    for(auto u: S) {
        mp[u] = id;
        id++;
    }
    rep(i, n) A[i] = mp[A[i]];
    
    memset(T, 0, sizeof(T));
    rep(i, n) {
        ll q = query(0, A[i] - 1) + 1;
        if(q > query(A[i], A[i])) update(A[i], q);
    }
    ll ans = 0;
    rep(i, n) ans = max(ans, query(A[i], A[i]));

    cout<<ans<<'\n';    


    return 0;
}