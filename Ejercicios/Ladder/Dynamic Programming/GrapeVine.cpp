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
 
// [a, b] -> max_{h} Exists i, j such that a <= A[i][j] and A[i + h][j + h] <= b
// for h in 1...n
//   for i in 1..n-h
//      for j in 1..n-h
//          if a <= A[i][j] and A[i + h][j + h] <= b
//              ans = max(ans, h)
//              DP[A[i][j]][A[i + h][j + h]] = max(DP[A[i][j]][A[i + h][j + h]], h)
// DP[a][b] = max(DP[a][b], DP[a + 1][b], DP[a][b - 1], DP[a + 1][b - 1]) 

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; 
    
    while(cin>>n>>m and n) {
        ll A[n][m];
        rep(i, n) rep(j, m) {
            cin>>A[i][j];
        }

        int q; cin>>q;
        while(q--) {
            int L, U; cin>>L>>U;
            int ans = 0;
            rep(i, n) {
                int l = 0, r = m-1;
                int cont = 0;
                while(l < r and cont++ < 10000) {
                    int m = (l + r) / 2;
                    if(A[i][m] >= L) r = m;
                    else l = m + 1;
                }
                if(A[i][l] < L) continue;
                // cout<<"parto la busqueda en "<<i<<' '<<l<<'\n';

                repx(j, l + ans, min(m, n + l - i)) {
                    if(A[i + j - l][j] <= U) ans = max(ans, j - l + 1);
                    else break;
                    // cout<<"nuevo maximo encontrado en ("<<i<<", "<<l<<"), ("<<i + (j - l)<<", "<<j<<") con valor "<<j - l + 1<<'\n';
                }
            }
            cout<<ans<<'\n';
        }
        cout<<"-\n";

    }
    


    
    int q; cin>>q;





    return 0;
}