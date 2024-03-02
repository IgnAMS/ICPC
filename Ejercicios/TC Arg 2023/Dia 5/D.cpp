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


vector<vl> G;



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vl A(n);
    rep(i, n) {
        cin>>A[i];
    }

    vl Primes;
    repx(i, 2, 3000) {
        bool oc = 1;
        for(int j = 2; j <= sqrt(i) + 1e-6; i++) {
            if(i % j == 0) oc = 0;
        }
        if(oc) Primes.pb(i);
    }
    

    rep(i, n) rep(j, n) if(i != j) {
        auto it = lower_bound(Primes.begin(), Primes.end(), A[i] + A[j]);
        if(*it == A[i] + A[j]) G[i].pb(j);
    }
    

    




    return 0;
}