#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<string.h>
#include<set>
#include<map>
#include<algorithm>
#include<unordered_map>
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
// g++ -std=c++17 MissingCoinSum.cpp -o a && ./a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 JosephusProblemII.cpp && time ./a.out <input.txt> output.txt


// Benjamin Rubio iterative ST: https://github.com/BenjaminRubio/CompetitiveProgramming/blob/master/Material/Structures/SegmentTree.cpp
// 0 - indexed / inclusive - exclusive
template <class node>
struct ST
{
    vector<node> t; int n;

    ST(vector<node> &arr, int N) : n(N), t(N * 2)
    {
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i) t[i] = node(t[i << 1], t[i << 1 | 1]);
    }
    void set(int p, const node &value)
    {
        for (t[p += n] = value; p >>= 1;)
            t[p] = node(t[p << 1], t[p << 1 | 1]);
    }
    node query(int l, int r)
    {
        r++;
        node ansl, ansr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) ansl = node(ansl, t[l++]);
            if (r & 1) ansr = node(t[--r], ansr);
        }
        return node(ansl, ansr);
    }
};
struct Node {
    int u;
    Node(): u(0) {}
    Node(int u): u(u) {}
    Node(Node &a, Node &b) {
        u = a.u + b.u;
    }
};



const int INF = 1e9+1;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k; cin>>n>>k;
    vector<Node> Arr; rep(i, n) Arr.pb(Node(1));
    Arr.pb(Node(0));
    ST<Node> st(Arr, n+1);
    int index = 0;
    ll cont = 0, curr = 0;
    ll xd = 0;
    while(cont < n and xd++ < n) {
        // vueltas completas
        if(n - cont < k+1 - curr) {
            ll vueltas = (k+1 - curr) / (n - cont);
            curr += vueltas * (n - cont);
            if(curr == k+1) curr -= n-cont;
        }
        index = 0;
        while(true) {
            int l = index, r = n;
            // garantia de pasar un paso!
            while(l < r) {
                int m = (l + r) / 2;
                if(st.query(index, m).u >= k+1 - curr) r = m;
                else l = m + 1;
            }
            curr += st.query(index, l).u;
            index = l;
            if(index == n) break;

            cont++;
            curr = 0;
            st.set(l, 0);
            cout<<l + 1<<" ";
        }
    }

    
    return 0;
}