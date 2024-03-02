#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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
 
const ll mod = 1e9+7;
vector<vl> Mul(vector<vl> A, vector<vl> B) {
    int n = A.size(), m = B[0].size();
    int n2 = B.size();
    vector<vl> C(n, vl(m, 0));
    rep(i, n) rep(j, m) {
        rep(k, n2) C[i][j] = (C[i][j] + A[i][k] * B[k][j] % mod) % mod;
    }
    return C;
}
 
vector<vl> binpow(vector<vl> A, ll b) {
    vector<vl> res(A.size(), vl(A.size(), 0));
    rep(i, A.size()) res[i][i] = 1;
    while(b) {
        if(b & 1) res = Mul(res, A);
        A = Mul(A, A);
        b >>= 1;
    }
    return res;
}
 
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin>>n>>m>>k;
    vector<vl> M(n, vl(n, 0));
    rep(i, m) {
        ll a, b; cin>>a>>b; a--, b--;
        M[a][b] += 1;
    }
    cout<<binpow(M, k)[0][n - 1]<<'\n';
 
    return 0;
}