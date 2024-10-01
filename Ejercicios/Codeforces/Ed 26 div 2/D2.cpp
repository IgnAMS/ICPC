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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    vl A(n); rep(i, n) cin>>A[i];
    vector<int> Dos(n, 0), Cinco(n, 0);
    ll tot5 = 0;
    rep(i, n) {
        while(A[i] % 2 == 0) {
            Dos[i]++;
            A[i] /= 2;
        }
        while(A[i] % 5 == 0) {
            Cinco[i]++;
            tot5++;
            A[i] /= 5;
        }
        // cout<<Cinco[i]<<'\n';
    }

    vector<vector<vector<int>>> DP(2, vector<vector<int>>(201, vector<int>(6005, -1e9)));
    DP[0][0][0] = 0;
    rep(i, n) {
        for(int j = 0; j < k; j++) {
            for(int cinco = 0; cinco < 6005 - Cinco[i]; cinco++) {
                DP[1][j][cinco] = max(DP[1][j][cinco], DP[0][j][cinco]);
                DP[1][j + 1][cinco + Cinco[i]] = max(DP[1][j + 1][cinco + Cinco[i]], DP[0][j][cinco] + Dos[i]);
                // cerr<<i<<' '<<j<<' '<<cinco<<' '<<DP[1][j + 1][cinco + Cinco[i]]<<' '<<DP[0][j][cinco]<<'\n';
            }
        }
        // rep(j, k + 1) rep(cinco, 6005) DP[1][j][cinco] = max(DP[1][j][cinco], DP[0][j][cinco]);

        rep(j, k + 1) rep(cinco, 6005) {
            DP[0][j][cinco] = DP[1][j][cinco];
            // DP[1][j][cinco] = 0;
        }
    }
    int ans = 0;
    rep(cinco, tot5 + 1) {
        // cout<<cinco<<' '<<DP[0][k][cinco]<<'\n';
        ans = max(ans, min(cinco, DP[0][k][cinco]));
    }
    cout<<ans<<'\n';


    return 0;
}