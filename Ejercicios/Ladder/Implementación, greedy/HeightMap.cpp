#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt
ll mat[100][100], r, c;
bool V[100][100];
ll dr[] = { 1, -1, 0, 0 };
ll dc[] = { 0, 0, 1, -1 };

void dfs(int i, int j) {
    V[i][j] = 1;
    rep(k, 4) {
        ll di = i + dr[k], dj = j + dc[k];
        if(0 <= di and di < r and 0 <= dj and dj < c and 
            mat[di][dj] == mat[i][j] and !V[di][dj]) dfs(di, dj); 
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>r>>c; memset(V, 0, sizeof V);
    rep(i, r) rep(j, c) cin>>mat[i][j];
    ll ans = 6;
    rep(i, r) rep(j, c) {
        if(i + 1 < r and mat[i][j] != mat[i + 1][j]) ans++;
        if(0 < j and mat[i][j] != mat[i][j - 1]) ans++;
        bool sign;
        
        sign = ((mat[i][j] - mat[i + 1][j - 1]) * (mat[i][j] - mat[i + 1][j])) > 0;
        if(0 < j and i + 1 < r and mat[i][j] == mat[i][j - 1] and sign) ans--;
        
        sign = ((mat[i][j] - mat[i - 1][j - 1]) * (mat[i][j] - mat[i][j - 1])) > 0;
        if(0 < j and 0 < i and mat[i][j] == mat[i - 1][j] and sign) ans--; 
        // cout<<"i, j: "<<i<<", "<<j<<", ans: "<<ans<<'\n';
    }
    if(1 < r) rep(j, c - 1) {
        bool sign = ((mat[r - 2][j] - mat[r - 1][j]) * (mat[r - 2][j + 1] - mat[r - 1][j])) > 0;
        if(mat[r - 1][j] == mat[r - 1][j + 1] and mat[r - 2][j] != mat[r - 2][j + 1] and sign) ans--;
    }
    if(1 < c) rep(i, r - 1) {
        bool sign = ((mat[i + 1][1] - mat[i][0]) * (mat[i][1] - mat[i][0])) > 0;
        if(mat[i][0] == mat[i + 1][0] and mat[i + 1][1] != mat[i][1] and sign) ans--;
    }
    
    rep(i, r) rep(j, c) if(!V[i][j]) ans++, dfs(i, j);
    cout<<ans - 1<<'\n';



    return 0;
}