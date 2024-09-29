#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)

const int mxN = 55;
int a[mxN][mxN];

void solve(){
    int n;
    cin >> n;
    rep(i, n){
        rep(j, n){
            cin >> a[i][j];
        }
    }
    vector<pair<int, int>> f;
    f.push_back({a[0][0], 0});
    f.push_back({a[0][n-1], 1});
    f.push_back({a[n-1][n-1], 2});
    f.push_back({a[n-1][0], 3});
    sort(f.begin(), f.end());
    cout << f[0].second;
    
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    solve();

    return 0;
}