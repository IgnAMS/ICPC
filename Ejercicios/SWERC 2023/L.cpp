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

vl X[4][4];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>k>>n;
    ll A[k], B[k];
    rep(i, k) cin>>A[i];
    rep(i, k) cin>>B[i];

    rep(i, k) {
        X[min(A[i], B[i])][max(A[i], B[i])].pb(i);
    }

    ll ans[3][n];

    ll left = 0;
    // cerr<<"hola1\n";
    rep(i, X[3][3].size()) {
        rep(j, 3) rep(k, 3) ans[j][left + k] = X[3][3][i];
        left += 3;
    }

    // cerr<<"hola1\n";

    rep(i, X[2][3].size()) {
        // cout<<"entre aca xd?\n";
        // cout<<X[2][3][i]<<'\n';
        rep(j, 3) rep(k, 2) ans[j][left + k] = X[2][3][i];
        left += 2;
    }
    // cout<<left<<'\n';
    // cerr<<"hola2\n";

    ll l1 = min(X[1][2].size(), X[2][2].size());
    rep(_, l1) {
        rep(j, 2) ans[0][left + j] = X[1][2].back();
        rep(j, 2) rep(k, 2) ans[1 + j][left + k] = X[2][2].back();
        X[1][2].pop_back(); X[2][2].pop_back();
        left += 2;
    }
    // cerr<<"hola3\n";

    ll l2 = min(X[2][2].size() / 3, X[1][3].size() / 2);
    rep(_, l2) {
        rep(xd, 2) {
            rep(j, 3) ans[0][left + xd * 3 + j] = X[1][3].back();
            X[1][3].pop_back();
        }
        rep(xd, 3) {
            rep(j, 2) rep(k, 2) ans[1 + j][left + xd * 2 + k] = X[2][2].back();
            X[2][2].pop_back();
        }
        left += 6;
    }

    // cerr<<"hola4\n";
    ll l3 = min({X[2][2].size() / 2, X[1][1].size(), X[1][3].size()});
    rep(_, l3) {
        rep(j, 3) ans[0][left + j]  = X[1][3].back();
        ans[0][left + 3] = X[1][1].back();
        X[1][3].pop_back();
        X[1][1].pop_back();

        rep(xd, 2) {
            rep(j, 2) rep(k, 2) ans[1 + j][left + xd * 2 + k] = X[2][2].back();
            X[2][2].pop_back();
        }
        left += 4;
    }

    // cerr<<"hola5\n";
    ll l4 = min(X[2][2].size(), X[1][1].size() / 2);
    rep(_, l4) {
        rep(j, 2) {
            ans[0][left + j] = X[1][1].back();
            X[1][1].pop_back();
        }
        rep(j, 2) rep(k, 2) ans[1 + j][left + k] = X[2][2].back();
        X[2][2].pop_back();
        left += 2;
    }
    
    // cerr<<"hola6\n";

    rep(i, X[1][3].size()) {
        rep(j, 3) ans[j][left] = X[1][3][i];
        left++;
    }

    // cerr<<"hola7\n";
    ll l5 = min(X[1][2].size(), X[1][1].size());
    rep(_, l5) {
        ans[0][left] = X[1][1].back();
        X[1][1].pop_back();
        rep(j, 2) ans[1 + j][left] = X[1][2].back();
        X[1][2].pop_back();
        left++;
    }

    // cerr<<"hola8\n";

    ll l6 = X[1][2].size() / 3;
    rep(i, l6) {
        rep(j, 3) {
            rep(k, 2) ans[j][left + k] = X[1][2].back();
            X[1][2].pop_back();
        }
        left += 2;
    }

    // cerr<<"hola9\n";
    ll l7 = X[1][1].size() / 3;
    rep(i, l7) {
        rep(j, 3) {
            ans[j][left] = X[1][1].back();
            X[1][1].pop_back();
        }
        left += 1;
    }
    // cerr<<"hola10\n";

    rep(i, 3) {
        rep(j, n) cout<<ans[i][j] + 1<<' '; cout<<'\n';
    }


    return 0;
}