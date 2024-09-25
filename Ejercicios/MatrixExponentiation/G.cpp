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
            res.M[i][j] += M[i][k] * B.M[k][j] % MOD;
            res.M[i][j] %= MOD;
        }
        return res;
    }
    vl operator*(const vl& x) {
        int n = x.size();
        vl ans(n, 0);
        rep(i, n) {
            rep(j, n) {
                ans[i] += M[i][j] * x[j] % MOD;
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
    
    // DPp[i] = {suma[i], Fib[i], Fib[i], Fib_[i-2], ..., Fib[i-n+1]}
    // suma[i + 1] = suma[i] + Fib[i] 
    // Fib[i + 1] = sum C[j] * Fib[i - j]
    // curr 
    Matrix Tp(n + 1);
    rep(i, n + 1) Tp.M[i][i] = 0;
    Tp.M[0][0] = Tp.M[0][1] = 1;  // suma[i + 1] = suma[i] + Fib[i]
    rep(i, n) Tp.M[1][1 + i] = C[i]; // Fib[i + 1] = sum C[j] * Fib[i - j] 
    rep(i, n - 1) Tp.M[i + 2][i + 1] = 1; // shifting F
    vl DPp(n + 1, 0); // suma[0] = 0
    DPp[1] = 1; // Fib[0] = 1

    // DPq =  {suma[i], suma[i-1], ..., suma[i-n+1], num[i], 1}
    // suma[i + 1] = sum C[j] * suma[i - j] + num[i]
    // num[i + 1] = num[i] + 1
    Matrix Tq(n + 2);
    rep(i, n + 2) Tq.M[i][i] = 0;
    rep(i, n) Tq.M[0][i] = C[i]; Tq.M[0][n] = 1; // suma[i + 1] = sum C[j] * suma[i - j] + num[i]
    rep(i, n - 1) Tq.M[i + 1][i] = 1; // shifting
    Tq.M[n][n] = Tq.M[n][n + 1] = 1; // num[i + 1] = num[i] + 1
    Tq.M[n + 1][n + 1] = 1; // 1
    vl DPq(n + 2, 0);
    DPq[n] = n; // num[i]
    DPq[n + 1] = 1; // 1


    // DPr = {suma[i], suma[i-1], ..., suma[i-n+1], square[i], step[i], 1}
    // suma[i + 1] = sum C[j] * suma[i - j] + square[i]
    // square[i + 1] = square[i] + step[i]
    // step[i + 1] = step[i] + 2 * 1
    Matrix Tr(n + 3);
    rep(i, n + 3) Tr.M[i][i] = 0;
    rep(i, n)  Tr.M[0][i] = C[i]; Tr.M[0][n] = 1; // suma[i + 1] = sum C[j] * suma[i - j] + square[i]
    rep(i, n - 1) Tr.M[i + 1][i] = 1; // shifting
    Tr.M[n][n] = Tr.M[n][n + 1] = 1; // square[i + 1] = square[i] + step[i]
    Tr.M[n + 1][n + 1] = 1, Tr.M[n + 1][n + 2] = 2; // step[i + 1] = step[i] + 2 * 1
    Tr.M[n + 2][n + 2] = 1; // 1

    vl DPr(n + 3, 0);
    DPr[n] = n * n; // square[i] = n * n
    DPr[n + 1] = 2 * n + 1; // step = 2 * n + 1
    DPr[n + 2] = 1; // 1

    if(k <= n - 1) cout<<A[n - 1 - k]<<'\n';
    else {
        Matrix M = binpow(Transition, k - n + 1);
        vl dp = M * A;
        Matrix Mp = binpow(Tp, k - n + 1);
        vl auxp = Mp * DPp;
        Matrix Mq = binpow(Tq, k - n + 1);
        vl auxq = Mq * DPq;
        Matrix Mr = binpow(Tr, k - n + 1);
        vl auxr = Mr * DPr;
        cout<<(dp[0] + auxp[0] * p % MOD + auxq[0] * q % MOD + auxr[0] * r % MOD) % MOD<<'\n';
    }

    return 0;
}