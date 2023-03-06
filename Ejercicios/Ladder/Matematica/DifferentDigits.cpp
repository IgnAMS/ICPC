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


bool f(ll x) {
    set<ll> S;
    while(x) {
        if(S.count(x % 10)) return 0;
        S.insert(x % 10);
        x /= 10;
    }
    return 1;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; 
    ll DP[5010];
    DP[0] = 0;
    repx(i, 1, 5010) {
        DP[i] = f(i) + DP[i - 1];
    }
    while(cin>>n>>m) {
        cout<<DP[m] - DP[n - 1]<<'\n';
    }


    return 0;
}