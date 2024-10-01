#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int mat[2][101];
int V[2][101];
int B[2][101];
int n;
int dr[] = {1, 1, 1, 0, -1, -1, -1, 0};
int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};
bool dfs(int i, int j) {
    // cout<<"visito a "<<i<<" "<<j<<' '<<n<<'\n';
    V[i][j] = 1;
    rep(k, 8) {
        ll di = i + dc[k], dj = j + dr[k];
        if(0 <= di and di < 2 and 0 <= dj and dj < n and !mat[di][dj] and !V[di][dj])
            B[i][j] |= dfs(di, dj);
    }
    return B[i][j];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        cin>>n;
        string S[2]; cin>>S[0]>>S[1];
        rep(i, 2) rep(j, n) mat[i][j] = S[i][j] == '1';
        rep(i, 2) rep(j, n) V[i][j] = 0, B[i][j] = 0;
        B[1][n - 1] = 1;
        if(dfs(0, 0)) cout<<"YES\n";
        else cout<<"NO\n";
    }



    return 0;
}