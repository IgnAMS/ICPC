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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        ll A[n];
        rep(i, n) cin>>A[i];
        ll B[n];
        rep(i, n - 1) B[i] = __gcd(A[i], A[i + 1]);
        ll L[n + 1], R[n + 1];
        L[0] = 1;
        repx(i, 1, n - 1) {
            if(B[i - 1] <= B[i]) L[i] = 1;
            else L[i] = 0;
            L[i] = min(L[i - 1], L[i]);
        }
        R[n - 1] = 1, R[n - 2] = 1;
        for(int i = n - 3; i >= 0; i--) {
            if(B[i] <= B[i + 1]) R[i] = 1;
            else R[i] = 0;
            R[i] = min(R[i], R[i + 1]);
        }

        // rep(i, n - 1) cout<<R[i]<<' '; cout<<'\n';
        // rep(i, n - 1) cout<<L[i]<<' '; cout<<'\n';
        

        // Si es que todos menos el primer elemento o todos menos el ultimo es no decreciente
        // Entonces gane :)
        ll ans = R[1] or L[n - 3];
        B[n - 1] = 1e9;

        // Que pasa si es que remuevo 
        repx(i, 0, n - 2) {
            // i + 1 < n - 1  ->  i < n - 2
            // Saco A[i + 1] -> Afecta a B[i] y B[i + 1]
            // Vuelvo a calcular B[i] y B[i + 1] deja de existir
            ll x = __gcd(A[i], A[i + 2]);
            // n - 3 + 2 = n - 1
            // B[n - 1] = 1e9, R[n - 1] = 1 por lo que deberia funcionar
            if(i == 0 and x <= B[i + 2] and R[i + 2]) ans = 1;
            if(i > 0 and B[i - 1] <= x and x <= B[i + 2] and L[i - 1] and R[i + 2]) ans = 1; 
        }
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}