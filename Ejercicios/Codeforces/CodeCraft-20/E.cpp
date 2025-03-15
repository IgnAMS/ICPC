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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, p, k; 
    cin>>n>>p>>k;
    ll A[n]; 
    rep(i, n) cin>>A[i];
    ll S[n][p];
    rep(i, n) rep(j, p) cin>>S[i][j];

    vl Ind(n); rep(i, n) Ind[i] = i;
    sort(Ind.begin(), Ind.end(), [&](const ll a, const ll b){
        return A[a] > A[b];
    });


    ll DP[2][1<<p];
    rep(b, 2) rep(bm, 1<<p) DP[b][bm] = -1e16;
    DP[0][0] = 0;

    rep(i, n) {
        ll ind = Ind[i];
        rep(bm, 1<<p) {
            ll cnt = 0;
            rep(j, p) if(bm & (1<<j)) cnt++;
            ll last = i - cnt;
            if(last < 0) continue;

            if(last < k) DP[1][bm] = max(DP[1][bm], DP[0][bm] + A[ind]);
            else DP[1][bm] = max(DP[1][bm], DP[0][bm]);

            rep(j, p) if(((bm >> j) & 1) == 0) {
                DP[1][bm | (1<<j)] = max(
                    DP[1][bm | (1<<j)], 
                    DP[0][bm] + S[ind][j]
                );
            }
        }
        // rep(bm, 1<<p) cout<<DP[1][bm]<<' '; cout<<'\n';
        rep(bm, 1<<p) DP[0][bm] = DP[1][bm];
    }
    cout<<DP[0][(1<<p) - 1]<<'\n';

    return 0;
}