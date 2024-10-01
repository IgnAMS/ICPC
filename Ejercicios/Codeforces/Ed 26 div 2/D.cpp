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
// g++ -std=c++11 D.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt


vector<short> Dos(201), Cinco(201);

// vector<vector<vector<short>>> DP2(201, vector<vector<short>>(201, vector<short>(6005)));
// vector<vector<vector<short>>> DP5(201, vector<vector<short>>(201, vector<short>(6005)));
// short dp5(short i, short k, short x);
// 
// short dp2(short i, short k, short x) {
//     if(k == 0) return 0;
//     if(i == -1) return 0;
//     if(DP2[i][k][x] != -1) return DP2[i][k][x];
// 
//     if(Cinco[i] >= x + Dos[i]) {
//         DP2[i][k][x] = max(dp2(i - 1, k, x), short(dp5(i - 1, k - 1, Cinco[i] - x - Dos[i]) + x + Dos[i]));
//     }
//     else {
//         DP2[i][k][x] = max(dp2(i - 1, k, x), short(dp2(i - 1, k - 1, min(6000, x + Dos[i] - Cinco[i])) + Cinco[i]));
//     }
//     return DP2[i][k][x];
// }
// 
// short dp5(short i, short k, short x) {
//     if(k == 0) return 0;
//     if(i == -1) return 0;
//     if(DP5[i][k][x] != -1) return DP5[i][k][x];
// 
//     if(Dos[i] > x + Cinco[i]) {
//         DP5[i][k][x] = max(dp5(i - 1, k, x), short(dp2(i - 1, k - 1, Dos[i] - x - Cinco[i]) + x + Cinco[i]));
//     }
//     else {
//         // Dos[i] <= x + Cinco[i]
//         DP5[i][k][x] = max(dp5(i - 1, k, x), short(dp5(i - 1, k - 1, x + Cinco[i] - Dos[i]) + Dos[i]));
//     }
//     return DP5[i][k][x];
// }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);    
    int n, k; cin>>n>>k;
    ll A[n]; 
    rep(i, n) cin>>A[i];
    short tot2 = 0, tot5 = 0;
    rep(i, n) {
        Dos[i] = 0;
        while(A[i] % 2 == 0) {
            Dos[i]++;
            A[i] /= 2;
            tot2++;
        }
        Cinco[i] = 0;
        while(A[i] % 5 == 0) {
            Cinco[i]++;
            A[i] /= 5;
            tot5++;
        }
    }
    // rep(i, n + 1) rep(j, n + 1) {
    //     rep(x, tot2 + 1) DP2[i][j][x] = -1;
    //     rep(x, tot5 + 1) DP5[i][j][x] = -1;
    // }
    // cout<<max(dp2(n - 1, k, 0), dp5(n - 1, k, 0))<<'\n';
    // cerr<<201 * 201 * (6005) * 2<<'\n';

    
    // DP2[k][dos]
    vector<vector<int>> DP2(205, vector<int>(12005, -1e9)), DP5(205, vector<int>(6005, -1e9));
    vector<vector<int>> DP2_copy(205, vector<int>(12005, -1e9)), DP5_copy(205, vector<int>(6005, -1e9));
    
    DP5[k][0] = 0;
    DP2[k][0] = 0;
    
    int ans = 0, acc2 = 0, acc5 = 0;

    rep(i, n) {
        rep(j, k + 1) {
            rep(l, tot2 + 1) DP2_copy[j][l] = DP2[j][l];
            rep(l, tot5 + 1) DP5_copy[j][l] = DP5[j][l];
        }

        for(int j = k; j >= 1; j--) {
            // Nota, si 'cinco' = 0 y 'dos' = 0 -> usar solo cinco
            for(int dos = 0; dos <= tot2 - Dos[i]; dos++) {
                if(Cinco[i] >= dos + Dos[i]) 
                    DP5[j - 1][Cinco[i] - dos - Dos[i]] = max(DP5[j - 1][Cinco[i] - dos - Dos[i]], DP2_copy[j][dos] + dos + Dos[i]);
                else 
                    DP2[j - 1][dos + Dos[i] - Cinco[i]] = max(DP2[j - 1][dos + Dos[i] - Cinco[i]], DP2_copy[j][dos] + Cinco[i]);
            }

            for(int cinco = 0; cinco <= tot5 - Cinco[i]; cinco++) {
                if(Dos[i] > cinco + Cinco[i]) 
                    DP2[j - 1][Dos[i] - Cinco[i] - cinco] = max(DP2[j - 1][Dos[i] - cinco - Cinco[i]], DP5_copy[j][cinco] + cinco + Cinco[i]);
                else 
                    DP5[j - 1][Cinco[i] + cinco - Dos[i]] = max(DP5[j - 1][Cinco[i] + cinco - Dos[i]], DP5_copy[j][cinco] + Dos[i]);
            }
        }
    }

    rep(j, k + 1) {
        rep(l, tot2 + 1) {
            ans = max(ans, DP2[j][l]);
            // if(DP2[j][l] == 4) cout<<"2: "<<j<<" "<<l<<'\n';
        }
        rep(l, tot5 + 1) {
            ans = max(ans, DP5[j][l]);
            // if(DP5[j][l] == 4) cout<<"5: "<<j<<" "<<l<<'\n';
        }
    }
    
    cout<<ans<<'\n';



    return 0;
}