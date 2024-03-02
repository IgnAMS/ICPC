#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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

int n, k;
ll A[35005];
ll DP_bef[35005], DP_curr[35005];

// n * k * log(n) * log(n) ~ 4 * 10^8

void compute(int l, int r, int optl, int optr) {
    if(l > r) return;

    int mid = (l + r) / 2;
    ll bestans = 0, bestind = -1;
    set<ll> S;
    repx(k, min(optr, mid), mid + 1) S.insert(A[k]);
    for(int k = min(optr, mid); k >= optl; k--) {
        S.insert(A[k]);
        ll new_cost = (k? DP_bef[k - 1]: 0) - (int)S.size();
        // cout<<C[k][mid] - (int)S.size()<<'\n';
        // cout<<C[k][mid]<<' '<<S.size()<<'\n';
        // cout<<k<<' '<<mid<<"\n\n";
        if(bestans > new_cost or (bestans == new_cost and bestind > k)) {
            bestans = new_cost, bestind = k;
        }
    }
    S.clear();
    // cout<<l<<' '<<r<<' '<<optl<<' '<<optr<<' '<<bestans<<'\n';
    DP_curr[mid] = bestans;
    int opt = bestind;
    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    rep(i, n) cin>>A[i];

    memset(DP_bef, 0, sizeof(DP_bef));
    memset(DP_curr, 0, sizeof(DP_curr));

    set<ll> S;
    S.clear();
    rep(i, n) {
        S.insert(A[i]);
        DP_bef[i] = S.size();
    }
    rep(i, k) {
        compute(0, n - 1, 0, n - 1);
        rep(j, n) DP_bef[j] = DP_curr[j];
    }
    cout<<-DP_bef[n - 1]<<'\n';


    return 0;
}