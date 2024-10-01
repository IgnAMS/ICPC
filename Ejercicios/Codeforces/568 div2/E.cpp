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
        int n, m; cin>>n>>m;
        string s[n];
        rep(i, n) cin>>s[i];

        vector<array<ll, 4>> X;
        bool pos = 1;
        rep(c, 26) {
            // primero itero y encuentro una posicion arbitraria
            pll first = {-1, -1};
            bool vertical = 0;
            rep(i, n) rep(j, m) {
                if(s[i][j] == 'a' + c and first.ff == -1) {
                    // Este es el de mas arriba o el de mas a la izquierda
                    first = {i, j};
                }
                else if(s[i][j] == 'a' + c) {
                    if(abs((ll)i - first.ff) * abs((ll)j - first.ss) > 0) pos = 0;
                    else if(i != first.ff) vertical = 1;
                }
            }
            if(first.ff == -1) continue;
            else {
                while(X.size() < c) X.pb({first.ff, first.ss, first.ff, first.ss});
            }
            if(!pos) break;
            
            rep(i, n) rep(j, m) if(s[i][j] == 'a' + c) {
                if(vertical and j != first.ss) pos = 0;
                if(!vertical and i != first.ff) pos = 0;
            }
            if(!pos) break;

            pll end = {-1, -1};
            for(int i = n - 1; i >= 0; i--) for(int j = m - 1; j >= 0; j--) if(s[i][j] == 'a' + c and end.ff == -1) {
                // cout<<"encontre el final en "<<i<<", "<<j<<" para la letra "<<char('a' + c)<<'\n';
                end = {i, j};
                break;
            }
            repx(i, min(first.ff, end.ff), max(first.ff, end.ff) + 1) {
                repx(j, min(first.ss, end.ss), max(first.ss, end.ss) + 1) {
                    if(s[i][j] == '.') pos = 0;
                    else if(s[i][j] == 'a' + c) s[i][j] = '.';
                }
            }
            X.pb({first.ff, first.ss, end.ff, end.ss});
        }
        if(pos) {
            cout<<"YES\n";
            cout<<X.size()<<'\n';
            for(auto [r1, c1, r2, c2]: X) cout<<r1 + 1<<' '<<c1 + 1<<' '<<r2 + 1<<' '<<c2 + 1<<'\n';
        }
        else cout<<"NO\n";


    }    







    return 0;
}