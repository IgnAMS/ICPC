#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<iostream>
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

bool V[1001][1001];
string S[1001];
vector<pll> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m; 

void dfs(int i, int j) {
    V[i][j] = 1;
    for(auto [dx, dy]: dirs) {
        int di = i+dx, dj = j+dy;
        if(0 <= di and di < n and 0 <= dj and dj < m and !V[di][dj] and S[di][dj] == '.') {
            dfs(di, dj);
        }
    }
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i, n) cin>>S[i];

    ll ans = 0;
    rep(i, n) {
        rep(j, m) if(!V[i][j] and S[i][j] == '.') {
            dfs(i, j), ans++;
        }
    }
    cout<<ans<<"\n";

    return 0;
}