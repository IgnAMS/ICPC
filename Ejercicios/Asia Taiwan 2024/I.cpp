#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<iostream>
#include <algorithm>
#include<set>
#include<array>
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
// g++ -std=c++17 A.cpp -o a && ./a <input.txt> output.txt   
// ulimit -s 1000000
// g++ -O2 I.cpp && time ./a.out <input.txt> output.txt


int n;
int B[20];
vl X;
int DP[1<<18][102];
int dp(int mask, int x) {
    if(DP[mask][x] == 0) return 0;
    DP[mask][x] = 0;
    X.pb(x);
    // cout<<"Entre con "<<x<<"\n";
    // rep(i, n) if((mask>>i) & 1) cout<<i<<", "; cout<<"\n";
    // for(auto u: X) cout<<u<<", "; cout<<"\n\n";

    if(mask == (1<<(n-1)) - 1) {
        return 1;
    }
    rep(i, n - 1) if(!((mask>>i) & 1) and B[i] % x == 0 and B[i] / x <= 100) {
        if(dp(mask | (1<<i), B[i] / x)) return 1;
    }
    X.pop_back();
    return 0;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i, 1<<n) rep(j, 101) DP[i][j] = -1;
    rep(i, n - 1) cin>>B[i];
    rep(i, n - 1) {
        repx(j, 1, 101) if(B[i] % j == 0 and B[i] / j <= 100) {
            X.push_back(j);
            if(dp(1<<i, B[i] / j)) {
                cout<<"Yes\n";
                for(auto u: X) cout<<u<<" "; cout<<"\n";
                // rep(i, n - 1) cout<<X[i] * X[i+1]<<", "; cout<<"\n";
                return 0;
            }
            X.pop_back();
        }
    }
    cout<<"No\n";

    return 0;
}