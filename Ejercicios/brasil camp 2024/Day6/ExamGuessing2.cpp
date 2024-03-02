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

int n, k;
const int mxN = 5005;
vector<db> P;
db DP[mxN][2 * mxN];


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    P.resize(n);
    rep(i, n) cin>>P[i];
    sort(P.begin(), P.end());

    // n es la mitad
    rep(i, mxN) rep(x, 2 * mxN) DP[i][x] = 0; 
    repx(x, n + k, 2 * mxN) DP[n][x] = 1;

    db ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        rep(x, 2 * mxN) if(x - 1 >= 0 and x + 1 < 2 * mxN) {
            DP[i][x] = DP[i + 1][x + 1] * P[i] + DP[i + 1][x - 1] * (1. - P[i]);
            // if(x == n) cout<<i<<' '<<x<<' '<<DP[i][x]<<'\n';
            if(x == n) ans = max(ans, DP[i][x]);
        }
    }
    cout<<ans<<'\n';




    return 0;
}