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
// g++ -O2 G.cpp && time ./a.out <input.txt> output.txt

const int mxN = 200005;

struct ST {
    ll T[4 * mxN];
    void update(int i, ll x, int l = 0, int r = 200000, int u = 0) {
        if(l == r) T[u] = x;
        else {
            int m = (l + r) / 2;
            if(i <= m) update(i, x, l, m, 2 * u + 1);
            else update(i, x, m + 1, r, 2 * u + 2);
            T[u] = T[2 * u + 1] + T[2 * u + 2];
        }    
    }

    ll query(int i, int j, int l = 0, int r = 200000, int u = 0) {
        if(i <= l and r <= j) return T[u];
        if(r < i or l > j) return 0;
        
        int m = (l + r) / 2;
        return query(i, j, l, m, 2 * u + 1) + query(i, j, m + 1, r, 2 * u + 2);
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k, q; cin>>n>>k>>q;
    vector<pll> X(n);
    vl Open(mxN, 0), Closed(mxN, 0);
    rep(i, n) {
        cin>>X[i].ff>>X[i].ss;
        Open[X[i].ff]++;
        Closed[X[i].ss]++;
    }

    ST st;
    ll curr = 0;
    rep(i, 200001) {
        curr += Open[i];
        ll x = (curr >= k);
        st.update(i, x);
        curr -= Closed[i];
    }

    while(q--) {
        ll a, b; cin>>a>>b;
        cout<<st.query(a, b)<<'\n';
    }


    return 0;
}