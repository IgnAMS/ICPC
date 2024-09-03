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
    ll G[101][101];
    
    G[0][0] = 999;
    rep(i, 101) G[i][0] = G[0][i] = G[i][i] = 999;

    rep(i, 101) rep(j, 101) if(i != 0 and j != 0 and i != j) {
        set<ll> S;
        repx(u, 1, max(i, j) + 1) {
            if(i >= u and j >= u) S.insert(G[i - u][j - u]);
            if(i >= u) S.insert(G[i - u][j]);
            if(j >= u) S.insert(G[i][j - u]); 
        }
        ll mex = S.size();
        for(auto it = S.begin(); next(it) != S.end(); it++) {
            if(*it + 1 != *next(it)) {
                mex = *it + 1;
                break;
            }
        }
        if(*S.begin() != 0) mex = 0;
        G[i][j] = mex;
    }

    // rep(i, 10) {
    //     rep(j, 10) cout<<G[i][j]<<'\t'; cout<<'\n'; 
    // }
    
    int n; cin>>n;
    ll ans = 0;
    while(n--) {
        ll l, c; cin>>l>>c;
        ans ^= G[l][c];
        if(l == 0 or c == 0 or l == c) {
            // insta win
            cout<<"Y\n";
            return 0;
        }
    }
    if(ans == 0) cout<<"N\n";
    else cout<<"Y\n";


    return 0;
}