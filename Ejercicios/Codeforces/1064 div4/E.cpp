#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
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

void solve() {
    int n, k, x; cin>>n>>k>>x;
    vl A(n); rep(i, n) cin>>A[i];
    sort(A.begin(), A.end());
    ll l = 0, r = 1e9+1;
    while(l < r) {
        ll m = (l + r + 1) / 2;
        ll curr = max(0LL, A[0] - m + 1) + max(0LL, x - A[n-1] - m + 1);
        rep(i, n - 1) {
            curr += max(0LL, A[i+1] - A[i] - 2 * m + 1);
        }
        if(curr >= k) l = m;
        else r = m - 1;
    }
    // cout<<l<<"\n";
    ll aux = 0;
    rep(i, min(A[0] - l+1, A[0])) {
        if(aux == k) return;
        aux++;
        cout<<i<<" ";
    }


    rep(i, n - 1) {
        repx(j, A[i] + l, min(A[i+1] - l+1, A[i+1])) {
            if(aux == k) return;
            aux++;
            cout<<j<<" ";
        }
    }

    repx(i, A[n-1] + l, x+1) {
        if(aux == k) return;
        aux++;
        cout<<i<<" ";
    }

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    // t = 1;
    while(t--) {
        solve();
        cout<<"\n";

    }

    return 0;
}