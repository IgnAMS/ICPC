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

ll DP[300000 + 5][2][2];
ll n, x;
vi A;

// i: posicion, j si empieza a multiplicar, k si ya multiplico
ll dp(ll i, ll j, ll k) {
    if(i == n) return 0;
    if(DP[i][j][k] != -1e17) return DP[i][j][k];
    if(!j and !k) {
        DP[i][j][k] = max({
            DP[i][j][k],
            dp(i + 1, 0, 0) + A[i], // nada
            dp(i + 1, 1, 0) + A[i], // empieza a sumar en la proxima
        });
    } 
    if(j) {
        DP[i][j][k] = max({
            DP[i][j][k], 
            dp(i + 1, 1, 0) + A[i] * x, 
            dp(i + 1, 0, 1) + A[i] * x
        });
    }
    if(k) DP[i][j][k] = max({
        DP[i][j][k], 
        dp(i + 1, 0, 1) + A[i],
        0LL
    });
    // cerr<<i<<' '<<j<<' '<<k<<' '<<DP[i][j][k]<<'\n';
    
    return DP[i][j][k];
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>x;
    A.resize(n + 1, 0); 
    rep(i, n) cin>>A[i];
    rep(i, n + 3) rep(j, 2) rep(k, 2) DP[i][j][k] = -100000000000000000;
    
    ll ans = 0;
    rep(i, n) ans = max({ans, dp(i, 0, 0), dp(i, 1, 0)});
    cout<<ans<<'\n';


    return 0;
}