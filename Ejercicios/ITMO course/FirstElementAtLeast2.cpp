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



const ll INF = 1e10;; 
struct Node {   
    ll mx, ind;
    Node(): mx(0), ind(0) {}
    Node(ll x, ll i): mx(x), ind(i) {}
    Node(Node a, Node b) {
        if(a.mx > b.mx) mx = a.mx, ind = a.mx;
        else if(b.mx > a.mx) mx = b.mx, ind = b.mx;
        else mx = a.mx, ind = min(a.ind, b.ind);
    }
};


const int mxN = 2e5+5;
struct ST {
    Node T[4 * mxN];
    void update(ll i, ll x, ll l = 0, ll r = mxN, ll u = 0) {
        // cerr<<i<<' '<<x<<' '<<l<<' '<<r<<'\n';
        if(l == r) T[u] = Node(x, l);
        else {
            ll m = (l + r) / 2;
            if(i <= m) update(i, x, l, m, 2 * u + 1);
            else update(i, x, m + 1, r, 2 * u + 2);
            T[u] = Node(T[2 * u + 1], T[2 * u + 2]);
        }
    }
    Node query(ll i, ll j, ll l = 0, ll r = mxN, ll u = 0) {
        if(i <= l and r <= j) return T[u];
        if(i > r or l > j) return Node();
        ll m = (l + r) / 2;
        return Node(query(i, j, l, m, 2 * u +1), query(i, j, m + 1, r, 2 * u + 2)); 
    }
    ll search(ll x, ll l = 0, ll r = mxN, ll u = 0) {
        // Si no lo encontre, entonces retorno 
        if(T[u].mx < x) return 0;

        // Si lo encontre entonces retorno l
        if(l == r) return l + 1;
        ll m = (l + r) / 2;
        ll left = search(x, l, m, 2 * u + 1);
        if(left) return left;   
        return search(x, m + 1, r, 2 * u + 2);
    }
    ll search_first_l(ll x, ll L, ll l = 0, ll r = mxN, ll u = 0) {
        // Si no lo encontre, entonces retorno 
        if(T[u].mx < x) return 0;
        if(r < L) return 0;

        // Si lo encontre entonces retorno l
        if(l == r) return l + 1;
        ll m = (l + r) / 2;
        ll left = search_first_l(x, L, l, m, 2 * u + 1);
        if(left) return left;   
        return search_first_l(x, L, m + 1, r, 2 * u + 2);
    }
} st;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vl A(n);
    rep(i, n) {
        cin>>A[i];
        st.update(i, A[i]);
    }
    rep(i, m) {
        int type; cin>>type;
        if(type == 1) {
            ll ind, v; cin>>ind>>v;
            st.update(ind, v);
        }
        else {
            ll x, l; cin>>x>>l;
            cout<<st.search_first_l(x, l) - 1<<'\n';
        }
    }



    return 0;
}