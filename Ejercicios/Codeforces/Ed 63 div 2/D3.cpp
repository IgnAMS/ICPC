#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

ll DP[300000 + 5][2][2][2];
ll n, x;
vi A;

// i: posicion, j si empieza a sumar, k si empieza a multiplicar, h si ya multiplico
ll dp(ll i, ll j, ll k, ll h) {
    if(i == n + 1) return 0;
    if(DP[i][j][k][h] != -1e17) return DP[i][j][k][h];
    if(!j) {
        DP[i][j][k][h] = max({
            DP[i][j][k][h],
            dp(i + 1, 0, 0, 0), // nada
            dp(i + 1, 1, 0, 0), // empieza a sumar en la proxima
            dp(i + 1, 1, 1, 0),
        });
    } 
    if(j and !k and !h) {
        DP[i][j][k][h] = max({
            DP[i][j][k][h], 
            dp(i + 1, 1, 0, 0) + A[i], 
            dp(i + 1, 1, 1, 0) + A[i]
        });
    }
    if(k) DP[i][j][k][h] = max({
        DP[i][j][k][h], 
        dp(i + 1, 1, 1, 0) + A[i] * x,
        dp(i + 1, 1, 0, 1) + A[i] * x 
    });
    if(h) {
        DP[i][j][k][h] = max({
            DP[i][j][k][h],
            dp(i + 1, 1, 0, 1) + A[i],
            0LL
        });
    }
    // cerr<<i<<' '<<j<<' '<<k<<' '<<h<<' '<<DP[i][j][k][h]<<'\n';
    
    return DP[i][j][k][h];
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>x;
    A.resize(n + 1, 0); 
    rep(i, n) cin>>A[i + 1];
    rep(i, n + 3) rep(j, 2) rep(k, 2) rep(h, 2) DP[i][j][k][h] = -100000000000000000;
    cout<<dp(0, 0, 0, 0)<<'\n';


    return 0;
}