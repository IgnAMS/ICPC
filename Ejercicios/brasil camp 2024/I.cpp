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

int n;
int DP[100005][202][2];
int Acc[100005][202][2];
ll A[100005];
ll MOD = 998244353;
// b = 1 <-> A[i] = k > A[i - 1] -> A[i + 1] >= k
// b = 0 <-> A[i] = k <= A[i - 1] -> A[i + 1] es irrestricto

int dp(int i, int k, int b) {
    if(i == n - 1 and b == 1) {
        // A[n - 1] > A[n - 2] -> deberia dar 0 
        return 0;
    }
    if(A[i] != -1 and k != A[i]) return 0;
    if(i == n - 1) return 1;
    

    if(DP[i][k][b] != -1) return DP[i][k][b];

    DP[i][k][b] = 0;
    if(b) {
        // A[i] = k > A[i - 1] -> A[i + 1] >= k = A[i]
        DP[i][k][b] += dp(i + 1, k, 0);
        if(DP[i][k][b] >= MOD) DP[i][k][b] -= MOD;

        repx(j, k + 1, 201) {
            DP[i][k][b] += dp(i + 1, j, 1);
            if(DP[i][k][b] >= MOD) DP[i][k][b] -= MOD;
        }
    }
    else {
        // A[i] = k <= A[i - 1] -> A[i + 1] es irrestricto
        for(int j = 1; j <= k; j++) {
            DP[i][k][b] += dp(i + 1, j, 0);
            if(DP[i][k][b] >= MOD) DP[i][k][b] -= MOD;
        }
        repx(j, k + 1, 201) {
            DP[i][k][b] += dp(i + 1, j, 1);
            if(DP[i][k][b] >= MOD) DP[i][k][b] -= MOD;
        }
    }
    
    return DP[i][k][b];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i, n) cin>>A[i];
    rep(i, n + 2) rep(k, 202) rep(b, 2) Acc[i][k][b] = 0;
    
    
    // (10^5 * 200 * 2) * 200 = 
    for(int i = n - 1; i >= 0; i--) {
        repx(k, 1, 201) rep(b, 2) {
            if(i == n - 1 and b == 1) {
                // A[n - 1] > A[n - 2] -> deberia dar 0 
                DP[i][k][b] = 0;
                Acc[i][k][b] = Acc[i][k - 1][b] + DP[i][k][b];
                if(Acc[i][k][b] >= MOD) Acc[i][k][b] -= MOD;
                continue;
            }
            if(A[i] != -1 and k != A[i]) {
                DP[i][k][b] = 0;
                Acc[i][k][b] = Acc[i][k - 1][b] + DP[i][k][b];
                if(Acc[i][k][b] >= MOD) Acc[i][k][b] -= MOD;
                
                continue;
            }
            if(i == n - 1) {
                DP[i][k][b] = 1;
                Acc[i][k][b] = Acc[i][k - 1][b] + DP[i][k][b];
                if(Acc[i][k][b] >= MOD) Acc[i][k][b] -= MOD;
                continue;
            }

            DP[i][k][b] = 0;
            if(b) {
                // A[i] = k > A[i - 1] = k -> A[i + 1] >= k = A[i]
                DP[i][k][b] += DP[i + 1][k][0];
                if(DP[i][k][b] >= MOD) DP[i][k][b] -= MOD;
                
                // DP[i][k][b] += Acc[i + 1][k + 1...200][1]
                DP[i][k][b] += (Acc[i + 1][200][1] - Acc[i + 1][k][1]);
                if(DP[i][k][b] < 0) DP[i][k][b] += MOD;
                if(DP[i][k][b] >= MOD) DP[i][k][b] -= MOD;
            }
            else {
                // A[i] = k <= A[i - 1] -> A[i + 1] es irrestricto

                // DP[i][k][b] += Acc[i + 1][1...k][0] 
                DP[i][k][b] += (Acc[i + 1][k][0] - Acc[i + 1][0][0]);
                if(DP[i][k][b] < 0) DP[i][k][b] += MOD;
                if(DP[i][k][b] >= MOD) DP[i][k][b] -= MOD;

                // DP[i][k][b] += Acc[i + 1][k + 1...200][1] 
                DP[i][k][b] += (Acc[i + 1][200][1] - Acc[i + 1][k][1]);
                if(DP[i][k][b] < 0) DP[i][k][b] += MOD;
                if(DP[i][k][b] >= MOD) DP[i][k][b] -= MOD;
            }

            Acc[i][k][b] = Acc[i][k - 1][b] + DP[i][k][b];
            if(Acc[i][k][b] >= MOD) Acc[i][k][b] -= MOD;
        }
    }

    int ans = 0;
    repx(k, 1, 201) {
        ans += DP[0][k][1];
        if(ans >= MOD) ans -= MOD;
    }
    cout<<ans<<'\n';


    return 0;
}