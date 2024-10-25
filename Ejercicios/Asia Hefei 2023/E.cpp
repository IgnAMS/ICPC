#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
typedef long long ll;
typedef pair<ll, ll> pll;


int main() {    
    ios::sync_with_stdio(0); cin.tie(0);

    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> mat(n, vector<ll>(m));
    rep(i, n) {
        rep(j, m) {
            cin >> mat[i][j];
        }
    }

    unordered_map<ll, vector<ll>> pasadax;
    pasadax.reserve(1000000);
    ll ansx = 0;
    ll cursum = 0;
    vector<ll> cur;
    rep(j, m) {
        rep(i, n) {
            cur = pasadax[mat[i][j]];
            if(cur.size() == 0) {
                // cout << "setting on " << i << " " << j << endl;
                pasadax[mat[i][j]] = {1, 0, j};
            }
            else {
                // cout << "found prev (" << pasadax[mat[i][j]][0] << " " << pasadax[mat[i][j]][1] << " " << pasadax[mat[i][j]][2] << ")" << endl;
                cursum = cur[1] + (j - cur[2])*cur[0];
                // cout << "adding " << cursum << endl;
                ansx += cursum;
                pasadax[mat[i][j]] = {cur[0] + 1, cursum, j};
            }
        }
    }

    unordered_map<ll, vector<ll>> pasaday;
    pasaday.reserve(1000000);
    ll ansy = 0;
    cursum = 0;
    rep(i, n) {
        rep(j, m) {
            cur = pasaday[mat[i][j]];
            if(cur.size() == 0) {
                pasaday[mat[i][j]] = {1, 0, i};
            }
            else {
                cursum = cur[1] + (i - cur[2])*cur[0];
                ansy += cursum;
                pasaday[mat[i][j]] = {cur[0] + 1, cursum, i};
            }
        }
    }

    // cout << ansx << endl;
    // cout << ansy << endl;

    cout << 2*(ansx + ansy) << endl;

    return 0;
}

