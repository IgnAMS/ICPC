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

ll n, m, k;
string S[100005];
ll R[100005];



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    rep(i, n) cin>>S[i];
    
    srand(time(0));
    ll suma = 0;

    // suma <= 9 * 10^8 * N <= 9 * 10^13
    rep(i, n) {
        // Generar numero entre [1, ~9 * 10^8]
        R[i] = RAND_MAX * rand() + rand(); 
        // cout<<R[i]<<' '; cout<<'\n';
        suma += k * R[i];
    }

    ll Multi[m][4];
    rep(i, m) rep(c, 4) Multi[i][c] = 0;
    rep(i, n) {
        // Multi[j][c] = indices i tales que en la pos j tienen el char c
        rep(j, m) Multi[j][S[i][j] - 'A'] += R[i];
    }
    

    rep(i, n) {
        // Pruebo si es que multi + R[i] * k == suma
        ll multi = 0;
        rep(j, m) {
            rep(c, 4) if(c != S[i][j] - 'A') multi += Multi[j][c];
        }
        // cout<<multi<<' '<<R[i]<<' '<<k<<' '<<suma<<'\n';
        if(multi + R[i] * k == suma) {
            cout<<i + 1<<'\n';
            return 0;
        }
    }


    return 0;
}