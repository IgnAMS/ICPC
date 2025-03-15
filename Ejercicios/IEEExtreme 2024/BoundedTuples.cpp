#include <bits/stdc++.h>
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define all(a) (a).begin(), (a).end()
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define mii map<int, int>
#define mll map<ll, ll>
#define REP(i, a, b) for(int i = (a); i < (b); i++)
#define printv(v) REP(i, 0, (v).size()) { cout << (v)[i] << (i != (v).size() - 1 ? " " : "\n"); }
#define pb push_back
using namespace std;

const ll INF = 1e18+5;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<pl> constraints(m);
    vector<pl> ranges(n, {0, INF});
    REP(i, 0, m) {
        ll l, h, k;
        cin >> l >> h >> k;
        REP(j, 0, k) {
            ll c;
            cin >> c;
            ranges[c] = {max(ranges[c].first, l), min(ranges[c].second, h)};
        }
    }

    bool inf = false;
    REP(i, 0, n) {
        if(ranges[i].first > ranges[i].second) {
            cout << "0\n";
            return;
        }
        else if(ranges[i].second == INF) {
            inf = true;
        }
    }
    if(inf) {
        cout << "infinity\n";
        return;
    }

    cout << "0\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    for(int t = 1; t <= tc; t++) {
        solve();
    }

    return 0;
}
