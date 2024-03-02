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
    int n; cin>>n;
    ll x[n], y[n];
    rep(i, n) cin>>x[i]>>y[i];
    ll currx = 0, curry = 0;
    ll INF = 1500000LL * 1500000LL; 
    vl A(n, 1);
    rep(i, n) {
        currx += x[i], curry += y[i];
        if(currx * currx + curry * curry > INF) {
            currx -= 2 * x[i], curry -= 2 * y[i];
            A[i] = -1;
        }
        // cout<<(currx * currx + curry * curry > INF)<<'\n';
        cout<<A[i]<<'\n';
    }

    return 0;
}