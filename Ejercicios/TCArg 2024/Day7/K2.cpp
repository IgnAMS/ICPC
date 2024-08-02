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
    if(e < 2 * s) return 1;
    // s <= e / 2
    return win(s, e / 2);
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll n; cin>>n;
        pll X[n];
        rep(i, n) {
            ll s, e; cin>>s>>e;
            X[i] = {win(s, e), loose(s, e)};
        }


    }





    return 0;
}