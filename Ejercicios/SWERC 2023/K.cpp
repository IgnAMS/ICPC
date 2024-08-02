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
    vector<int> T;
    int N;
    ST(int n) {
        N = n;
        T.assign(4 * n, 0);
        build(0, n - 1, 0);
    }

    void build(int l, int r, int u = 0) {
        if(l == r) {
            T[u] = 1;
            return;
        }
        else {
            int m = (l + r) / 2;
            build(l, m, 2 * u + 1);
            build(m + 1, r, 2 * u + 2);
            T[u] = T[2 * u + 1] + T[2 * u + 2];
        }
    }

    void update(int i, int x, int l, int r, int u = 0) {
        if(l == r) {
            T[u] = x;
            return;
        }
        int m = (l + r) / 2;
        if(i <= m) update(i, x, l, m, 2 * u + 1);
        else update(i, x, m + 1, r, 2 * u + 2);
        T[u] = T[2 * u + 1] + T[2 * u + 2];
    }
    void update(int i, int x) { update(i, x, 0, N - 1, 0); }
    
    int query(int x, int l, int r, int u = 0) {
        if(l == r) return l;
        int m = (l + r) / 2;
        if(x <= T[2 * u + 1]) return query(x, l, m, 2 * u + 1);
        return query(x - T[2 * u + 1], m + 1, r, 2 * u + 2);
    }
    int query(int x) { return query(x, 0, N - 1, 0); }
};



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ST st(n);
    ll A[n / 2], B[n / 2];
    rep(i, n / 2) {
        cin>>A[i];
    }
    rep(i, n / 2) {
        cin>>B[i];
    }
    
    vl AA, AB;
    rep(i, n) { 
        int x;
        // cerr<<"nueva busqueda\n";
        if((i & 1) == 0) {
            x = st.query(A[i / 2]);
            // cout<<x + 1<<'\n';
            AA.pb(x + 1);
            st.update(x, 0);
        }
        else {
            x = st.query(B[i / 2]);
            // cout<<x + 1<<'\n';
            AB.pb(x + 1);
            st.update(x, 0);
        }   
    }
    rep(i, n / 2) cout<<AA[i]<<' '; cout<<'\n';
    rep(i, n / 2) cout<<AB[i]<<' '; cout<<'\n';


    return 0;
}