#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<iostream>
#include<algorithm>
#include<numeric>
#include <cmath>
#include<set>
#include<array>
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
// g++ -std=c++17 A.cpp -o a && ./a <input.txt> output.txt   
// ulimit -s 1000000
// g++ -std=c++17 -O2 C2.cpp && time ./a.out <input.txt> output.txt

const int mxN = 5e4+10;
int n, k, A[mxN], P[mxN];


// Para cada i de P, calcular cuantos cambios tengo a mi izquierda y a mi derecha
// Definirlas como L[i]: cambios izquierda, R[i]: cambios derecha, C[i]: Cambios en la isla i
// Lo que quiero hacer es minimizar sum X[i] tq para todo intervalo: sum X[i] + X[i+1] >= C[i]
// Debo distribuir los valores de X[i] de alguna forma que lo cumpla.

// 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1
//     x               x   x    
void solve() {
    cin>>n>>k;
    rep(i, n) cin>>A[i];
    rep(i, k) cin>>P[i];





}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();

    return 0;
}