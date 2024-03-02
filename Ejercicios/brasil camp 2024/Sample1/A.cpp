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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll A[7];
    rep(i, 7) cin>>A[i]; 
    ll n, w; cin>>n>>w;

    vl C(7, 0);
    ll cont = 0;
    rep(mask, 1<<7) {
        ll active = 0, suma = 0;
        rep(i, 7) {
            if(mask & (1<<i)) active++, suma += A[i];
        }

        if(active == n and suma == w) {
            cont++;
            rep(i, 7) if(mask & (1<<i)) C[i]++;
        } 
    }
    rep(i, 7) {
        if(C[i] == cont) cout<<i + 1<<" present\n";
        else if(C[i] == 0) cout<<i + 1<<" absent\n";
        else cout<<i + 1<<" unknown\n";
    }


    return 0;
}