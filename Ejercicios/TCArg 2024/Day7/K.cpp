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


ll win(ll s, ll e) {
    if(s == e) return 0;
    if(s > e) return 1;
    if(e & 1) {
        if(s & 1) return 0;
        // Caso contrario s es par, i + 1 es impar y hago que pierda el enemigo
        return 1;
    }
    // e es par
    if(e / 2 < s and s <= e) {
      // No puedo hacer la operacion de x2
      if(s & 1) return 1;
      return 0;  
    }
    if(e / 4 < s and s <= e / 2)  {
        // lo llevo a s par multiplicadolo por 2 a un estado de perdida del enemigo
        return 1;
    }
    // s <= e / 4 -> 
    return win(s, e / 4);
}

ll loose(ll s, ll e) {
    if(s > e) return 0;
    if(e < 2 * s) return 1;
    // s <= e / 2
    return win(s, e / 2);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll S[n], E[n]; rep(i, n) cin>>S[i]>>E[i];
    
    ll Win[n + 1][2], Loose[n + 1][2]; 
    // Win[i][0] = 1 if Lee can win independenlty i,...,n-1 and Lee start
    // Win[i][1] = 1 if Lee can win independenlty i,...,n-1 and Lee does not start  
    // rep(b, 2) Win[n][b] = Loose[n][b] = 1;
    Win[n][1] = 1, Win[n][0] = 0;
    Loose[n][0] = 1, Loose[n][1] = 0;
    for(int i = n - 1; i >= 0; i--) {
        Win[i][0] = 0;
        if(win(S[i], E[i])) Win[i][0] = Win[i][0] or Win[i + 1][1];
        if(loose(S[i], E[i])) Win[i][0] = Win[i][0] or Win[i + 1][0];

        Win[i][1] = 0;
        if(win(S[i] + 1, E[i]) and win(2 * S[i], E[i])) Win[i][1] = Win[i][1] or Win[i + 1][1];
        if(loose(S[i] + 1, E[i]) and loose(2 * S[i], E[i])) Win[i][1] = Win[i][1] or Win[i + 1][0];

        Loose[i][0] = 0;
        if(loose(S[i], E[i])) Loose[i][0] = Loose[i][0] or Loose[i + 1][0];
        if(win(S[i], E[i])) Loose[i][0] = Loose[i][0] or Loose[i + 1][1];

        Loose[i][1] = 0;
        if(win(S[i] + 1, E[i]) and win(2 * S[i], E[i])) Loose[i][1] = Loose[i][1] or Loose[i + 1][1];
        if(loose(S[i] + 1, E[i]) and loose(2 * S[i], E[i])) Loose[i][1] = Loose[i][1] or Loose[i + 1][0];
        //  cout<<i<<": "<<Win[i][0]<<' '<<Win[i][1]<<" "<<Loose[i][0]<<" "<<Loose[i][1]<<'\n';
    }
    // cout<<win(S[3] + 1, E[3])<<' '<<win(S[3] * 2, E[3])<<'\n';
    cout<<Win[0][0]<<' '<<Loose[0][0]<<'\n';

    return 0;
}