#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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
    ll t; cin>>t;
    while(t--) {
        ll n, m; cin>>n>>m;
        vl A(n); rep(i, n) cin>>A[i];
        vl B(m); rep(i, m) cin>>B[i];
        ll x = A[0];
        repx(i, 1, n) x = x ^ A[i];
        // cout<<x<<endl; 
        ll mn = x, mx = x;
        if(n % 2 == 0) {
            // n es par, asi que solamente me disminuye agregarle cosas
            // Esto se debe a que agregarle cosas se cancelaran igualmente
            rep(i, m) {
                mn = min(mn, mn & ~B[i]);
            }
        }
        else {
            // n es impar, asi que solo me aporta agregarle cosas
            rep(i, m) mx = max(mx, mx | B[i]);
        }
        cout<<mn<<' '<<mx<<'\n';

    }
    return 0;
}