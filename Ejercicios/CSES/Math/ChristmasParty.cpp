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
    ll n; cin>>n;
    ll mod = 1e9+7;
    ll F[1000006];
    F[0] = 0, F[1] = 0, F[2] = 1;
    repx(i, 3, 1e6+1) F[i] = ((F[i - 1] + F[i - 2]) % mod ) * (i - 1) % mod;
    cout<<F[n]<<'\n';
    

    return 0;
}