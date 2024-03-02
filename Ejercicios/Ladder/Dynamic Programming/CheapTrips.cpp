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

const ll mxN = 1e4+5;

ll DP[mxN][122][7];
ll C[mxN], D[mxN];
int n; 

vl Div = {1, 2, 4, 4, 4, 4, 4, 4};

ll dp(ll i, ll t, ll q) {
    if(i == n) return 0;
    if(DP[i][t][q] != -1) return DP[i][t][q];

    if(t + D[i] < 120) {
        if(q < 6) {
            DP[i][t][q] = min({
                dp(i + 1, t + D[i], q + 1) + C[i] / Div[q],
                dp(i + 1, D[i], 1) + C[i],
                dp(i + 1, 0, 0) + C[i] / Div[q]
            });
        }
        else {
            DP[i][t][q] = min({
                dp(i + 1, D[i], 1) + C[i],
                dp(i + 1, 0, 0) + C[i]
            });
        }
    }
    else {
        if(D[i] >= 120) {
            if(q < 6) DP[i][t][q] = dp(i + 1, 0, 0) + C[i] / Div[q];
            else DP[i][t][q] = dp(i + 1, 0, 0) + C[i];
        }
        else {
            if(q < 6) {
                DP[i][t][q] = min({
                    dp(i + 1, D[i], 1) + C[i],
                    dp(i + 1, 0, 0) + C[i] / Div[q]
                });
            }
            else {
                if(q < 6) DP[i][t][q] = dp(i + 1, 0, 0) + C[i] / Div[q];
                else DP[i][t][q] = dp(i + 1, D[i], 1) + C[i];
            }
        }
    }
    return DP[i][t][q];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i, n) cin>>D[i]>>C[i];
    rep(i, n) C[i] *= 4;

    rep(i, mxN) rep(t, 122) rep(q, 7) DP[i][t][q] = -1;

    cout<<setprecision(2)<<fixed<<dp(0, 0, 0) / 4.<<'\n';

    return 0;
}