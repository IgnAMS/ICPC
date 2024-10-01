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


const ll INF = 1e15;
struct ST {
    vl T, Acc;
    int n;
    ST(vl& A, int N): T(4 * N), Acc(4 * N, 0), n(N) {
        build(A, 0, N - 1, 0);
    }
    void build(vl& A, ll l, ll r, ll u) {
        if(l == r) T[u] = A[l];
        else {
            ll m = (l + r) / 2;
            build(A, l, m, 2 * u + 1);
            build(A, m + 1, r, 2 * u + 2);
            T[u] = min(T[2 * u + 1], T[2 * u + 2]);
        }
    }
    void update(ll i, ll j, ll v, ll l, ll r, ll u = 0) {
        // cout<<"actualizo el segmento "<<l<<' '<<r<<" en "<<v<<'\n';
        if(i <= l and r <= j) {
            Acc[u] += v; return;
        }
        if(r < i or j < l) return;
        ll m = (l + r) / 2;
        update(i, j, v, l, m, 2 * u + 1);
        update(i, j, v, m + 1, r, 2 * u + 2);
        ll left = T[2 * u + 1] + Acc[2 * u + 1];
        ll right = T[2 * u + 2] + Acc[2 * u + 2];
        T[u] = min(left, right);
    }
    ll query(ll i, ll j, ll l, ll r, ll u = 0) {
        if(i <= l and r <= j) return Acc[u] + T[u];
        if(r < i or j < l) return INF;
        ll m = (l + r) / 2;
        ll left = query(i, j, l, m, 2 * u + 1);
        ll right = query(i, j, m + 1, r, 2 * u + 2);
        // cout<<"query "<<l<<' '<<r<<' '<<left<<' '<<right<<' '<<Acc[u]<<'\n';
        if(left == INF) return Acc[u] + right;
        if(right == INF) return Acc[u] + left;
        return Acc[u] + min(left, right);
    }

};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vl A(n); rep(i, n) cin>>A[i];
    ST st(A, n);

    int m; cin>>m;
    string xd; getline(cin, xd);
    rep(_, m) {
        string s; getline(cin, s);
        vl N;
        ll curr = 0, sign = 1;
        for(auto c: s) {
            if(c == '-') sign = -1;
            else if(c == ' ') {
                N.pb(sign * curr);
                curr = 0, sign = 1;
            }
            else {
                curr = curr * 10 + ll(c - '0');
            }
        }
        N.pb(sign * curr);
        
        // for(auto u: N) cout<<u<<' '; cout<<'\n';
        if(N.size() == 2) {
            if(N[0] > N[1]) {
                ll left = st.query(0, N[1], 0, n - 1, 0);
                ll right = st.query(N[0], n - 1, 0, n - 1, 0);
                cout<<min(left, right)<<'\n';
            }
            else cout<<st.query(N[0], N[1], 0, n - 1, 0)<<'\n';
        }
        else {
            if(N[0] > N[1]) {
                st.update(0, N[1], N[2], 0, n - 1, 0);
                st.update(N[0], n - 1, N[2], 0, n - 1, 0);
            }
            else st.update(N[0], N[1], N[2], 0, n - 1, 0);
        }
    }    




    return 0;
}