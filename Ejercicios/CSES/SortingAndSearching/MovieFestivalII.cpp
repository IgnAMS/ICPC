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
const int mxN = 2e5+5;
struct ST {
    int n;
    pll T[4 * mxN];
    void update(int i, ll x, int l, int r, int u) {
        if(l == r) T[u] = pll(x, i);
        else {
            int m = (l + r) / 2;
            if(i <= m) update(i, x, l, m, 2 * u + 1);
            else update(i, x, m + 1, r, 2 * u + 2);
            T[u] = min(T[2 * u + 1], T[2 * u + 2]);
        }
    }

    pll query(int i, int j, int l, int r, int u) {
        if(i <= l and r <= j) return T[u];
        if(j < l or r < i) return pll(INF, INF);
        int m = (l + r) / 2;
        return min(query(i, j, l, m, 2 * u + 1), query(i, j, m + 1, r, 2 * u + 2));
    }
} st_min, st_max;



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    vector<pll> A(n);
    rep(i, n) {
        cin>>A[i].ff>>A[i].ss;
    }
    sort(A.begin(), A.end());

    // Asigno st[i].T[u].ss = ind
    rep(i, k) {
        st_min.update(i, 0, 0, k - 1, 0);
        st_max.update(i, 0, 0, k - 1, 0);
    }
    ll cont = 0;
    rep(i, n) {
        auto [x, ind] = st_min.query(0, k - 1, 0, k - 1, 0);
        if(x <= A[i].ff) {
            cont++;
            st_min.update(ind, A[i].ss, 0, k - 1, 0);
            st_max.update(ind, -A[i].ss, 0, k - 1, 0);
        }
        else {
            auto [x, ind] = st_max.query(0, k - 1, 0, k - 1, 0);
            x *= -1;
            if(A[i].ss < x) {
                st_min.update(ind, A[i].ss, 0, k - 1, 0);
                st_max.update(ind, -A[i].ss, 0, k - 1, 0);
            }
        }
    }
    cout<<cont<<'\n';


    return 0;
}