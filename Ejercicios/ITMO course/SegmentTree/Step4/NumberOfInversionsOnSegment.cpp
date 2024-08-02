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

struct Node {
    ll ans = 0;
    vl F = vl(41, 0), Acc = vl(41, 0);
    Node() {
        ans = 0, F = vl(41, 0), Acc = vl(41, 0);
    }
    Node(ll x) {
        ans = 0, F = vl(41, 0), Acc = vl(41, 0);
        F[x] += 1;
        repx(i, 1, 41) Acc[i] = Acc[i - 1] + F[i];
    }
    Node(Node& a, Node& b) {
        ans = a.ans + b.ans;
        F = vl(41, 0), Acc = vl(41, 0);
        repx(i, 1, 41) {
            ans += a.F[i] * b.Acc[i - 1];
            // ans += b.F[i] * a.Acc[i - 1];
            F[i] += a.F[i] + b.F[i];
            Acc[i] = Acc[i - 1] + F[i];
        }
    }
};


// 0 - indexed / inclusive - exclusive
template <class node>
struct ST {
    vector<node> t; int n;
    ST(vector<node> &arr, int N) : n(N), t(N * 2) {
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i) {
            t[i] = node(t[i << 1], t[i << 1 | 1]);
            // cout<<"mergeo "<<'\n';
            // repx(j, 1, 41) cout<<t[i << 1].F[j]<<' '; cout<<'\n';
            // repx(j, 1, 41) cout<<t[i << 1 | 1].F[j]<<' '; cout<<'\n';
            // cout<<t[i].ans<<"\n\n";
        }
    }
    void set(int p, const node &value) {
        for (t[p += n] = value; p >>= 1;)
            t[p] = node(t[p << 1], t[p << 1 | 1]);
    }
    node query(int l, int r) {
        node ansl, ansr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ansl = node(ansl, t[l++]);
            if (r & 1) ansr = node(t[--r], ansr);
        }
        return node(ansl, ansr);
    }
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vector<Node> A(n);
    rep(i, n) {
        int x; cin>>x;
        A[i] = Node(x);
    }
    ST<Node> st(A, n);
    rep(_, m) {
        int t, x, y; cin>>t>>x>>y;
        if(t == 1) {
            x--, y--;
            Node X = st.query(x, y + 1);
            // repx(i, 1, 41) cout<<X.F[i]<<' '; cout<<'\n';
            cout<<st.query(x, y + 1).ans<<'\n';
        }
        else {
            x--;
            Node X(y);
            st.set(x, X);
        }
    }



    return 0;
}