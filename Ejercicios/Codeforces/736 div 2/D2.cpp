#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))
 
template<typename it, typename bin_op>
struct sparse_table {
 
    using T = typename remove_reference<decltype(*declval<it>())>::type;
    vector<vector<T>> t; bin_op f;
 
    sparse_table(it first, it last, bin_op op) : t(1), f(op) {
        int n = distance(first, last);
        t.assign(32-__builtin_clz(n), vector<T>(n));
        t[0].assign(first, last);
        for (int i = 1; i < t.size(); i++)
            for (int j = 0; j < n-(1<<i)+1; j++)
                t[i][j] = f(t[i-1][j], t[i-1][j+(1<<(i-1))]);
    }
 
    // returns f(a[l..r]) in O(1) time
    T query(int l, int r) {
        int h = floor(log2(r-l+1));
        return f(t[h][l], t[h][r-(1<<h)+1]);
    }
};
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> a(n), d(n-1);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n-1; i++)
            d[i] = abs(a[i+1]-a[i]);
        sparse_table g(all(d), [](ll x, ll y){
            return __gcd(x, y);
        });
        int j = 0, ans = 1;
        for (int i = 0; i < n-1; i++) {
            while (j <= i && g.query(j, i) == 1) j++;
            cerr<<i<<' '<<j<<' '<<g.query(j, i)<<'\n';
            cmax(ans, i-j+2);
        }
        cout << ans << "\n";
    }
}