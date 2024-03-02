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
    int n, k; cin>>n>>k;
    vl A(n); rep(i, n) cin>>A[i];
    sort(A.begin(), A.end());
    ll l = 0, r = 1e10;
    while(l < r) {
        ll faltantes = 0;
        ll m = (l + r + 1) / 2;
        for(int i = n / 2; i < n; i++) faltantes += max(0LL, m - A[i]);
        if(faltantes <= k) l = m;
        else r = m - 1;
    }
    cout<<l<<'\n';


    return 0;
}