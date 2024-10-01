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

vi Comps;
int dr[] = {1, -1, 0, 0}; 
int dc[] = {0, 0, 1, -1};
ll D[2002][2002];
ll mat[2002][2002];
int n, m;
void dfs(int i, int j) {
    // cerr<<i<<' '<<j<<'\n';
    D[i][j] = (ll)Comps.size() - 1;
    Comps.back()++;
    rep(k, 4) {
        ll di = i + dr[k], dj = j + dc[k];
        if(0 <= di and di < n and 0 <= dj and dj < m and D[di][dj] == -1 and mat[di][dj]) 
            dfs(di, dj);
    }
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i, n) {
        string s; cin>>s;
        rep(j, m) mat[i][j] = s[j] == '*';
    }

    // up, down, left right
    ll Acc[4][n + 2][m + 2];
    rep(i, 4) rep(j, n + 2) rep(k, m + 2) Acc[i][j][k] = 0;
    rep(i, n) rep(j, m) {
        Acc[0][i + 1][j] = (mat[i][j]? Acc[0][i][j] + mat[i][j]: 0);
        Acc[1][n - i - 1][j] = (mat[n - i - 1][j]? Acc[1][n - i][j] + mat[n - i - 1][j]: 0);
        Acc[2][i][j + 1] = (mat[i][j]? Acc[2][i][j] + mat[i][j]: 0);
        Acc[3][i][m - j - 1] = (mat[i][m - j - 1]? Acc[3][i][m - j] + mat[i][m - j - 1]: 0);
    }
    // rep(i, n) {
    //     rep(j, m) cout<<Acc[3][i][j]<<' '; cout<<'\n';
    // }
    rep(i, n) rep(j, m) D[i][j] = -1;
    rep(i, n) rep(j, m) if(D[i][j] == -1 and mat[i][j]) {
        Comps.push_back(0);
        dfs(i, j);
    }

    ll ans = 0;
    rep(i, n) rep(j, m) if(D[i][j] != -1) {
        ll up = Acc[0][i + 1][j], down = Acc[1][i][j];
        ll left = Acc[2][i][j + 1], right = Acc[3][i][j];
        // cout<<i<<", "<<j<<": "<<up<<' '<<down<<' '<<left<<' '<<right<<' '<<Comps[D[i][j]]<<'\n';
        if(up > 1 and up == left and up == right and up < down and 
            Comps[D[i][j]] == up + down + left + right - 3) {
                // cout<<"YES: "<<i<<" "<<j<<'\n';
                ans++; 
        }
    }
    cout<<ans<<'\n';




    return 0;
}