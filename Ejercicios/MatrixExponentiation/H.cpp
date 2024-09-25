#pragma GCC optimize("Ofast")
// #pragma GCC target("popcnt") 
// #pragma GCC target("sse4")   
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

const ll MOD = 1e9+7;

struct Matrix {
    ll M[2][2];
    Matrix() {
        memset(M, 0, sizeof(M));
        M[0][0] = M[1][1] = 1;
    }
    Matrix(char c) {
        if(c == 'H') {
            M[1][0] = M[1][1] = 1;
            M[0][0] = M[0][1] = 0;
        }  
        else if(c == 'S' or c == 'D') {
            M[0][1] = M[0][0] = 1;
            M[1][0] = M[1][1] = 0;
        }
        else if(c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U') {
            M[0][1] = 1, M[1][0] = 1;
            M[1][1] = 0, M[0][0] = 0;
        }
        else if('A' <= c and c <= 'Z') {
            M[0][0] = 1, M[1][1] = 1, M[0][1] = 0, M[1][0] = 0;
        } 
        else { // c == '?'
            M[0][0] = 18 + 2;
            M[1][1] = 18 + 1;
            M[0][1] = 5 + 2;
            M[1][0] = 5 + 1;
        }
    }
    Matrix operator*(const Matrix& B) {
        Matrix res; 
        memset(res.M, 0, sizeof(res.M));
        rep(i, 2) rep(j, 2) rep(k, 2) {
            res.M[i][j] += M[i][k] * B.M[k][j];
            res.M[i][j] %= MOD;
        }
        return res;
    }
    Matrix(const Matrix& A, const Matrix& B) {
        memset(M, 0, sizeof(M));
        rep(i, 2) rep(j, 2) rep(k, 2) {
            // swap A and B if necessary
            M[i][j] += B.M[i][k] * A.M[k][j];
            M[i][j] %= MOD;
        }
    }
    vl operator*(const vl& x) {
        vl ans(2, 0);
        rep(i, 2) {
            rep(j, 2) {
                ans[i] += M[i][j] * x[j];
                ans[i] %= MOD;
            }
        }
        return ans;
    }
};


template <class node>
struct ST {
    int n;
    vector<node> t;
    ST(vector<node> &arr, int N): n(N), t(N * 2) {
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i) t[i] = node(t[i << 1], t[i << 1 | 1]);
    }
    void set(int p, const char c) {
        for (t[p += n] = Matrix(c); p >>= 1;)
            t[p] = node(t[p << 1], t[p << 1 | 1]);
    }
    node query(int l, int r) {
        node ansl, ansr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ansl = node(ansl, t[l++]);
            if (r & 1) ansr = node(t[--r], ansr);
        }
        return node(ansl, ansr);
    }
};


// 2 * 10^5 * 8 * 17

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    string s; cin>>s;
    vector<Matrix> A(n);
    rep(i, n) A[i] = Matrix(s[i]);
    ST<Matrix> st(A, n);
    vl dp(2, 0); dp[1] = 1;
    
    // cout<<2e5 * 17 * 8<<'\n';
    // cout<<(st.query(0, n) * dp)[1]<<'\n';
    Matrix M = st.query(0, n); 
    cout<<M.M[1][1]<<'\n';
    while(q--) {
        int x; char c; cin>>x>>c;
        x--;
        st.set(x, c);
        Matrix M = st.query(0, n); 
        cout<<M.M[1][1]<<'\n';
        // cout<<(st.query(0, n) * dp)[1]<<'\n';
    }

    return 0;
}