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


const int mxN = 1e3;
ll A[mxN];
ll DP[1000005];
ll cont = 0;



// 10^6 * Log2()
ll binpow(vl A, ll b) {
    vl res;
    while(b) {
        res = FFT(res, A);
        A = FFT(A, A);
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    rep(i, n) cin>>A[i];
    
    dfs(n - 1, k, 0);
    rep(i, 1000005) if(DP[i] != 0) cout<<i<<' ';
    cout<<'\n';
    
    // tengo a lo mas 10^6 numeros y quiero ver si lo puedo formar con los numeros que tengo
    // para eso puedo hacer un dfs tipo puedo formar el numero x con k elementos?
    // DP[10^6][10^3] que claramente no cabe en tamaño 
    // DP[10^6] que es si puedo formar el numero k
    rep(i, k) {
        rep(w, 1000005) {
            
        }
    } 
    

    // cout<<n * n * (1<<(2*k))<<'\n';
    // cout<<cont<<'\n';


    return 0;
}