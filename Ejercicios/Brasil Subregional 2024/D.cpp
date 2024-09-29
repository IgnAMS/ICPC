#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define pb push_back

const ll MOD = 1e9+7, MOD2 = MOD*MOD;

vector<vl> MatrixMul(vector<vl> &A, vector<vl> &B) {
    vector<vl> res(A.size(), vl(A.size(), 0));
    rep(i, A.size()) {
        rep(j, B[0].size()) {
            rep(k, B.size()) {
                res[i][j] += A[i][k] * B[k][j];
                res[i][j] %= MOD;
                // if(res[i][j] >= MOD2) res[i][j] -= MOD2;
                // if(res[i][j] >= MOD) res[i][j] -= MOD; 
            }
        }
    }
    return res;
}

vl Mul(vector<vl>& A, vl &x) {
    vl res(A.size(), 0);
    rep(i, A.size()) {
        rep(j, A[0].size()) {
            res[i] += A[i][j] * x[j];
            res[i] %= MOD;
        }
    }
    return res;
}

vector<vl> binpow(vector<vl> &A, ll b) {
    vector<vl> res(A.size(), vl(A.size(), 0));
    rep(i, A.size()) res[i][i] = 1;
    while(b) {
        if(b & 1) res = MatrixMul(A, res);
        A = MatrixMul(A, A);
        b >>= 1;
    }
    return res;
}


// We have that dp[k] = sum_{i: k % 2^b[i] == 0} dp[k - a[i]]
// we can store the last 101 items, and calculate the new one by just shift the previous elements and sum the new one
// X[exp(k)] = {
//    {F[0], F[1], F[2], ...}, 
//    {1, 0, 0, ...}, 
//    {0, 1, 0, ...},
//    ...,
//    {0, 0, ..., 1, 0}
// }
// where exp is the lowest bit of the number k 
// and F[l] is the number of i = 0, ..., m - 1 such that b[i] <= exp(k) and a[i] == l

// The answer can be written like dp[n] = X[exp(n-1)] X[exp(n-2)] ... X[exp(n)] dp[0]

void solve() {
    ll n, m;
    cin>>n>>m;
    vl a(m), b(m);
    rep(i, m) cin>>a[i]>>b[i];
    vector<vector<vl>> X(61, vector<vl>(101, vl(101, 0)));

    
    rep(exp, 61) {
        rep(i, m) if(b[i] <= exp) X[exp][0][a[i]-1]++;
        rep(i, 100) X[exp][i + 1][i] = 1;
    }
    
    vector<vector<vl>> Acc(61, vector<vl>(101, vl(101, 0)));
    vl Sz(61);
    Acc[0] = X[0], Sz[0] = 1; 
    repx(i, 1, 61) {
        // Acc[i] = Acc[i-1] X[i] Acc[i-1]
        Acc[i] = MatrixMul(Acc[i - 1], X[i]);
        Acc[i] = MatrixMul(Acc[i], Acc[i - 1]);
        Sz[i] = 2 * Sz[i - 1] + 1;
    }

    ll curr = 0;
    vector<vl> Res(101, vl(101, 0));
    rep(i, 101) Res[i][i] = 1;
    while(curr != n) {
        auto ind = lower_bound(Sz.begin(), Sz.end(), n - curr) - Sz.begin();
        if(Sz[ind] > n - curr) ind--; 
        Res = MatrixMul(Acc[ind], Res);
        curr += Sz[ind];
        if(curr != n) {
            curr++;
            ll b = 0;
            while((curr & (1LL<<b)) == 0) b++;
            Res = MatrixMul(X[b], Res);
        }
    }
    vl dp(101, 0);
    dp[0] = 1;
    dp = Mul(Res, dp);
    cout<<dp[0]<<'\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    solve();

    return 0;
}
