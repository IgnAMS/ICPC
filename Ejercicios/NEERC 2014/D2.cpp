#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define ff first
#define ss second
#define repx(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define rep(i, n) repx(i, 0, n)
#define pb push_back


int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m;
    ll a, b;
    cin >> n >> m;
    vector<pll> lv, hv;

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

    lc = lv.size() - 1;
    hc = hv.size() - 1;
    
    ll acc = 0;
    while(acc < m and lc >= 0 and hc >= 0) {
        if(lc == -1)  acc += hv[hc], hc--;
        else if(hc == -1) acc += lv[lc], lc--;
        else if(lv[lc] >= hv[hc]) acc += lv[lc], lc--;
        else acc += hv[hc], hc--;
    }
    if(acc < m) {
        cout<<"-1\n";
        return 0;
    }

    while(lc >= 0 and hc < hv.size() and acc + lv[lc] - hv[hc] >= m) {
        acc += lv[lc] - hv[hc];
        lc--, hc++;
    }
    
    cout<<(lv.size() - lc + 1) + (hv.size() - hc + 1)<<'\n';
    for(int i = lc + 1; i < lv.size(); i++) cout<<lv[i]<<' ';
    for(int i = hc + 1; i < hv.size(); i++) cout<<hv[i]<<' ';
}

