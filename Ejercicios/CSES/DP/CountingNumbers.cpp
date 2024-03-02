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


// no two adjacent digits are the same
// DP[i][d][1] = sum_{a < d} dp(i + 1, a, 0) + dp(i + 1, d, 1)
// DP[i][d][0] = sum_{a in [0, 9]} dp(i + 1, a, 0)

const ll mxN = 20;
ll DP[mxN][11][2][2];
int n;

ll A[mxN];

ll dp(ll i, ll d, ll b, ll z) {
    if(i == -1) return 1;
    if(DP[i][d][b][z] != -1) return DP[i][d][b][z];

    DP[i][d][b][z] = 0;
    
    // z significa que llevo puros 0's
    if(z) {
        DP[i][d][b][z] += dp(i - 1, 0, 0, 1);
        if(b) { 
            repx(a, 1, A[i]) DP[i][d][b][z] += dp(i - 1, a, 0, 0);
            if(A[i] != 0) DP[i][d][b][z] += dp(i - 1, A[i], b, 0);
        }
        else {
            repx(a, 1, 10) DP[i][d][b][z] += dp(i - 1, a, 0, 0);
        }
    }
    // el numero ya empezo
    else if(b) {
        rep(a, A[i]) if(a != d) DP[i][d][b][z] += dp(i - 1, a, 0, 0);
        if(A[i] != d) DP[i][d][b][z] += dp(i - 1, A[i], 1, 0);
    }
    else {
        rep(a, 10) if(a != d) DP[i][d][b][z] += dp(i - 1, a, 0, 0);
    }
    return DP[i][d][b][z];
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll a, b; cin>>a>>b;
    
    ll ind = 0;
    ll aux = a - 1;
    while(aux > 0) {
        A[ind] = aux % 10;
        aux /= 10;
        ind++;
    }
    rep(i, mxN) rep(d, 11) rep(b, 2) rep(z, 2) DP[i][d][b][z] = -1;

    ll L = (a? dp(ind - 1, 0, 1, 1): 0);

    ind = 0;
    aux = b;
    while(aux > 0) {
        A[ind] = aux % 10;
        aux /= 10;
        ind++;
    }
    rep(i, mxN) rep(d, 11) rep(b, 2) rep(z, 2) DP[i][d][b][z] = -1;

    ll R = dp(ind - 1, 0, 1, 1);

    // cout<<R<<' '<<L<<'\n';
    cout<<R - L<<'\n';


    return 0;
}