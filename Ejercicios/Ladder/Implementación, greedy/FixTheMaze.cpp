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
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt


vector<vector<bool>> V;
vector<vector<vector<bool>>> D;
// 0: up, 1: down, 2: left, 3: right
int dc[] = {0, 0, -1, 1};
int dr[] = {-1, 1, 0, 0};
int n;

int cont = 0;

void dfs(int i, int j) {
    V[i][j] = 1;
    for(int k = 0; k < 4; k++) {
        if(D[i][j][k]) {
            int di = i + dr[k], dj = j + dc[k];
            if(0 <= di and di < 2 * n and 0 <= dj and dj < 2 * n + 1 and !V[di][dj]) {
                dfs(di, dj);
            }
        }
    }
}

void dfs2(int i, int j) {
    vector<ii> S;
    S.push_back({i, j});
    while(!S.empty()) {
        i = S.back().ff, j = S.back().ss;
        S.pop_back(); 
        V[i][j] = 1;
        rep(k, 4) if(D[i][j][k]) {
            int di = i + dr[k], dj = j + dc[k];
            if(0 <= di and di < 2 * n and 0 <= dj and dj < 2 * n + 1 and !V[di][dj]) {
                S.push_back({di, dj});
            }
        }

    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(cin>>n) {
        vector<string> S(2 * n + 1);
        rep(i, 2 * n - 1) cin>>S[i];
        D.assign(2 * n + 3, vector<vector<bool>>(2 * n + 3, vector<bool>(4, 1)));
        rep(i, 2 * n - 1) rep(j, n) {
            auto u = S[i][j];
            if(u == 'H' and i % 2 == 0) {
                D[i][2 * j][1] = D[i][2 * j + 1][1] = 0;
                D[i + 1][2 * j][0] = D[i + 1][2 * j + 1][0] = 0;
            }
            else if(u == 'H') {
                D[i][2 * j + 1][1] = D[i][2 * j + 2][1] = 0;
                D[i + 1][2 * j + 1][0] = D[i + 1][2 * j + 2][0] = 0;
            }
            else if(u == 'V' and i % 2 == 0) {
                D[i][2 * j][3] = D[i + 1][2 * j][3] = 0;
                D[i][2 * j + 1][2] = D[i + 1][2 * j + 1][2] = 0;
            }
            else {
                D[i][2 * j + 1][3] = D[i + 1][2 * j + 1][3] = 0;
                D[i][2 * j + 2][2] = D[i + 1][2 * j + 2][2] = 0;
            }
        }

        V.assign(2 * n + 3, vector<bool>(2 * n + 3, 0));
        int ans = 0;
        rep(i, 2 * n) rep(j, 2 * n + 1) if(!V[i][j]) {
            ans++; 
            dfs2(i, j);
            // cerr<<"termino exploracion!\n\n";
        }

        cout<<ans - 1<<'\n';
        

    }





    return 0;
}