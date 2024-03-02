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


const int mxN = 35002;
int n, k; 
ll A[mxN];
ll DP[55][mxN];

struct Node
{
    ll v, lzv = 0;
    bool lz = false;
    Node() : v(0) {}
    Node(int x) : v(x) {}
    Node(const Node &a, const Node &b) : v(max(a.v, b.v)) {}
    Node(int x, int i, int j, const Node &b)
    {
        v = b.v + x;
        // v = b.v + (j - i + 1) * x;
    }
};

// 0 - indexed / inclusive - inclusive
template <class node>
struct STL {
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


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    rep(i, n) cin>>A[i];
    vector<Node> prevDP(n, Node(0)); 
    vl Last(n + 1, -1), prevPos(n, -1);
    rep(i, n) {
        cerr<<Last[A[i]]<<'\n';
        prevPos[i] = Last[A[i]];
        Last[A[i]] = i;
    }

    // DP[k][i] = max(dp(k - 1, j - 1) + c(i, j): 1 <= j <= i)
    // DP[k][0] = 0
    // DP[k][1] = DP[k - 1][0] + c(1, 1)
    // DP[k][2] = max(DP[k - 1][0] + c(1, 2), DP[k - 1][1] + c(2, 2))
    // DP[k][3] = max(DP[k - 1][0] + c(1, 3), DP[k - 1][1] + c(2, 3), DP[k - 1][2] + c(3, 3))
    // DP[k][4] = max(
    //     DP[k - 1][0] + c(1, 4), 
    //     DP[k - 1][1] + c(2, 4), 
    //     DP[k - 1][2] + c(3, 4), 
    //     DP[k - 1][3] + c(3, 4))
    
    // 1 actualiza al rango (0, 0)
    // 2 actualiza al rango (0, 1)
    // 3 actualiza al rango ()

    // -> si añado el elemento j debo aumentar la dp acumulada desde prevPos[i] - 1 hasta 
    repx(k1, 1, k + 1) {
        STL<Node> ST(prevDP, n);
        prevDP.clear();

        prevDP.pb(Node(0));
        repx(i, 1, n) {
            // Aumento en uno el rango
            cerr<<i<<" actualizo el rango "<<prevPos[i - 1] + 1<<' '<<i<<'\n';
            if(k1 == 1) {
                ST.update(prevPos[i - 1] + 1, i, 1);
                DP[k1][i] = ST.query(0, i).v;
            }
            else {
                ST.update(prevPos[i - 1] + 1, i - 1, 1);
                DP[k1][i] = ST.query(0, i - 1).v;
            }

            prevDP.pb(Node(DP[k1][i]));
            cout<<"k, i, dp: "<<k1<<' '<<i<<' '<<DP[k1][i]<<'\n';
            cout<<"actualizo al rango "<<prevPos[i - 1] + 1<<' '<<i - 1<<"\n\n";
        }
        cout<<'\n';
    }
    cout<<DP[k][n - 1]<<'\n';
    





    return 0;
}