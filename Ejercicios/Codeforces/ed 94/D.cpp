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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace __gnu_pbds;
 
// typedef tree<
// array<ll, 3>,
// null_type,
// less_equal<array<ll, 3>>,
// rb_tree_tag,
// tree_order_statistics_node_update>
// ordered_set;

typedef tree<
ll,
null_type,
less_equal<ll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

const int mxN = 3004;
ll X[3005][3005];

void solve() {
    int n; cin>>n;
    ll A[n]; rep(i, n) cin>>A[i];
    ll ans = 0;
    rep(i, n + 1) rep(j, n + 1) X[i][j] = 0;
    rep(i, n) {
        repx(j, i + 1, n) ans += X[A[i]][A[j]];
        rep(j, i) X[A[j]][A[i]]++;
    }
    cout<<ans<<'\n';
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        solve();
    }

    return 0;
}