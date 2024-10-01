#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

struct Node
{
    int v, lzv = 0;
    bool lz = false;
    Node() : v(0) {}
    Node(int x) : v(x) {}
    Node(const Node &a, const Node &b){
        v = min(a.v, b.v);
    }
    Node(ll x, int i, int j, const Node &b)
    {
        v = b.v + x;
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
    void push(int u, int i, int j, ll x)
    {
        st[u] = node(x, i, j, st[u]);
        if (i == j) return;
        st[u * 2 + 1].lz = 1, st[u * 2 + 1].lzv += x;
        st[u * 2 + 2].lz = 1, st[u * 2 + 2].lzv += x;
    }
    node query(int a, int b, int u, int i, int j)
    {
        if (j < a || b < i) return node();
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (st[u].lz) push(u, i, j, st[u].lzv);
        if (a <= i && j <= b) return st[u];
        return node(query(a, b, l, i, m), query(a, b, r, m + 1, j));
    }
    void update(int a, int b, ll v, int u, int i, int j)
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
    while(t--){
        int n, m; cin>>n>>m;
        vi profe(n); rep(i, n) cin>>profe[i];
        vector<vi> group(m);
        vi suma(m, 0), k(m);
        rep(i, m) {
            cin>>k[i]; group[i].resize(k[i]);
            rep(j, k[i]) { cin>>group[i][j]; suma[i] += group[i][j]; } 
        }
        // todo siempre es menor a 10^5, por ende cabe en un ST

        vector<Node> A(100004);
        vector<ii> S; rep(i, n) S.emplace_back(profe[i], 1);
        rep(i, m) S.emplace_back((suma[i] + k[i] - 1) / k[i], -1);
        sort(S.begin(), S.end());
        ll acc = 0;
        repx(i, 1, n+m+1){
            acc += S[n+m-i].ss;
            if(i != n+m) repx(j, S[n+m-i-1].ff+1, S[n+m-i].ff+1) A[j].v = acc;
        }
        rep(j, S[0].ff+1) A[j].v = acc;
        // rep(i, n+m) cout<<S[i].ff<<' '<<A[S[i].ff].v<<'\n'; cout<<'\n';

        STL<Node> ST(A, 100004);
        rep(i, m) {
            ST.update(0, (suma[i] + k[i] - 1) / k[i], 1);
            rep(j, k[i]) {
                ST.update(0, (suma[i] - group[i][j] + k[i] - 2) / (k[i] - 1), -1);
                // cout<<ST.query(0, 100000).v<<'\n';
                if(ST.query(0, 100000).v < 0) cout<<0;
                else cout<<1;
                ST.update(0, (suma[i] - group[i][j] + k[i] - 2) / (k[i] - 1), 1);
            }
            ST.update(0, (suma[i] + k[i] - 1) / k[i], -1);
        }
        cout<<'\n';


    }


    return 0;
}