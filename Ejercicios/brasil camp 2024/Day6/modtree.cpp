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


map<ll, ll> mp;
ll ans = 0;
ll k;
const int mxN = 1e6+6;
ll A[mxN];
void dfs(ll u, ll d) {
    if(mp.count(k - d)) ans += mp[k - d];
    for(auto v: G[u]) {
        ll next = (A[v] + d) % k
        if(!mp.count(next)) mp[next] = 0;
        mp[next]++;
        dfs(v, next);
        mp[next]--;
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);





    return 0;
}