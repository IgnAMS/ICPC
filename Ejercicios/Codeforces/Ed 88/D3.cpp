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
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt


struct Node
{
    ll v;
    Node() { v = -10000000; } // neutro
    Node(ll v) : v(v) {}
    Node(const Node &a, const Node &b) { v = max(a.v, b.v); }
};

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
        cerr<<"l, r: "<<l<<' '<<r<<'\n';
        node ansl, ansr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            cerr<<l<<' '<<r<<'\n';
            if (l & 1) ansl = node(ansl, t[l++]);
            if (r & 1) ansr = node(t[--r], ansr);
        }
        return node(ansl, ansr);
    }
};



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vector<vi> G(65), IG;
    int n; cin>>n;
    vi A(n); rep(i, n) cin>>A[i];
    vi Acc(n + 1, 0), Rev(n + 1, 0);
    rep(i, n) if(A[i] >= 0) {
        G[A[i]].push_back(i);
    }

    rep(i, n) Acc[i + 1] = Acc[i] + A[i];
    for(int i = n - 1; i >= 0; i--) Rev[i] = Rev[i + 1] + A[i];
    // cerr<<"sobrevivi hasta aca\n";
    vector<Node> ACC(n + 1), REV(n + 1);
    rep(i, n + 1) ACC[i].v = Acc[i], REV[i].v = Rev[i];
    ST<Node> QR(ACC, n + 1);
    ST<Node> QL(REV, n + 1); 
    
    
    ll ans = 0;
    rep(i, n) if(A[i] > 0) { // asumo que soy el maximo
        ll l = 0, r = n - 1;
        repx(j, A[i] + 1, 30) {
            auto itR = lower_bound(G[j].begin(), G[j].end(), i);
            if(itR != G[j].end()) 
                r = min(r, *itR - 1);

            auto itL = lower_bound(G[j].begin(), G[j].end(), i);
            if(G[j].end() != G[j].begin() and itL != G[j].begin()) 
                l = max(*prev(itL) + 1, l);
        }
        // cerr<<"range: "<<l<<' '<<i<<' '<<r<<'\n';
        // ll L = query(l, i, 0, n, 1).ss;
        // ll R = query(i + 1, r + 1, 0, n, 1).ff;
        ll L = QL.query(l, i + 1).v, R = QR.query(i + 1, r + 2).v;
        // cerr<<"L, R: "<<L<<' '<<R<<"\n";
        ans = max(ans, (L == -10000000? 0: L) + (R == -10000000? 0: R) - Rev[i] - Acc[i + 1]);
        // cerr<<"i, ans: "<<i<<' '<<ans<<"\n\n";
    }
    cout<<ans<<'\n';


    return 0;
}