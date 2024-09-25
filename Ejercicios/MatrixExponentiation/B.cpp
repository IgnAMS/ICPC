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

// DP[i + 1][c][mood] = sum_{c2 = 'a',...,'z'} DP[i][c2][func(mood, c2)]
// DP[0][c][1] = 1 // Parte como happy :)
// func(mood, c2) = (c2 == 's' or c2 == 'd')? 0: (c2 == 'H ? 1: (c2 is vowel? !mood: mood));
// DP[i + 1][c * 2 + mood] = sum_{c2='a',...,'z'} DP[i][c2 * 2 + func(mood, c2)]

const ll MOD = 1e9+7;
vector<vl> MatrixMul(vector<vl>& A, vector<vl>& B) {
    vector<vl> res(A.size(), vl(A.size(), 0));
    rep(i, 2) rep(j, 2) {
        rep(k, 2) {
            res[i][j] += A[i][k] * B[k][j] % MOD;
            res[i][j] %= MOD;
        }
    } 
    return res;
}


vector<vl> binpow(vector<vl>& A, ll b) {
    vector<vl> res(2, vl(2, 0));
    rep(i, 2) res[i][i] = 1;
    while(b) {
        if(b & 1) res = MatrixMul(A, res);
        A = MatrixMul(A, A);
        b >>= 1;
    }
    return res;
}

vl Mul(vector<vl>& A, vl& x) {
    vl ans(2, 0);
    rep(i, 2) {
        rep(j, 2) {
            ans[i] += A[i][j] * x[j] % MOD;
            ans[i] %= MOD;
        }
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    vector<vl> Transition(2, vl(2, 0));
    Transition[0][0] = 18 + 2;
    Transition[1][1] = 18 + 1;
    Transition[0][1] = 5 + 2;
    Transition[1][0] = 5 + 1;
    
    Transition = binpow(Transition, n);
    vl dp(2, 0);
    dp[1] = 1;
    dp = Mul(Transition, dp);
    cout<<dp[1]<<'\n';
    

    return 0;
}