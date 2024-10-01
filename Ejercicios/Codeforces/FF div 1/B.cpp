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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m, k, p; cin>>n>>m>>k>>p;
    ll mat[n][m]; rep(i, n) rep(j, m) cin>>mat[i][j];
    vi R(k + 1, 0), C(k + 1, 0);
    priority_queue<ll, vector<ll>> pqc, pqr;
    rep(i, n) {
        ll suma = 0;
        rep(j, m) suma += mat[i][j];
        pqr.push(suma);
    } 
    rep(j, m) {
        ll suma = 0;
        rep(i, n) suma += mat[i][j];
        pqc.push(suma);
    }
    repx(i, 1, k + 1) {
        ll x = pqr.top(); pqr.pop();
        R[i] = R[i - 1] + x;
        pqr.push(x - m * p);
    }
    repx(i, 1, k + 1) {
        ll x = pqc.top(); pqc.pop();
        C[i] = C[i - 1] + x;
        pqc.push(x - n * p);
    }
    ll ans = -1e16;
    rep(i, k + 1) {
        ans = max(ans, C[i] + R[k - i] - i * (k - i) * p);
    }
    cout<<ans<<'\n';





    return 0;
}