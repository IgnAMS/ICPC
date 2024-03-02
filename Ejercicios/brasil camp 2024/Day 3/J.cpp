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

// 1e8 * 7 * Log2[7] ~ 1e9 :c
// 1e8 * 7 si uso un unordered set
set<ll> Div[10];
ll ind(int i, int j) {
    ll ans = 0;
    for(auto p: Div[i]) {
        if(!Div[j].count(p)) ans++;  
    }
    for(auto p: Div[j]) {
        if(!Div[i].count(p)) ans++;
    }
    return ans;
}




int main() {
    ios::sync_with_stdio(0); cin.tie(0);






    return 0;
}