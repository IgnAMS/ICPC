#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define repx(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define rep(i, n) repx(i, 0, n)
#define pb push_back


int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ll n, m;
    ll a, b;
    cin >> n >> m;
    vector<pair<ll, ll>> lv, hv;

    repx(i, 0, n) {
        cin >> a >> b;
        if (b == 1) {
            lv.push_back({a, i});
        }
        else {
            hv.push_back({a, i});
        }
    }
    sort(lv.begin(), lv.end());
    sort(hv.begin(), hv.end());

    // repx(i, 0, lv.size()) {
    //     cout << lv[i].first << " ";
    // }
    // cout << "\n";
    // repx(i, 0, hv.size()) {
    //     cout << hv[i].first << " ";
    // }
    // cout << "\n";

    ll l = -1;
    ll r = n+ 1;
    ll lc = lv.size() - 1;
    ll hc = hv.size() - 1;
    ll s = 0;
    ll mlc, ms, mhc;
    while (r - l > 1) {
        ll mid = (r + l) / 2;
        // cerr << "mid: " << mid << "\n";
        s = 0;
        lc = lv.size() - 1;
        hc = hv.size() - 1;
        while ((lc >= 0 || hc >= 0) && (lv.size() - lc - 1 + hv.size() - hc - 1 < mid)) {
            if (lc >= 0 && hc >= 0) {
                if (lv[lc].first >= hv[hc].first) {
                    s += lv[lc].first;
                    lc--;
                }
                else {
                    s += hv[hc].first;
                    hc--;
                }
            }
            else if (lc >= 0) {
                s += lv[lc].first;
                lc--;
            }
            else if (hc >= 0) {
                s += hv[hc].first;
                hc--;
            }

            if (s >= m) break;
        }
        // cerr << "sum: " << s << "\n";

        if (s < m) l = mid;
        else {
            r = mid;
            mlc = lc;
            mhc = hc;
            ms = s;
        }
    }

    // cerr << ms << " " << mlc << " " << mhc << "\n";
    while (mhc < hv.size() - 1 && mlc >= 0) {
        if (ms - hv[mhc + 1].first + lv[mlc].first > m) {
            ms = ms - hv[mhc + 1].first + lv[mlc].first;
            mlc--;
            mhc++;
        }
        else {
            break;
        }
    }
    // cout << ms << " " << mlc << " " << mhc << "\n";

    cout << lv.size() - mlc - 1 + hv.size() - mhc - 1 << " " << lv.size() - mlc - 1 << "\n";
    // cout << lv[mlc + 1].second << "asdf\n";
    repx(i, mlc + 1, lv.size()) {
        cout << lv[i].second + 1 << " ";
    }
    repx(i, mhc + 1, hv.size()) {
        cout << hv[i].second + 1 << " ";
    }
    cout << "\n";
}