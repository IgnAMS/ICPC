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


const int mxN = 2e5+5;

const ll MOD = 1e9+7;
const ll Base = 154;
ll Pot[mxN];


struct Node {
    ll H[26];
    ll largo;
    Node() {
        rep(c, 26) H[c] = 0;
        largo = 0;
    }
    Node(char c) {
        rep(c2, 26) H[c2] = 0;
        H[c - 'a'] = 1;
        largo = 1;
    }
    Node(Node L, Node R) {
        rep(c, 26) {
            H[c] = (L.H[c] + (Pot[L.largo] * R.H[c]) % MOD) % MOD;  
        }
        largo = L.largo + R.largo;
    }
};


struct ST {
    Node T[4 * mxN];
    void build(string& s, ll l = 0, ll r = mxN, ll u = 0) {
        if(l == r) T[u] = Node(s[l]);
        else {
            ll m = (l + r) / 2;
            build(s, l, m, 2 * u + 1);
            build(s, m + 1, r, 2 * u + 2);
            T[u] = Node(T[2 * u + 1], T[2 * u + 2]);
        }
    }
    Node query(ll i, ll j, ll l = 0, ll r = mxN, ll u = 0) {
        if(r < i or j < l) return Node();
        if(i <= l and r <= j) return T[u];
        ll m = (l + r) / 2;
        return Node(query(i, j, l, m, 2 * u + 1), query(i, j, m + 1, r, 2 * u + 2));
    }
} st;




int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    string s; cin>>s;

    // Inicio la potencia
    Pot[0] = 1;
    repx(i, 1, mxN) Pot[i] = (Pot[i - 1] * Base) % MOD;

    // Inicio el ST
    st.build(s, 0, n - 1, 0);

    while(m--) {
        ll x, y, l; cin>>x>>y>>l; x--, y--;
        Node L = st.query(x, x + l - 1, 0, n - 1, 0);
        Node R = st.query(y, y + l - 1, 0, n - 1, 0);
        multiset<ll> S;
        rep(c, 26) S.insert(L.H[c]);
        
        bool pos = 1;
        rep(c, 26) {
            if(!S.count(R.H[c])) pos = 0;
            else S.erase(S.find(R.H[c]));
        }
        cout<<(pos? "YES\n": "NO\n");
    }



    return 0;
}