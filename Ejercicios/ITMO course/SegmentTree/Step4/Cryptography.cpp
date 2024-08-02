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

#define _CRT_DISABLE_PERFCRIT_LOCKS
#define pb push_back
// g++ -std=c++17 Cryptography.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

ll MOD;
vector<vl> Mul(vector<vl> &A, vector<vl> &B) {
    vector<vl> R(2, vl(2, 0));
    rep(i, 2) rep(j, 2) {
        rep(k, 2) {
            R[i][j] += ((A[i][k] % MOD) * (B[k][j] % MOD)) % MOD;
            R[i][j] %= MOD;
        }
    }

    // R[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0] + MOD * MOD) % MOD;
    // R[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1] + MOD * MOD) % MOD;
    // R[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0] + MOD * MOD) % MOD;
    // R[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1] + MOD * MOD) % MOD;
    return R;
}

const vector<vl> Ident = {{1, 0}, {0, 1}};
// struct Mat {
//     vector<vl> A;
//     Mat(): A(Ident) {}
//     Mat(vector<vl>& B): A(B) {}
//     Mat(Mat& B, Mat& C): A(Mul(B.A, C.A)) {}
// };


struct ST {
    vector<vector<vl>> t; int n;
    ST(vector<vector<vl>> &arr, int N) : n(N), t(N * 2) {
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i) t[i] = Mul(t[i << 1], t[i << 1 | 1]);
    }
    vector<vl> query(int l, int r) {
        vector<vl> ansl = Ident, ansr = Ident;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) ansl = Mul(ansl, t[l++]);
            if(r & 1) ansr = Mul(t[--r], ansr);
        }
        return Mul(ansl, ansr);
    }
};


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    // MOD = read_int(), n = read_int(), m = read_int();
    // scanf("%lld %d %d", &MOD, &n, &m);
    cin>>MOD>>n>>m;

    vector<vector<vl>> A(n, vector<vl>(2, vl(2)));
    
    rep(i, n) {
        rep(j, 2) rep(k, 2) {
            // A[i].A[j][k] = read_int();
            // scanf("%lld", &A[i][j][k]);
            cin>>A[i][j][k];
            A[i][j][k] += MOD * MOD;
            A[i][j][k] %= MOD; 
        }
    }
    
    ST st(A, n);
    vector<string> Ans;
    rep(_, m) {
        int l, r; 
        // l = read_int(), r = read_int();
        // scanf("%d %d", &l, &r);
        cin >> l >> r; 
        l--;
        vector<vl> X = st.query(l, r);
        rep(i, 2) {
            rep(j, 2) {
                // printf("%lld ", X[i][j]);
                cout<<X[i][j]<<' ';
            }
            cout<<'\n';
            // printf("\n");
        }
        cout<<'\n';
        //printf("\n");
    }

    return 0;
}