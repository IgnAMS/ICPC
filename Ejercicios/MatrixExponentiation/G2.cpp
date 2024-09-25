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


ll n, k;
vl A;
ll C[11];
ll p, q, r;


// a_i = sum_{1 <= j <= n} c_j * a_{i-j} + p + i * q + i^2 * r
// a_i = sum_{1 <= j <= n} c_j * a_{i-j} 
//       + p * (i - n + 1) * (i - n + 2) / 2 + r * (i * (i + 1) * (2 * i + 1) * minv(6) - (n-1) * n * (2*(n-1) + 1) * minv(6))
//       + q * ((i-n+1) * (i-n+2) / 2)^2


const ll MOD = 1e9+7;

struct Matrix {
    vector<vl> M;
    Matrix(int n) {
        M.assign(n, vl(n, 0));
        rep(i, n) M[i][i] = 1;
    }
    Matrix init0(int n) {
        Matrix res(n);
        rep(i, n) res.M[i][i] = 0;
        return res;
    }
    Matrix operator*(const Matrix& B) {
        int n = B.M.size();
        Matrix res = init0(n);
        rep(i, n) rep(j, n) rep(k, n) {
            res.M[i][j] += M[i][k] * B.M[k][j];
            res.M[i][j] %= MOD;
        }
        return res;
    }
    vl operator*(const vl& x) {
        int n = x.size();
        vl ans(n, 0);
        rep(i, n) {
            rep(j, n) {
                ans[i] += M[i][j] * x[j];
                ans[i] %= MOD;
            }
        }
        return ans;
    }
};

Matrix binpow(Matrix A, ll b) {
    int n = A.M.size();
    Matrix res(n);
    while(b) {
        if(b & 1) res = res * A;
        A = A * A;
        b >>= 1;
    }
    return res;
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    A.resize(n);
    rep(i, n) cin>>A[n - i - 1];
    rep(i, n) cin>>C[i];
    cin>>p>>q>>r;
    
    Matrix Transition(n);
    rep(i, n) Transition.M[i][i] = 0;
    rep(i, n) Transition.M[0][i] = C[i];
    rep(i, n - 1) Transition.M[i + 1][i] = 1;
    
    // DPp = {suma[i], Fib[i], Fib[i], Fib_[i-2], ..., Fib[i-n+1]}
    Matrix Tp(n + 1);
    rep(i, n + 1) Tp.M[i][i] = 0;
    Tp.M[0][0] = Tp.M[0][1] = 1; // suma += current
    rep(i, n) Tp.M[1][1 + i] = C[i]; // X[i] = sum X[i - j] * C[j]
    rep(i, n - 1) Tp.M[i + 2][i + 1] = 1; // shifting
    vl DPp(n + 1, 0);
    DPp[1] = 1;

    Matrix Tq(n + 2);
    rep(i, n + 2) Tq.M[i][i] = 0;
    rep(i, n) Tq.M[0][i] = C[i]; Tq.M[0][n] = 1; // Q[i] = sum C[j] * Q[i - j] + curr
    rep(i, n - 1) Tq.M[i + 1][i] = 1; // shifting 
    Tq.M[n][n] = Tq.M[n][n + 1] = 1; // curr = curr + i
    Tq.M[n + 1][n + 1] = 1; // X[n + 1] = 1

    vl DPq(n + 2, 0);
    DPq[n] = n; // curr
    DPq[n + 1] = 1; // 1

    Matrix Tr(n + 3);
    rep(i, n + 3) Tr.M[i][i] = 0;
    rep(i, n)  Tr.M[0][i] = C[i]; Tr.M[0][n] = 1; // R[i] += sum C[j] * R[i - j] + sqr 
    rep(i, n - 1) Tr.M[i + 1][i] = 1; // shifting
    Tr.M[n][n] = Tr.M[n][n + 1] = 1; // sqr = sqr + 2 * step (cuadrados perfectos)
    Tr.M[n + 1][n + 1] = 1, Tr.M[n + 1][n + 2] = 2; // step = step + 2
    Tr.M[n + 2][n + 2] = 1; // X[n + 2] = 1

    vl DPr(n + 3, 0);
    DPr[n] = n * n; // sqr
    DPr[n + 1] = 2 * n + 1; // step
    DPr[n + 2] = 1; // 1

    vl X(n);
    rep(i, n) X[i] = A[n - i - 1];
    rep(i, n) cout<<X[i]<<' '; cout<<'\n';
    for(ll k = n; k <= 10; k++) {
        Matrix M = binpow(Transition, k - n + 1);
        vl dp = M * A;
        rep(i, n) cout<<dp[i]<<' '; cout<<'\n';

        Matrix Mp = binpow(Tp, k - n + 1);
        vl auxp = Mp * DPp;
        Matrix Mq = binpow(Tq, k - n + 1);
        vl auxq = Mq * DPq;
        Matrix Mr = binpow(Tr, k - n + 1);
        vl auxr = Mr * DPr;

        ll curr = p + (k % MOD) * q + ((k % MOD) * (k % MOD) % MOD) * r;
        curr %= MOD;
        rep(i, n) {
            curr += X[X.size() - i - 1] * C[i] % MOD;
            curr %= MOD;
        }
        X.pb(curr);
        // cout<<dp[0]<<' '<<auxp[0]<<' '<<auxq[0]<<' '<<auxr[0]<<'\n';
        cout<<curr<<' '<<(dp[0] + auxp[0] * p + auxq[0] * q + auxr[0] * r) % MOD<<'\n';
        cout<<'\n';
    }

    return 0;
}