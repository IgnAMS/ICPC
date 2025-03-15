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


const int mxN = 4000;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    int n = s.length();

    vl L(2 * n, 0), R(2 * n, 0), U(2 * n, 0);
    ll p = 1, cont = 2;
    
    
    vl Hoja = {p};
    for(auto c: s) {
        // cout<<p<<'\n';
        if(c == 'L') {
            if(!L[p]) {
                L[p] = cont;
                U[cont] = p;
                cont++;
            }
            p = L[p];
        }
        if(c == 'R') {
            continue;
        }
        if(c == 'U') {
            if(!U[p]) {
                U[cont] = p;
                L[p] = cont;
                cont++; 
            }
            p = U[p];
        }
    }

    ll Pos[3][n];
    rep(i, 3) rep(j, n) Pos[i][j] = 1;

    p = 1;
    rep(i, 2000) {
        for(auto c: s) {
            if(c == 'L' and L[p]) Pos[0][p] = 0, p = L[p];
            else if(c == 'L') Pos[0][p] = 0;

            if(c == 'R' and R[p]) Pos[1][p] = 0, p = R[p];
            else if(c == 'R') Pos[1][p] = 0;
            
            if(c == 'U' and U[p]) Pos[2][p] = 0, p = U[p];
            else if(c == 'U') Pos[2][p] = 0;
        }
    }

    pll best = {-1, -1};
    repx(i, 1, cont) {
        rep(j, 3) if(Pos[j][i]) best = {i, j};
    }
    if(best.ff == -1) {
        cout<<"-1\n";
        return 0;
    }

    // cout<<best.ff<<' '<<best.ss<<'\n';

    if(best.ss == 0) {
        L[best.ff] = cont;
        cout<<L[best.ff]<<'\n';
        U[cont] = best.ff;
        cont++;
    }
    if(best.ss == 1) {
        R[best.ff] = cont;
        U[cont] = best.ff;
        cont++;
    }
    if(best.ss == 2) {
        U[best.ff] = cont;
        L[cont] = best.ff;
        cont++;
    }

    cout<<cont - 1<<' '<<best.ff<<' '<<cont - 1<<'\n';
    repx(i, 1, cont) {
        cout<<L[i]<<' '<<R[i]<<'\n';
    }






    return 0;
}