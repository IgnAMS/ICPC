#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

template<class T>
class Hungarian {
    T inf = numeric_limits<T>::max();
    bool maxi, swapped = false;
    vector<vector<T>> cost;
    vector<T> u, v;
    vi p, way;
    int l, r;

public:
    // left/right == partition sizes
    Hungarian(int left, int right, bool maximizing) {
        l = left, r = right, maxi = maximizing;
        if (swapped = l > r) swap(l, r);
        cost.assign(l + 1, vector<T>(r + 1, 0));
        u.assign(l + 1, 0); v.assign(r + 1, 0);
        p.assign(r + 1, 0); way.assign(r + 1, 0);
    }

    void add_edge(int l, int r, T w) {
        assert(l and r);  // indices start from 1 !!
        if (swapped) swap(l, r);
        cost[l][r] = maxi ? -w : w;
    }

    // execute after all edges were added
    void calculate() {
        repx(i, 1, l + 1) {
            vector<bool> used(r + 1, false);
            vector<T> minv(r + 1, inf);
            int j0 = 0; p[0] = i;

            while (p[j0]) {
                int j1, i0 = p[j0]; used[j0] = true;
                T delta = inf;
                repx(j, 1, r + 1) if (not used[j])
                {
                    T cur = cost[i0][j] - u[i0] - v[j];
                    if (cur < minv[j]) minv[j] = cur, way[j] = j0;
                    if(minv[j] < delta) delta = minv[j], j1 = j;
                }
                rep(j, r + 1) {
                    if (used[j]) u[p[j]] += delta, v[j] -= delta;
                    else minv[j] -= delta;
                }
                j0 = j1;
            }

            while (j0) p[j0] = p[way[j0]], j0 = way[j0];
        }
    }

    // execute after executing calculate()
    T answer() { return maxi ? v[0] : -v[0]; }

    bool are_matched(int l, int r)
    {
        if (swapped) swap(l, r);
        return p[r] == l;
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll cost[n][n]; rep(i, n) rep(j, n) cin>>cost[i][j];
    Hungarian<ll> h(n / 2, n / 2, 0);
    rep(i, n / 2) {
        rep(j, n / 2) {
            ll w = cost[2 * i][2 * j + 1] + (2 * i + 2 < n? cost[2 * i + 2][2 * j + 1]: 0LL);
            // cout<<2 * i + 1<<' '<<2 * j + 2<<' '<<w<<'\n';
            h.add_edge(i + 1, j + 1, w);
        }
    }
    h.calculate();
    cout<<h.answer()<<'\n';

    return 0;
}