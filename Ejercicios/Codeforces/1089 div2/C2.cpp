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
int n, A[mxN], B[mxN];
ll DP[mxN][25]; 
vl Primes;


void solve() {
    cin>>n;
    rep(i, n) cin>>A[i];
    rep(i, n) cin>>B[i];
    
    set<ll> S[n];
    vl Pos(n, 0);

    rep(i, n) {
        ll gcd_left = 1, gcd_right = 1;
        if(i > 0) gcd_left = gcd(A[i-1], A[i]); 
        if(i+1 < n) gcd_right = gcd(A[i], A[i+1]); 
        ll aux = 1LL * gcd_left * gcd_right / gcd(gcd_left, gcd_right);
        if(aux != A[i] and aux <= B[i]) {
            // cout<<"asigno "<<aux<<" en "<<i<<"\n";
            Pos[i] = 1;
            A[i] = aux;
        }
    }


    rep(i, n) {
        ll gcd_left = 1, gcd_right = 1;
        if(i > 0) gcd_left = gcd(A[i-1], A[i]); 
        if(i+1 < n) gcd_right = gcd(A[i], A[i+1]); 
        if(Pos[i]) continue;

        rep(j, 22) {
            ll p = Primes[j];
            if(i and (A[i-1] / gcd_left) % p == 0) continue;
            if(i+1 < n and (A[i+1] / gcd_right) % p == 0) continue;
            if(i and S[i-1].size() == 1 and S[i-1].count(p)) continue;
            if(A[i] * p > B[i]) continue;
            if(S[i].size() >= 2) break;
            // cout<<"asigno "<<p<<" en "<<i<<"\n";

            S[i].insert(p);
            Pos[i] = 1;
        } 
    }
    ll ans = 0;
    rep(i, n) ans += Pos[i];
    cout<<ans<<"\n";
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    
    // primeros 30 primos si o si están en los primeros 1k numeros
    repx(i, 2, 1000) {
        bool prime = 1;
        repx(j, 2, int(sqrt(i))+1) {
            if(i % j == 0 and i != j) prime = 0; 
        }
        if(prime) Primes.pb(i);
    }
    // for(auto p: Primes) cout<<p<<" "; cout<<"\n";
    // cout<<Primes.size()<<"\n";
    
    while(t--) solve();    

    return 0;
}