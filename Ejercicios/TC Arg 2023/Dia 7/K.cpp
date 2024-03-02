#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define ff first
#define ss second
#define rep(i, n) for(int i = 0; i < n; i++)


const int mxN = 2e5+5;

struct SEG{
    ll tree[4*mxN];
    void init(){
        memset(tree, 0, sizeof(tree));
    }
    void merge(int i){
        tree[i] = tree[2*i] + tree[2*i+1];
    }
    void upd(int l1, int r1, int l2, int r2, int i, ll val){
        if(l2 > r1 || r2 < l1) return;
        if(l1<=l2 && r2<=r1){
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
        if(l1 <= l2 && r2 <= r1) return tree[i];
        int m2 = (l2+r2)/2;
        return qry(l1, r1, l2, m2, 2*i) + qry(l1, r1, m2+1, r2, 2*i+1);
    }

}seg[12];






int n, k;
ll a[mxN];

int main() {

    rep(i, 12) seg[i].init();
    cin >> n >> k;
    rep(i, n){
        cin >> a[i], --a[i];
    }

    rep(i, n){
        for(int x = k; x>=0; --x){
            if(x == 0){
                seg[0].upd(a[i], a[i], 0, n-1, 1, 1);
                continue;
            }
            ll value = seg[x-1].qry(0, a[i], 0, n-1, 1);
            seg[x].upd(a[i], a[i], 0, n-1, 1, value);
        }
    }

    cout << seg[k].qry(0, n-1, 0, n-1, 1);
}