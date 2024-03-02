#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<ll> vl;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)

const int mxN = 1e6+3;
const int mxH = 5e3+5;
ll mod = 1e9+7;

ll DP[mxH], F[mxN], A[mxH];

ll dp(int k) {
    if(DP[k] != -1) return DP[k];
    if(k == 0) return F[A[k]];
    ll aux = 0;
    repx(j, 1, k + 1) {
        aux = (aux + F[A[k] - A[j - 1]] * dp(j - 1) % mod) % mod;
    }
    return DP[k] = (F[A[k]] - aux + mod) % mod;
}


int main() {
    int n, k; cin>>n>>k;
    rep(i, k) cin>>A[i];
    repx(i, 1, k) A[i] += A[i - 1]; 
    A[k] = n;

    F[0] = 1; 
    repx(i, 1, mxN) F[i] = F[i - 1] * ll(i) % mod;
    
    memset(DP, -1, sizeof(DP));
    cout<<dp(k)<<'\n';


    return 0;
}