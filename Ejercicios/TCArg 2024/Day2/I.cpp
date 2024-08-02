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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    ll mat[n][m];
    ll ans = 0;
    ll imp = 0;
    rep(i, n) rep(j, m) cin>>mat[i][j];

    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            if(mat[i][j] == 0) mat[i][j] = min(mat[i + 1][j], mat[i][j + 1]) - 1;
            if(i+1 < n and mat[i][j] >= mat[i + 1][j]) {
                imp = 1;
            }
            if(j+1 < m and mat[i][j] >= mat[i][j + 1]) {
                imp = 1;
            }
            ans += mat[i][j];
        }
    }
    if(imp) cout<<"-1\n";
    else cout<<ans<<'\n';


    return 0;
}