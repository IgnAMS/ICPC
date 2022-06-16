#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt


struct Node {
    int v, lzv = 0;
    bool lz = false;
    Node() : v(0) {}
    Node(int x) : v(x) {}
    Node(const Node &a, const Node &b) : v(a.v + b.v) {}
    Node(int x, int i, int j, const Node &b) {
        if(x == 0) v = 0;
        if(x == 1) v = (j - i + 1);
        if(x == 2) v = (j - i + 1) - b.v;
        lz = 0;
    }
};

// 0 - indexed / inclusive - inclusive
template <class node>
struct STL
{
    vector<node> st; int n;

    void build(int u, int i, int j, vector<node> &arr)
    {
        if (i == j) { st[u] = arr[i]; return; }
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        build(l, i, m, arr), build(r, m + 1, j, arr);
        st[u] = node(st[l], st[r]);
    }
    void push(int u, int i, int j, int x) 
    {
        st[u] = node(x, i, j, st[u]);
        // cout<<"acutalizo el nodo "<<i<<' '<<j<<" a "<<st[u].v<<" al actualizarlo con "<<x<<'\n';
                if (i == j) return;
        // x, (L, R)  = (0, algo) -> 0
        // x, (L, R)  = (1, algo) -> 1
        // x, (L, R)  = (2, 0)    -> 1
        // x, (L, R)  = (2, 1)    -> 0
        // x, (L, R)  = (2, 2)    -> lz = 0
        auto& L = st[2 * u + 1];
        auto& R = st[2 * u + 2];

        if(x == 2 and L.lz and L.lzv == 0) L.lzv = 1;
        else if(x == 2 and L.lz and L.lzv == 1) L.lzv = 0;
        else if(x == 2 and L.lz and L.lzv == 2) L.lz = 0, L.lzv = 0;
        else L.lz = 1, L.lzv = x;

        if(x == 2 and R.lz and R.lzv == 0) R.lzv = 1;
        else if(x == 2 and R.lz and R.lzv == 1) R.lzv = 0;
        else if(x == 2 and R.lz and R.lzv == 2) R.lz = 0, R.lzv = 0;
        else R.lz = 1, R.lzv = x;
    }
    node query(int a, int b, int u, int i, int j)
    {
        if (j < a || b < i) return node();
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (st[u].lz) push(u, i, j, st[u].lzv);
        if (a <= i && j <= b) {
            // cout<<"El nodo "<<i<<' '<<j<<" retorna "<<st[u].v<<'\n';
            return st[u];
        }
        return node(query(a, b, l, i, m), query(a, b, r, m + 1, j));
    }
    void update(int a, int b, int v, int u, int i, int j) 
    {
        if (st[u].lz) push(u, i, j, st[u].lzv);
        if (j < a || b < i) return;
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (a <= i && j <= b) { push(u, i, j, v); return; }
        update(a, b, v, l, i, m); update(a, b, v, r, m + 1, j);
        st[u] = node(st[l], st[r]);
    }

    STL(vector<node> &v, int N) : n(N), st(N * 4 + 5) { build(0, 0, n - 1, v); }
    node query(int a, int b) { return query(a, b, 0, 0, n - 1); }
    void update(int a, int b, int v) { update(a, b, v, 0, 0, n - 1); }
};



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    rep(cas, t) {
        cout<<"Case "<<cas + 1<<":\n";
        int casos; cin>>casos;
        vi A;
        rep(i, casos) {
            int k; cin>>k;
            string s; cin>>s;
            rep(j, k) for(auto u: s) A.push_back(u - '0');
        }
        vector<Node> B(A.size()); rep(i, A.size()) B[i] = Node(A[i]);
        STL<Node> stl(B, A.size());
        int q; cin>>q;
        int cont = 0;
        
        while(q--) {
            string com;
            int a, b; 
            cin>>com>>a>>b;
            if(com == "F") stl.update(a, b, 1);
            if(com == "E") stl.update(a, b, 0);
            if(com == "I") stl.update(a, b, 2);
            if(com == "S") {
                cont++;
                cout<<"Q"<<cont<<": "<<stl.query(a, b).v<<'\n';
            }
        }
    }


    return 0;
}