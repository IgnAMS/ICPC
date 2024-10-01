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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n, m; cin>>n>>m;
        ll mat[n][m];
        ll suma = 0;
        vl sumCol(n, 0);
        rep(i, n) rep(j, m) {
            cin>>mat[i][j];
            suma += mat[i][j];
            sumCol[i] += mat[i][j];
        }
        if(suma % n != 0) {
            cout<<"-1\n";
            continue;
        }
        ll cont = 0;
        ll prom = suma / n;
        vector<array<ll, 3>> Ans;
        rep(j, m) {
            vl X;
            rep(i, n) if(sumCol[i] > prom and mat[i][j] == 1) X.pb(i);
            rep(i, n) if(sumCol[i] < prom and mat[i][j] == 0) {
                if(X.size()) {
                    sumCol[i]++;
                    sumCol[X.back()]--;
                    Ans.pb({i, X.back(), j});
                    X.pop_back();
                }
            }
        }
        cout<<Ans.size()<<'\n';
        for(auto [a, b, c]: Ans) cout<<a + 1<<' '<<b + 1<<' '<<c + 1<<'\n';
    }



    return 0;
}