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


const int mxN = 4e5+5;
ll Calc[20][mxN], Mn[20];

const int mxM = (1<<20) + 1;
ll DP[mxM];
ll Suma[mxM];

int n;
string S[20];

// La suma de los elementos la podemos precomputar
ll dp(ll mask) {
    if(DP[mask] != -1) return DP[mask];

    DP[mask] = 0;
    rep(i, n) if(!(mask & (1<<i))) {
        // Si no puedo extenderme entonces obtengo lo que pueda sacar
        if(Suma[mask] + Mn[i] < 0) DP[mask] = max(DP[mask], Calc[i][Suma[mask]]);
        // Si es que puedo extenderme aumento mi respuesta con lo que pueda extenderme :)
        else if(Suma[mask] + Mn[i] == 0) DP[mask] = max(DP[mask], dp(mask | (1<<i)) + Calc[i][Suma[mask]]);
        else DP[mask] = max(DP[mask], dp(mask | (1<<i)));
    }
    return DP[mask];
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i, n) {
        cin>>S[i];
        Mn[i] = 0;
        rep(j, mxN) Calc[i][j] = 0;
        ll curr = 0;
        for(auto c: S[i]) {
            curr += (c == '('? 1: -1);
            if(curr <= Mn[i]) Calc[i][-curr]++;
            Mn[i] = min(Mn[i], curr);
        }

        rep(mask, (1<<n)) if(mask & (1<<i)) Suma[mask] += curr;
    }
    
    rep(mask, (1<<n)) DP[mask] = -1;
    cout<<dp(0)<<'\n';

    return 0;
}