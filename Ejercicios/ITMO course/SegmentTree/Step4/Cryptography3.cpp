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

ll MOD;
void Mul(ll A[2][2], ll B[2][2], ll R[2][2]) {
    ll temp[2][2] = {0};
    rep(i, 2) rep(j, 2) {
        temp[i][j] = 0;
        rep(k, 2) {
            temp[i][j] = (temp[i][j] + A[i][k] * B[k][j] % MOD) % MOD;
        }
    }
    rep(i, 2) rep(j, 2) {
        R[i][j] = temp[i][j];
    }
}

const ll Ident[2][2] = {{1, 0}, {0, 1}};

const int mxN = 2e5+5;
struct ST {
    ll t[2 * mxN][2][2];
    int n;
    ST(ll arr[][2][2], int N) : n(N) {
        rep(i, n) {
            rep(j, 2) rep(k, 2) {
                t[n + i][j][k] = arr[i][j][k];
            }
        }
        // copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i) Mul(t[i << 1], t[i << 1 | 1], t[i]);
    }
    void query(int l, int r, ll res[2][2]) {
        ll ansl[2][2] = {{1, 0}, {0, 1}};
        ll ansr[2][2] = {{1, 0}, {0, 1}};
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                ll temp[2][2];
                Mul(ansl, t[l++], temp);
                rep(i, 2) rep(j, 2) ansl[i][j] = temp[i][j];
            }
            if(r & 1) {
                ll temp[2][2];
                Mul(t[--r], ansr, temp);
                rep(i, 2) rep(j, 2) ansr[i][j] = temp[i][j];
            }
        }
        Mul(ansl, ansr, res);
    }

};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    // Input the values of MOD, n, and m
    cin >> MOD >> n >> m;

    ll arr[mxN][2][2];
    rep(i, n) {
        rep(j, 2) rep(k, 2) {
            cin >> arr[i][j][k];
            arr[i][j][k] = (arr[i][j][k] % MOD + MOD) % MOD;
        }
    }
    
    ST st(arr, n);
    rep(_, m) {
        int l, r;
        cin >> l >> r;
        l--;  // Convert to 0-based index
        ll res[2][2];
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