#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<iostream>
#include<algorithm>
#include<numeric>
#include <cmath>
#include<set>
#include<array>
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
// g++ -std=c++17 A.cpp -o a && ./a <input.txt> output.txt   
// ulimit -s 1000000
// g++ -std=c++17 -O2 A.cpp && time ./a.out <input.txt> output.txt

struct ST {
    int N;
    vector<pll> Mn, Mx;

    ST(int n, vl A): N(n), Mn(4 * (n+1), {1e9, -1}), Mx(4 * (n+1), {-1e9, -1}) {
        build(0, n-1, 0, A);
    }

    void build(int l, int r, int u, vl& A) {
        if(l == r) {
            Mn[u] = Mx[u] = {A[l], l};
            return;
        }
        int m = (l + r) / 2;
        build(l, m, 2 * u + 1, A);
        build(m+1, r, 2 * u + 2, A);
        Mn[u] = min(Mn[2*u+1], Mn[2*u+2]);
        Mx[u] = max(Mx[2*u+1], Mx[2*u+2]);
    }

    void set(int x, int i, int l, int r, int u) {
        if(l == r) {
            Mn[u] = Mx[u] = {x, l};
            return;
        }
        int m = (l + r) / 2;
        if(i <= m) set(x, i, l, m, 2 * u + 1);
        else set(x, i, m+1, r, 2 * u + 2);
        Mn[u] = min(Mn[2*u+1], Mn[2*u+2]);
        Mx[u] = max(Mx[2*u+1], Mx[2*u+2]);
    }
    void set(int x, int i) {
        set(x, i, 0, N-1, 0);
    }

    pll mn_query(int i, int j, int l, int r, int u) {
        if(i <= l and r <= j) return Mn[u];
        if(r < i or j < l) return {1e9, -1};
        int m = (l + r) / 2;
        return min(mn_query(i, j, l, m, 2*u+1), mn_query(i, j, m+1, r, 2*u+2));
    }   
    pll mn_query(int i, int j) {
        return mn_query(i, j, 0, N-1, 0);
    }

    pll mx_query(int i, int j, int l, int r, int u) {
        if(i <= l and r <= j) return Mx[u];
        if(r < i or j < l) return {-1e9, -1};
        int m = (l + r) / 2;
        return max(mx_query(i, j, l, m, 2*u+1), mx_query(i, j, m+1, r, 2*u+2));
    }
    pll mx_query(int i, int j) {
        return mx_query(i, j, 0, N-1, 0);
    }
};



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    vl A(n); rep(i, n) cin>>A[i];
    ST st(n, A);

    while(q--) {
        int l, r; cin>>l>>r; l--, r--;
        ll val = A[l] * A[r];
        // max(
        //      val * min_{i in [l+1, r-1]} A[i] * max_{j in [l+1, r+1]} A[i]),
        //      val * min_{i in [l+1, r-1]} A[i] * min_{j in [l+1, r+1]: j != i} A[i] 
        //      val * max_{i in [l+1, r-1]} A[i] * max_{j in [l+1, r+1]: j != i} A[i]
        // )
        pll min_val = st.mn_query(l+1, r-1);
        pll max_val = st.mx_query(l+1, r-1);

        ll best = val * min_val.ff * max_val.ff;
        st.set(10000, min_val.ss);
        pll second_min = st.mn_query(l+1, r-1);
        st.set(min_val.ff, min_val.ss);
        
        
        st.set(-10000, max_val.ss);
        pll second_max = st.mx_query(l+1, r-1);
        st.set(max_val.ff, max_val.ss);

        // cout<<"val: "<<val<<", min_val: "<<min_val.ff<<", max_val: "<<max_val.ff<<", second_max: "<<second_max.ff<<", second_min: "<<second_min.ff<<"\n";

        best = max({
            best, 
            val * min_val.ff * second_min.ff,
            val * max_val.ff * second_max.ff
        });
        cout<<best<<"\n";
    }




    return 0;
}
