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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int base = 11;
    ll n = 32;
    string n2 = "";
    char B[base];
    rep(i, min(base, 10)) B[i] = i + '0';
    
    rep(i, base - 10) B[i + 10] = char(i + 'A');
    rep(i, base) cout<<B[i]<<'\n'; 

    // log_b(n)
    while(n) {
        n2 += B[n % base];
        n /= base;
    }
    reverse(n2.begin(), n2.end());
    cout<<n2<<'\n';

    return 0;
}