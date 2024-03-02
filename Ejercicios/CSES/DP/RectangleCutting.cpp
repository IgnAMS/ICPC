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

ll DP[505][505];

ll dp(ll a, ll b) {
    if(a == b) return 0;
    if(DP[a][b] != -1) return DP[a][b];
    
    DP[a][b] = 1e10;
    
    repx(i, 1, max(a, b)) {
        if(i < a) {
            DP[a][b] = min({
                DP[a][b], 
                dp(a - i, b) + dp(i, b) + 1
            });
        }
        if(i < b) {
            DP[a][b] = min({
                DP[a][b], 
                dp(a, b - i) + dp(a, i) + 1
            });
        }
        
    }
    
    return DP[a][b];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b; cin>>a>>b;
    
    rep(i, 501) rep(j, 501) DP[i][j] = -1;

    rep(i, 501) rep(j, 501) {
        if(i == j) {
            DP[i][j] = 0;
            continue;
        }

        DP[i][j] = 1e10;
        repx(k, 1, max(i, j)) {
            if(k < i) {
                DP[i][j] = min(
                    DP[i][j],
                    DP[i - k][j] + DP[k][j] + 1
                );
            }
            if(k < j) {
                DP[i][j] = min(
                    DP[i][j],
                    DP[i][j - k] + DP[i][k] + 1
                );
            }
        }
    }


    cout<<DP[a][b]<<'\n';



    return 0;
}