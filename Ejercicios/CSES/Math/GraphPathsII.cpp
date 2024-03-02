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
    vector<vl> C(n, vl(m, 1000000000000000001LL));
    rep(i, n) rep(j, m) {
        // cout<<"calculo las posibilidades para "<<i<<' '<<j<<'\n';
        rep(k, n2) {
            C[i][j] = min(C[i][j], A[i][k] + B[k][j]);
            // cout<<A[i][k] + B[k][j]<<' ';
        }
        // cout<<C[i][j]<<'\n';
        // cout<<"\n\n";
    }
    return C;
}

vector<vl> binpow(vector<vl> A, ll b) {
    vector<vl> res = A; b--;
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
    vector<vl> M(n, vl(n, 1000000000000000001LL));
    rep(i, m) {
        ll a, b, w; cin>>a>>b>>w; a--, b--;
        M[a][b] = min(M[a][b], w);
    }
    ll ans = binpow(M, k)[0][n - 1];
    if(ans == 1000000000000000001LL) cout<<"-1\n";
    else cout<<ans<<'\n';

    return 0;
}