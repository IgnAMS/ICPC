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

const ll MOD = 1e9+7, MOD2 = MOD * MOD;

uint64_t prod_long_double(const ll x, const ll y) {
	ll c = x * y / MOD;
	ll ans = x * y - c * MOD;
	return ans;
}

vector<vl> MatrixMul(const vector<vl> &A, const vector<vl>& B) {
    int n = 2;
    vector<vl> res(n, vl(n, 0));
    ll k = 0;
    res[0][0] = prod_long_double(A[0][0], B[0][0]) + prod_long_double(A[0][1], B[1][0]);
    if(res[0][0] >= MOD) res[0][0] -= MOD;

    res[0][1] = prod_long_double(A[0][0], B[0][1]) + prod_long_double(A[0][1], B[1][1]);
    if(res[0][1] >= MOD) res[0][1] -= MOD;
    
    res[1][0] = prod_long_double(A[1][0], B[0][0]) + prod_long_double(A[1][1], B[1][0]);
    if(res[1][0] >= MOD) res[1][0] -= MOD;
 
    res[1][1] = prod_long_double(A[1][0], B[0][1]) + prod_long_double(A[1][1], B[1][1]);
    if(res[1][1] >= MOD) res[1][1] -= MOD;
    
    return res;
}

// vl Mul(vector<vl> &A, vl& x) {
//     int n = 2;
//     vl res(n);
//     rep(i, n) rep(j, n) res[i] += A[i][j] * x[j];
//     return res;
// }

vector<vl> Id = {{1, 0}, {0, 1}};
vector<vl> F = {{1, 1}, {1, 0}};
vector<vl> Rock = {{0, 0}, {1, 0}};
vector<vl> Pot[33];


unordered_map<ll, vector<vl>> mem;
vector<vl> binpow(ll b) {
    if(mem.count(b)) return mem[b];
    int n = 2;
    vector<vl> res = Id;
    ll ogb = b;
    int i = 0;
    while(b) {
        if(b & 1) res = MatrixMul(res, Pot[i]);
        i++;
        b >>= 1;
    }
    mem[ogb] = res;
    return res;
}

// Complexity O(2^3 * m * log2(10^9)) ~ O(8 * m * 30) ~ O(240 * 10^6) ~ O(2 * 10^8)

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    mem.reserve(1000000);
    vl A(m); rep(i, m) cin>>A[i];
    sort(A.begin(), A.end());
    
    Pot[0] = F;
    repx(i, 1, 33) Pot[i] = MatrixMul(Pot[i-1], Pot[i-1]);

    ll last = 0;
    vector<vl> curr = Id;
    rep(i, m) {
        // cout<<"multiplico la matriz de fib elevado a "<<max(A[i] - last - 1, 0LL)<<'\n';
        vector<vl> pot = binpow(max(A[i] - last - 1, 0LL));
        curr = MatrixMul(pot, curr);
        // cout<<"multiplico por una roca\n";
        curr = MatrixMul(Rock, curr);
        last = A[i];
    }
    if(last != n) {
        // cout<<"multiplico la matriz de fib elevado a "<<max(n - last, 0LL)<<'\n';
        vector<vl> pot = binpow(max(n - last, 0LL));
        curr = MatrixMul(pot, curr);
    }
    // vl dp(2, 0); dp[0] = 1;
    // dp = Mul(curr, dp);
    // cout<<dp[0]<<'\n';
    cout<<curr[0][0]<<'\n';
    return 0;
}