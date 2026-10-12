#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<iostream>
#include<algorithm>
#include<numeric>
#include <unordered_map>
#include <cmath>
#include<set>
#include<array>
using namespace std;
// g++ -std=c++17 M.cpp -o a && ./a <input.txt> output.txt   
// ulimit -s 1000000
// g++ -std=c++17 -O2 M.cpp && time ./a.out <input.txt> output.txt


#define ll long long
#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define repx(i, a, b) for(int i = (int)a; i < (int)b; ++i)
#define pb push_back
typedef vector<ll> vl;
typedef pair<ll, ll> pll; 
typedef vector<int> vi;


struct ST {
    int N;
    vector<bool> Empty;
    vl RemainCap;
    vl LazyAdding;
    vl InitCap;
    vector<pair<int,int>> Range;


    ST(vl& A) {
        N = A.size();
        Empty.resize(4 * N + 4);
        RemainCap.resize(4 * N + 4);
        InitCap.resize(4 * N + 4);
        LazyAdding.resize(4 * N + 4);
        Range.assign(4 * N + 4, {-1, -1});
        build(A, 0, N - 1, 0);
    }

    void build(vl& A, int l, int r, int u) {
        Range[u] = {l, r};
        if(l == r) {
            InitCap[u] = RemainCap[u] = A[l];
            Empty[u] = 0;
            return;
        }
        int m = (l + r) / 2;
        build(A, l, m, 2 * u + 1);
        build(A, m+1, r, 2 * u + 2);
        InitCap[u] = InitCap[2 * u + 1] + InitCap[2 * u + 2];
        RemainCap[u] = InitCap[u];
    }

    void push_empty(int l, int r, int u) {
        RemainCap[u] = InitCap[u];
        LazyAdding[u] = 0;
        if(l != r) {
            LazyAdding[2 * u + 1] = LazyAdding[2 * u + 2] = 0;
            RemainCap[2 * u + 1] = InitCap[2 * u + 1];
            RemainCap[2 * u + 2] = InitCap[2 * u + 2];
            Empty[2 * u + 1] = Empty[2 * u + 2] = 1;
        }
        Empty[u] = 0;
    }

    void push_adding(int l, int r, int u) {
        // cout<<"Propagating "<<l<<", "<<r<<", "<<u<<", "<<RemainCap[u]<<", "<<LazyAdding[u]<<"\n";
        RemainCap[u] = max(0LL, RemainCap[u] - LazyAdding[u]);
        if(l != r) {
            // now, lets fill the left side
            int m = (l + r) / 2;
            if(Empty[2 * u + 1]) push_empty(l, m, 2 * u + 1);
            if(Empty[2 * u + 2]) push_empty(m+1, r, 2 * u + 2);
            ll overflow = max(0LL, LazyAdding[u] - max(0LL, RemainCap[2 * u + 2] - LazyAdding[2 * u + 2]));
            LazyAdding[2 * u + 2] = min(RemainCap[2 * u + 2], LazyAdding[2 * u + 2] + LazyAdding[u]);
            LazyAdding[2 * u + 1] += overflow;
        }
        LazyAdding[u] = 0;
    }

    // This function should return what it was not used.
    ll fill(ll x, int ind, int l, int r, int u) {
        // cerr<<"filling: "<<x<<", "<<ind<<", "<<l<<", "<<r<<", "<<u<<"\n";
        if(Empty[u]) push_empty(l, r, u);
        if(LazyAdding[u]) push_adding(l, r, u);

        if(r <= ind) {
            // cout<<"adding lazy in "<<u<<"\n";
            LazyAdding[u] += x;
            ll unused = max(0LL, x - RemainCap[u]);
            push_adding(l, r, u);
            return unused;
        }

        int m = (l + r) / 2;
        ll answer = 0;
        if(ind <= m) {
            answer = fill(x, ind, l, m, 2 * u + 1);
            if(Empty[2 * u + 2]) push_empty(m + 1, r, 2 * u + 2);
            if(LazyAdding[2 * u + 2]) push_adding(m + 1, r, 2 * u + 2);
        }
        else {
            // This is the tricky part. I have to fill both sides, but the left 
            // side is guaranteed to be just one call.
            ll unused = fill(x, ind, m + 1, r, 2 * u + 2); 
            answer = fill(unused, ind, l, m, 2 * u + 1); // This should be just the lazy adding.
        }
        RemainCap[u] = RemainCap[2 * u + 1] + RemainCap[2 * u + 2];

        return answer;
    }

    void empty(int i, int j, int l, int r, int u) {
        if(Empty[u]) push_empty(l, r, u);
        if(LazyAdding[u]) push_adding(l, r, u); // This will be 0, but who cares
        if(i <= l and r <= j) {
            Empty[u] = 1;
            push_empty(l, r, u);
            return;
        }
        if(j < l or r < i) return;
        int m = (l + r) / 2;
        empty(i, j, l, m, 2 * u + 1);
        empty(i, j, m+1, r, 2 * u + 2);
        RemainCap[u] = RemainCap[2 * u + 1] + RemainCap[2 * u + 2];
    }

    void fill(ll x, int ind) {
        fill(x, ind, 0, N - 1, 0);
    };

    void empty(int i, int j) {
        empty(i, j, 0, N - 1, 0);
    }

    ll query(int i, int j, int l, int r, int u) {
        // cout<<"querying "<<i<<", "<<j<<", "<<l<<", "<<r<<", "<<u<<"\n";
        if(Empty[u]) push_empty(l, r, u);
        if(LazyAdding[u]) push_adding(l, r, u);
        if(i <= l and r <= j) return InitCap[u] - RemainCap[u];
        if(r < i or j < l) return 0;
        int m = (l + r) / 2;
        return query(i, j, l, m, 2 * u + 1) + query(i, j, m+1, r, 2 * u + 2);
    } 
    ll query(int i, int j) {
        return query(i, j, 0, N - 1, 0);
    }
};


int main() {
    int n, q; cin>>n>>q;
    vl A(n);
    rep(i, n) cin>>A[i];
    
    ST st(A);

    while(q--) {
        /*
        cerr<<"\n-------------------------------------------------------\n";
        rep(u, 4 * n + 4) {
            if(st.Range[u].first == -1) continue;
            cerr<<"Node: "<<u<<"\n";
            cerr<<"Range = ["<<st.Range[u].first<<", "<<st.Range[u].second<<"]\n";
            cerr<<"Empty: "<<st.Empty[u]<<"\n";
            cerr<<"LazyAdding: "<<st.LazyAdding[u]<<"\n";
            cerr<<"RemainCapacity: "<<st.RemainCap[u]<<"\n";
            cerr<<"InitCapacity: "<<st.InitCap[u]<<"\n";
            cerr<<"\n";
        }
        */
        
        int type; cin>>type;
        if(type == 1) {
            int B, V; cin>>B>>V; B--;
            st.fill(V, B);
        }
        else {
            int i, j; cin>>i>>j; i--, j--;
            cout<<st.query(i, j)<<'\n';
            st.empty(i, j);
        }
    }


}