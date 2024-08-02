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

const int mxN = 1e5+5;
const ll INF = 1e10;
struct ST {
    vl T = vl(4 * mxN, INF);
    void update(ll ind, ll v, ll l = 0, ll r = 100000, ll u = 0) {
        if(l == r) T[u] = v;
        else {
            ll m = (l + r) / 2;
            if(ind <= m) update(ind, v, l, m, 2 * u + 1);
            else update(ind, v, m + 1, r, 2 * u + 2);
            T[u] = min(T[2 * u + 1], T[2 * u + 2]); 
        }
    }
    ll find(ll i, ll j, ll v, ll l = 0, ll r = 100000, ll u = 0) {
        if(T[u] > v) return 0;
        if(i > r or j < l) return 0;
        if(l == r) {
            T[u] = INF;
            return 1;
        }
        ll m = (l + r) / 2;
        ll ans = 0;
        ans += find(i, j, v, l, m, 2 * u + 1);
        ans += find(i, j, v, m + 1, r, 2 * u + 2);
        T[u] = min(T[2 * u + 1], T[2 * u + 2]);
        return ans;
    }
} st;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    rep(_, m) {
        ll type; cin>>type;
        if(type == 1) {
            ll ind, h; cin>>ind>>h;
            st.update(ind, h);
        }
        else {
            ll l, r, v; cin>>l>>r>>v;
            cout<<st.find(l, r - 1, v)<<'\n';
        }
    }


    return 0;
}