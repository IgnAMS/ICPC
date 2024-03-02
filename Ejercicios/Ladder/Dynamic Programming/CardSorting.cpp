#pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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


// A, B, C, D
// A, B, D, C
// A, C, B, D
// A, C, D, B
// A, D, B, C
// A, D, C, B
// ...


// DP[i][]
// tengo dos opciones, o traigo todas para aca, o muevo todas las que estan entre medio y las traigo para aca
// min(
//  sum(A[j] > i) + cost(i) + dp(i + 1),
//  sum(A[j] == i) + cost(i) + dp(i + 1)
// )


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int c, n; cin>>c>>n;
    n *= c;

    vector<pll> X1;
    rep(i, n) {
        int x, a; cin>>x>>a; x--, a--;
        X1.pb({x, a});
    }

    vl B(c); 
    rep(i, c) B[i] = i;
    ll ans = 1e10;
    do {
        ll acc = 0;
        vl X;
        for(auto u: X1) {
            ll aux = (n / c) * B[u.ff] + u.ss;
            X.pb(aux);
        }
        ll auxans = 0;
        ll neutro = 100000;
        vl Aux(n, neutro);
        rep(i, n) {
            ll cont = 0;
            ll l = lower_bound(Aux.begin(), Aux.end(), X[i]) - Aux.begin();
            Aux[l] = X[i];
        }
        rep(i, n) if(Aux[i] != neutro) auxans = n - i - 1;

        ans = min(ans, auxans);

    } while(next_permutation(B.begin(), B.end()));
    cout<<ans<<'\n';




    return 0;
}