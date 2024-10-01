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
    int t; cin>>t;
    while(t--) {
        int n, m; cin>>n>>m;
        vl R(n, 0), C(m, 0);
        vector<string> M(n); rep(i, n) cin>>M[i];
        vector<vl> H(m, vl()), V(n, vl());
        rep(i, n) rep(j, m) {
            if(M[i][j] == 'L') {
                C[j]++;
                H[j].pb(i);
            }
            if(M[i][j] == 'R') C[j]++;
            if(M[i][j] == 'U') {
                R[i]++;
                V[i].pb(j);
            }
            if(M[i][j] == 'D') R[i]++;
        }
        bool pos = 1;
        rep(i, n) if(R[i] % 2) pos = 0;
        rep(i, m) if(C[i] % 2) pos = 0;
        if(!pos) {
            cout<<"-1\n";
            continue;
        }
        string aux = ""; rep(i, m) aux += '.'; 
        vector<string> Ans(n, aux);
        rep(i, n) {
            int col = 0;
            for(auto j: V[i]) {
                // cerr<<"vertical: "<<i<<' '<<j<<'\n';
                Ans[i][j] = col? 'B': 'W';
                Ans[i + 1][j] = col? 'W': 'B';
                col = 1 ^ col;
            } 
        }
        rep(j, m) {
            int col = 0;
            for(auto i: H[j]) {
                // cerr<<"horizontal: "<<i<<' '<<j<<'\n';
                Ans[i][j] = col? 'B': 'W';
                Ans[i][j + 1] = col? 'W': 'B';
                col = 1 ^ col;
            }
        }
        rep(i, n) cout<<Ans[i]<<'\n';
        // cerr<<"wohoo\n";
        
    }

    return 0;
}