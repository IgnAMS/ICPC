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


ll ans = 0;
ll X[8], D1[16], D2[16];
vl curr;
string mat[8];
ll cont = 0;

void solve(ll i) {
    if(i == 8) {
        ans++;
        return;
    }
    rep(j, 8) if(X[j] == 0) {
        if(D1[j + i]) continue;
        if(D2[j - i + 8]) continue;
        if(mat[i][j] == '*') continue;

        D1[j + i] = 1;
        X[j] = 1;
        D2[j - i + 8] = 1;

        curr.pb(j);
        solve(i + 1);
        curr.pop_back();

        D1[j + i] = 0;
        X[j] = 0;
        D2[j - i + 8] = 0;
    }
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    rep(i, 8) cin>>mat[i];
    solve(0);
    cout<<ans<<'\n';


    return 0;
}