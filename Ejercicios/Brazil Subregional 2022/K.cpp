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

vector<vl> MatrixMul(vector<vl>& A, vector<vl>& B) {
    int n = A.size();
    vector<vl> res(n, vl(n, 0));
    rep(i, n) rep(j, n) {
        rep(k, n) { 
            res[i][j] += (A[i][k] * B[k][j]); 
            res[i][j] %= MOD;
        }
    }
    return res;
}

vector<vl> binpow(vector<vl> &A, ll b) {
    int n = A.size();
    vector<vl> res(n, vl(n, 0));
    rep(i, n) res[i][i] = 1;
    while(b) {
        if(b & 1) res = MatrixMul(res, A);
        A = MatrixMul(A, A);
        b >>= 1;
    }
    return res;
}

vl Mul(vector<vl> &A, vl &x) {
    int n = A.size();
    vl ans(n, 0);
    rep(i, n) {
        rep(j, n) { 
            ans[i] += A[i][j] * x[j]; 
            ans[i] %= MOD;
        }
    }
    return ans;
}

// O(4000^3 * log2(10^8)) ~ O(6.4 * 10^11 * 30) ~ O(1.9 * 10^12) x.x

int n, m, k; 
ll ind(ll i, ll j) { return i * (k + 1) + j; }

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    ll D[m], P[m];
    rep(i, m) cin>>D[i]>>P[i];
    
    // stores the answers between dp[0,...,9][0,...K]
    vector<vl> Transition((k + 1) * 10, vl((k + 1) * 10, 0));
    // Creo DP[k+1] a partir de los anteriores
    rep(b, k + 1) {
        rep(i, m) if(P[i] <= b) {
            Transition[ind(0, b)][ind(D[i] - 1, b - P[i])]++;
        }
    }
    // Shifteo en k + 1 todos los elementos
    rep(a, 9) rep(b, k + 1) {
        Transition[ind(a + 1, b)][ind(a, b)] = 1;
    }

    // Elevo la matriz
    Transition = binpow(Transition, n - 1);

    vl dp((k + 1) * 10, 0);
    dp[ind(0, 0)] = 1;
    dp = Mul(Transition, dp);

    // rep(i, 10) {
    //     cout<<"fila "<<n - i<<":\n";
    //     rep(j, k + 1) cout<<dp[ind(i, j)]<<' '; cout<<'\n';
    //     cout<<'\n';
    // }
    
    ll ans = 0;
    rep(i, k + 1) ans += dp[ind(0, i)];
    ans %= MOD;

    cout<<ans<<'\n';
    
    return 0;
}