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
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;

        ll ans = 0;
        ll mat[n][n];
        memset(mat, 0, sizeof(mat));
        
        vector<pll> Ops;
        bool type = 1;
        
        for(int i = n - 1; i >= 0; i--) rep(b, 2) {
            Ops.pb({b, i});
            rep(j, n) {
                if(b) mat[i][j] = j + 1;
                else mat[j][i] = j + 1;
            }
        }

        rep(i, n) {
            rep(j, n) ans += mat[i][j];
        }
        
        cout<<ans<<' '<<2 * n<<'\n';
        for(int i = n - 1; i >= 0; i--) rep(b, 2) {
            cout<<b + 1<<' '<<i + 1<<' ';
            rep(j, n) cout<<j + 1<<' '; cout<<'\n';
        }
        
    }

    return 0;
}