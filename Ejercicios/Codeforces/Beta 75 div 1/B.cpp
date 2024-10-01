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


struct ST {
    vl T;
    int N;
    ST(vl A) {
        N = A.size();
        T.assign(4 * N + 2, 0);
        build(0, N - 1, 0, A);
    }
    void build(int l, int r, int u, vl& A) {
        if(l == r) T[u] = A[l];
        else {
            int m = (l + r) / 2;
            build(l, m, 2 * u + 1, A);
            build(m + 1, r, 2 * u + 2, A);
            T[u] = min(T[2 * u + 1], T[2 * u + 2]);
        }
    }
    ll query(int i, int j, int l, int r, int u) {
        if(i <= l and r <= j) return T[u];
        if(l > j or r < i) return 1e10;

        int m = (l + r) / 2;
        return min(query(i, j, l, m, 2 * u + 1), query(i, j, m + 1, r, 2 * u + 2));
    }
    ll query(int i, int j) { return query(i, j, 0, N - 1, 0); }  
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vl A(n); rep(i, n) cin>>A[i];
    ST st(A);
    vl Ans(n);
    rep(i, n) {
        int l = i, r = n;
        while(l < r) {
            int m = (l + r) / 2;
            if(A[i] <= st.query(m, n - 1)) r = m;
            else l = m + 1;
        }
        // cerr<<st.query(3, n - 1)<<'\n';
        // cerr<<i<<' '<<l<<'\n';
        if(l == i) cout<<l - i - 1<<' ';
        else cout<<l - i - 2<<' ';
    }
    cout<<'\n';



    return 0;
}