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


ll solve(int n, int k) {
    if(k <= n / 2) return 2 * k;
    if(n == 1) return 1;
    ll val = solve(n - n/2, k - n/2);
    if(n % 2 == 1) {
        if(val == 1) return n;
        return 2 * (val - 1) - 1; 
    }
    return 2 * val - 1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int q; cin>>q;
    while(q--) {
        ll n, k; cin>>n>>k;
        cout<<solve(n, k)<<'\n';
    }

    return 0;
}