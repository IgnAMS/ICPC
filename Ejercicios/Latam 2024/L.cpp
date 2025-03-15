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
// g++ -O2 L.cpp && time ./a.out <input.txt> output.txt

// DP[i][j] = DP[i + 1][j] if !C[i + j] or X[i] = i + j OR DP[i][j + 1] if !C[i + j] or X[j] = i + j
 

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, t; cin>>n>>t;
    pll A[n][n];
    rep(i, n) rep(j, n) A[i][j] = {i, j};

    rep(i, t) {
        string s; cin>>s;
        int a, b; cin>>a>>b; a--, b--;
        if(s == "R") rep(j, n) swap(A[a][j], A[b][j]);
        else rep(j, n) swap(A[j][a], A[j][b]);
    }

    rep(i, n) {
        rep(j, n) cout<<"("<<A[i][j].ff<<", "<<A[i][j].ss<<"), "; 
        cout<<'\n';
    }

    return 0;
}