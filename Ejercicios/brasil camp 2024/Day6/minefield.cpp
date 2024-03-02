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

ll dr[] = {-1, 0};
ll dc[] = {0, -1};

const int mxN = 2005;
pll D[mxN][mxN];
char DP[mxN][mxN];
string mat[mxN];

char dfs(ll i, ll j) {
    if(i == 0 and j == 0) return 1;
    if(i < 0 or j < 0 or mat[i][j] == '#') return 'N';
    if(DP[i][j] != ' ') return DP[i][j];
    rep(h, 2) {
        ll di = i + dr[h], dj = j + dc[h];
        if(dfs(di, dj) != 'N') {
            D[di][dj] = {i, j};
            return DP[di][dj] = (h == 0? 'D': 'R');
        }
    }
    return DP[i][j] = 'N';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int r, c; cin>>r>>c;
        rep(i, r) cin>>mat[i];
        
        rep(i, r + 1) rep(j, c + 1) DP[i][j] = ' ';

        if(dfs(r - 1, c - 1) != 'N') {
            cout<<"YES\n";
            ll i = 0, j = 0, previ = -1, prevj = -1;
            string ans = "";
            vl R(r, 0), C(c, 0);
            while(i != r - 1 or j != c - 1) {
                if(mat[i][j] == '@' and R[i] + C[j] == 0) {
                    if(i != previ) R[i] = 1;
                    else if(j != prevj) C[j] = 1;
                }
                if(mat[i][j] == 'O' and R[i] + C[j] == 1) R[i] = 1, C[j] = 1;
                ans += DP[i][j];
                tie(previ, prevj) = tie(i, j);
                tie(i, j) = D[i][j];
            }
            if(mat[i][j] == '@' and R[i] + C[j] == 0) {
                if(i != previ) R[i] = 1;
                else if(j != prevj) C[j] = 1;
            }
            if(mat[i][j] == 'O' and R[i] + C[j] == 1) R[i] = C[j] = 1; 
            
            
            rep(i, r) cout<<(R[i]? 'Y': 'N'); cout<<'\n';
            rep(i, c) cout<<(C[i]? 'Y': 'N'); cout<<'\n';
            cout<<ans<<'\n';
        }
        else cout<<"NO\n"; 
    }

    return 0;
}