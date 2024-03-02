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
    ll v; 
    Node(): v(-1000000) {}
    Node(ll v): v(v) {}
    Node(const Node& a, const Node& b) {
        v = max(a.v, b.v);
    }
};


template<class node>
struct ST {
    vector<node> t; int n;
    ST(vector<node>& arr, int N): n(N), t(2 * N) {
        copy(arr.begin(), arr.end(), t.begin() + n);
        for(int i = n - 1; i > 0; i--) t[i] = node(t[i<<1], t[i<<1 | 1]);
    }
    void set(int p, const node& value) {
        for(t[p += n] = value; p >>= 1;) t[p] = node(t[p<<1], t[p<<1 | 1]); 
    }
    node query(int l, int r) {
        node ansl, ansr;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) ansl = node(ansl, t[l++]);
            if(r & 1) ansr = node(t[--r], ansr);
        }
        return node(ansl, ansr);
    }
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vl X(n), R(n);
        rep(i, n) cin>>X[i]>>R[i];

        ll DPL[n];
        vector<Node> AccL(n);
        ST<Node> stL(AccL, n);
        // DPL[i] = max_{j < i: X[j] <= X[i] - R[i]} DPL[j] + (i - j) 
        rep(i, n) {
            int left = lower_bound(X.begin(), X.end(), X[i] - R[i]) - X.begin();
            DPL[i] = 1;
            if(left < i) {
                DPL[i] = stL.query(left, i).v + i;
            }
            stL.set(i, Node(DPL[i] - i));
        }

        ll DPR[n];
        vector<Node> AccR(n);
        ST<Node> stR(AccR, n);
        // DPR[i] = max_{j > i: X[j] <= X[i] + R[i]} DPL[j] + (j - i)
        for(int i = n - 1; i >= 0; i--) {
            int right = upper_bound(X.begin(), X.end(), X[i] + R[i]) - X.begin() - 1;
            DPR[i] = 1;
            if(right > i) {
                DPR[i] = stR.query(i + 1, right + 1).v - i;
            }
            stR.set(i, Node(DPR[i] + i));
        }

        //  rep(i, n) cout<<DPL[i]<<' '<<DPR[i]<<'\n';

        rep(i, n) {
            cout<<DPL[i] + DPR[i] - 1<<" \n"[i == n - 1];
        }
    }


    return 0;
}