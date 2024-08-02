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


const ll INF = 1e15;
const int mxN = 1e5+5;
struct ST {
    ll T[4 * mxN], Acc[4 * mxN];
    void add(ll i, ll j, ll v, ll l = 0, ll r = mxN, ll u = 0) {
        if(i <= l and r <= j) {
            Acc[u] += v;
            T[u] += v;
            return;
        }
        if(r < i or j < l) return;

        ll m = (l + r) / 2;
        add(i, j, v, l, m, 2 * u + 1);
        add(i, j, v, m + 1, r, 2 * u + 2);
        T[u] = Acc[u] + min(T[2 * u + 1], T[2 * u + 2]);
    }
    ll query(ll i, ll j, ll l = 0, ll r = mxN, ll u = 0) {
        if(i <= l and r <= j) return T[u];
        if(r < i or j < l) return INF;
        ll m = (l + r) / 2;
        return Acc[u] + min(query(i, j, l, m, 2 * u + 1), query(i, j, m + 1, r, 2 * u + 2));
    }
} st;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    rep(_, m) {
        int type; cin>>type;
        if(type == 1) {
            ll l, r, v; cin>>l>>r>>v;
            st.add(l, r - 1, v);
        }
        if(type == 2) {
            ll l, r; cin>>l>>r;
            cout<<st.query(l, r - 1)<<'\n';
        }
    }

    return 0;
}