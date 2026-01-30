#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<string.h>
#include<set>
#include<map>
#include<algorithm>
#include<array>
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
// g++ -O2 NestedRangeCount.cpp && time ./a.out <input.txt> output.txt

 
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
    ll n; cin>>n;
    vector<ll> Ps = {0, 1000000001};
    vector<array<ll, 3>> X;
    vector<array<ll, 4>> E;
    rep(i, n) {
        int l, r; cin>>l>>r;
        X.pb({l, r, i});
        E.pb({l, -r, i, 0});
        E.pb({r, -l, i, 1});
        Ps.pb(l);
        Ps.pb(r);
    }
    sort(Ps.begin(), Ps.end());
    Ps.erase(unique(Ps.begin(), Ps.end()), Ps.end());
    auto get_idx = [&](int x) {
        return lower_bound(Ps.begin(), Ps.end(), x) - Ps.begin();
    };

    vector<Node> Arr(Ps.size(), Node(0));
    ST<Node> left(Arr, Arr.size());
    ST<Node> right(Arr, Arr.size());
    sort(E.begin(), E.end());
    vl In(n, 0), Out(n, 0);
    for(auto& [x, _, ind, event]: E) {
        auto& [l, r, xd] = X[ind];
        if(event == 0) {
            // Reviso cuantos tiene adentro:
            int left_id = get_idx(r);
            int right_id = Ps.size();
            Out[ind] = right.query(left_id, right_id).u;
            int left_val = right.query(left_id, left_id+1).u;
            right.set(left_id, left_val + 1);
        }
        else {
            int left_id = get_idx(l);
            int right_id = get_idx(r)+1;
            In[ind] = left.query(left_id, right_id).u;
            int mid_val = left.query(left_id, left_id+1).u;
            left.set(left_id, mid_val + 1);
        }
        // rep(i, 2 * n + 2) cerr<<left.query(i, i).u<<" "; cerr<<"\n\n";
    }
 
 
    rep(i, n) cout<<In[i]<<" "; cout<<"\n";
    rep(i, n) cout<<Out[i]<<" "; cout<<"\n";
 
    
    return 0;
}