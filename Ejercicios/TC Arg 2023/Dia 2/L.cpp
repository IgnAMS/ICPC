#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define rep(i, n) for(int i = 0; i<(int)n; ++i)
#define ff first
#define ss second
const int mxN = 2e5+5;

struct SEG{
    ll tree[4*mxN];
    void init(){
        memset(tree, 0, sizeof(tree));
    }
    void merge(int i){
        tree[i] = tree[2*i]+tree[2*i+1];
    }
    void upd(int l1, int r1, int l2, int r2, int i, ll val){
        if(l2 > r1 || r2 < l1) return;
        if(l1 <= l2 && r2 <= r1){
            tree[i] += val;
            return;
        }
        int m2 = (l2+r2)/2;
        upd(l1, r1, l2, m2, 2*i, val);
        upd(l1, r1, m2+1, r2, 2*i+1, val);
        merge(i);
    }
    ll qry(int l1, int r1, int l2, int r2, int i){
        if(l2 > r1 || r2 < l1) return 0;
        if(l1 <= l2 && r2 <= r1){
            return tree[i];
        }
        int m2 = (l2+r2)/2;
        return qry(l1, r1, l2, m2, 2*i) + qry(l1, r1, m2+1, r2, 2*i+1);
    }
}seg;


int main() {
    int n;
    cin >> n;
    seg.init();
    vl L(n), R(n);
    vector<vector<ll>> X(n);
    rep(i, n){
        int l, r;
        cin >> l >> r;
        X[i] = {l, r, i};
    }
    sort(X.begin(), X.end(), [&](const vl a, const vl b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });

    ll l = -1, r = -1;
    ll ans = -2;
    rep(i, n) {
        // cout<<r<<' '<<X[i][0]<<' '<<X[i][1]<<' '<<X[i][2]<<'\n';
        if(X[i][0] <= r and X[i][1] <= r) ans = X[i][2];
        if(i < n - 1 and X[i][0] <= r and X[i + 1][0] <= r + 1) ans = X[i][2];
        r = max(r, X[i][1]);
    }
    cout<<ans + 1<<'\n';
}


// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt
