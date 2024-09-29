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

const ll MOD = 1e9;
int n, m, k; 

vl FFT(vl& a, vl& b) {
    vl res(k + 1, 0);
    rep(i, k + 1) rep(j, i + 1) {
        res[i] += (a[j] * b[i - j]) % MOD;
        res[i] %= MOD;
    }
    return res;

}

vector<vector<vl>> MatrixMul(vector<vector<vl>>& A, vector<vector<vl>>& B) {
    vector<vector<vl>> res(10, vector<vl>(10, vl(k + 1, 0)));
    rep(a, 10) rep(b, 10) {
        rep(c, 10) { 
            // res[a][b] += A[a][c] * B[c][b];
            vl X = FFT(A[a][c], B[c][b]); 
            rep(l, k + 1) {
                res[a][b][l] += X[l];
                res[a][b][l] %= MOD;
            }
        }
    }
    return res;
}
 

vector<vector<vl>> binpow(vector<vector<vl>> &A, ll b) {
    vector<vector<vl>> res(10, vector<vl>(10, vl(k + 1, 0)));
    rep(i, 10) res[i][i][0] = 1;
    while(b) {
        if(b & 1) res = MatrixMul(A, res);
        A = MatrixMul(A, A);
        b >>= 1;
    }
    return res;
}

vector<vl> Mul(vector<vector<vl>>& A, vector<vl>& x) {
    vector<vl> ans(A.size(), vl(k + 1, 0));
    rep(i, A.size()) {
        rep(j, A.size()) {
            // ans[i] += A[i][j] * x[j]
            vl X = FFT(A[i][j], x[j]);
            rep(l, k + 1) {
                ans[i][l] += X[l];
                ans[i][l] %= MOD; 
            }
        }
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    ll D[m], P[m];
    rep(i, m) cin>>D[i]>>P[i];
    
    // stores the answers between dp[0,...,9][0,...K]
    vector<vector<vl>> Transition(10, vector<vl>(10, vl(k + 1, 0)));
    rep(i, m) {
        Transition[0][D[i] - 1][P[i]]++;
    }
    // Shifteo en k + 1 todos los elementos
    rep(a, 9) {
        Transition[a+1][a][0] = 1;
    }

    Transition = binpow(Transition, n - 1);

    // rep(i, 10) {
    //     rep(j, 10) {
    //         cout<<"transicion de "<<i<<' '<<j<<'\n';
    //         rep(a, k + 1) cout<<Transition[i][j][a]<<' '; cout<<'\n';
    //     }
    //     cout<<'\n';
    // }

    vector<vl> dp(10, vl(k + 1, 0));
    dp[0][0] = 1;
    dp = Mul(Transition, dp);

    
    ll ans = 0;
    // rep(i, 10) {
    //     cout<<"fila "<<n - i<<":\n";
    //     rep(j, k + 1) cout<<dp[i][j]<<' '; cout<<'\n';
    // }
    rep(i, k + 1) ans += dp[0][i];
    ans %= MOD;
    cout<<ans<<'\n';
    
    return 0;
}