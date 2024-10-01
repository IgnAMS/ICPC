#pragma GCC optimize("Ofast")
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


ll n, m, k;
ll A[20][20];
map<ll, ll> X[20][20];

void left(int i, int j, ll u) {
    u ^= A[i][j];
    if(i + j == (n + m - 2) / 2) {
        X[i][j][u]++;
        return;
    }
    if(i + 1 < n) left(i + 1, j, u);
    if(j + 1 < m) left(i, j + 1, u);
}

ll ans = 0;
void right(int i, int j, ll u) {
    if((n - 1 - i) + (m - 1 - j) == (n + m - 1) / 2) {
        ans += X[i][j][k ^ u];
        return;
    }
    if(i) right(i - 1, j, u ^ A[i][j]);
    if(j) right(i, j - 1, u ^ A[i][j]);
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    rep(i, n) rep(j, m) cin>>A[i][j];
    left(0, 0, 0);
    right(n - 1, m - 1, 0);
    cout<<ans<<'\n';

    return 0;
}