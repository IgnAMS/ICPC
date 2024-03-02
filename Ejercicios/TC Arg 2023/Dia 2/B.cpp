#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<ll> vl;

#define rep(i, n) for(int i = 0; i<(int)n; ++i)

int main() {
    int n, m; cin>>n>>m;
    vector<string> M(n);
    rep(i, n) cin>>M[i];
    vector<string> C = {"CATG", "CAGT", "CTAG", "CTGA", "CGAT", "CGTA"}; 
    ll anst = 0, ansoff = 0, ans = 1e7;
    rep(t, 6) {
        rep(offset, 4) {
            vector<string> Pos(n);
            rep(i, n) {
                if(i & 1) {
                    rep(j, m) Pos[i] += C[t][(j + offset + 2) % 4];    
                }
                else rep(j, m) Pos[i] += C[t][(j + offset) % 4];
                // cout<<Pos[i]<<'\n';
            }
            ll curr = 0;
            rep(i, n) rep(j, m) curr += Pos[i][j] != M[i][j];
            if(curr < ans) ans = curr, anst = t, ansoff = offset;
        }
    }
    vector<string> Pos(n);
    rep(i, n) {
        if(i & 1) {
            rep(j, m) Pos[i] += C[anst][(j + ansoff + 2) % 4];    
        }
        else rep(j, m) Pos[i] += C[anst][(j + ansoff) % 4];
        cout<<Pos[i]<<'\n';
    }
    

    return 0;
}