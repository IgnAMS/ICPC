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


ll Dig[12];
ll DP[12][2];
ll Digits;
ll Pot10[12];

const ll INF = 1e10 + 5;

ll dp(ll i, ll b) {
    if(i == -1) return 0;
    if(DP[i][b] != -1) return DP[i][b];

    DP[i][b] = INF;
    if(b == 0) {
        if(Digits & (1<<Dig[i])) DP[i][b] = min(DP[i][b], Dig[i] * Pot10[i] + dp(i - 1, 0));
        repx(d, Dig[i] + 1, 10) if(Digits & (1<<d)) DP[i][b] = min(DP[i][b], d * Pot10[i] + dp(i - 1, 1));
    }
    if(b == 1) {
        rep(d, 10) if(Digits & (1<<d)) DP[i][b] = min(DP[i][b], d * Pot10[i] + dp(i - 1, b));
    }
    return DP[i][b];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    Pot10[0] = 1;
    repx(i, 1, 12) Pot10[i] = Pot10[i - 1] * 10;
    // vector<vl> Comb[11];
    // rep(mask, (1<<10)) {
    //     vl X;
    //     rep(d, 10) if(mask & (1<<d)) X.pb(d);        
    //     Comb[X.size()].pb(X);
    // }
    


    while(t--) {
        ll n, k; cin>>n>>k;
        ll cont = 0, x = n;
        rep(i, 12) Dig[i] = 0;
        while(x != 0) {
            Dig[cont] = x % 10;
            x /= 10; 
            cont++;
        }
        ll ans = INF;
        rep(mask, (1<<10)) { // 10^3
            ll digitos = 0;
            rep(i, 10) if(mask & (1<<i)) digitos++; // 10^1
            if(digitos != k) continue;

            // cout<<"estoy con el multiset:\n";
            // rep(i, 10) if(mask & (1<<i)) cout<<i<<' '; cout<<'\n';

            rep(i, cont + 1) rep(b, 2) DP[i][b] = -1; // 10^1
            Digits = mask;
            // if(mask & (1<<1) and mask & (1<<8)) cout<<dp(cont - 1, 0)<<' '<<dp(cont, 0)<<'\n';
            ans = min({ans, dp(cont, 0), dp(cont - 1, 0)});
        }
        cout<<ans<<'\n';
    }


    return 0;
}