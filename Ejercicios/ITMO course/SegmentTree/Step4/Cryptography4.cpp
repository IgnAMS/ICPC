#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

ll MOD;

// Function to multiply two 2x2 matrices A and B under modulo MOD
void Mul(int A[2][2], int B[2][2], int R[2][2]) {
    rep(i, 2) rep(j, 2) {
        R[i][j] = 0;
        rep(k, 2) {
            R[i][j] = (1LL * R[i][j] + 1LL * A[i][k] * B[k][j] % MOD) % MOD;
        }
    }
}

const ll Ident[2][2] = {{1, 0}, {0, 1}};
const int mxN = 2e5 + 5;

struct ST {
    int t[2 * mxN][2][2];  // Segment tree array
    int n;

    void build(int N) {
        cerr<<"Hola\n";
        n = N;
        for (int i = n - 1; i > 0; --i) {
            Mul(t[i << 1], t[i << 1 | 1], t[i]);
        }
    }

    // Query to get product of matrices from index l to r-1
    void query(int l, int r, int res[2][2]) {
        int ansl[2][2] = {{1, 0}, {0, 1}};
        int ansr[2][2] = {{1, 0}, {0, 1}};
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                int temp[2][2];
                Mul(ansl, t[l++], temp);
                rep(i, 2) rep(j, 2) ansl[i][j] = temp[i][j];
            }
            if (r & 1) {
                int temp[2][2];
                Mul(t[--r], ansr, temp);
                rep(i, 2) rep(j, 2) ansr[i][j] = temp[i][j];
            }
        }
        Mul(ansl, ansr, res);
    }
} st;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    // Input the values of MOD, n, and m
    cin >> MOD >> n >> m;

    int arr[n][2][2];
    rep(i, n) {
        rep(j, 2) rep(k, 2) {
            cin >> arr[i][j][k];
            st.t[n + i][j][k] = arr[i][j][k];
            arr[i][j][k] = (arr[i][j][k] % MOD + MOD) % MOD;
        }
    }
    st.build(n);
    
    rep(_, m) {
        int l, r;
        cin >> l >> r;
        l--;  // Convert to 0-based index
        int res[2][2];
        st.query(l, r, res);
        rep(i, 2) {
            rep(j, 2) {
                cout << res[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    
    return 0;
}
