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

int dc[] = {1, -1, 0, 0};
int dr[] = {0, 0, 1, -1};


ll D[1000][1000];
string mat[1000];
int r, c, k;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        cin>>r>>c>>k;
        rep(i, r)  cin>>mat[i];
        
        queue<pll> q;
        rep(i, r) rep(j, c) D[i][j] = 1e7;
        
        bool onlyx = 1;
        rep(i, r) rep(j, c) if(mat[i][j] == '.') {
            onlyx = 0;
            q.push({i, j});
            D[i][j] = 0;
        }

        if(onlyx) {
            cout<<"YES\n";
            continue;
        }
        
        while(!q.empty()) {
            ll i = q.front().ff, j = q.front().ss; 
            q.pop();
            rep(h, 4) {
                ll di = i + dr[h], dj = j + dc[h];
                if(0 <= di and di < r and 0 <= dj and dj < c and D[di][dj] > D[i][j] + 1) {
                    q.push({di, dj}); 
                    D[di][dj] = D[i][j] + 1;
                }
            }
        }
        
        ll D2[r][c];
        rep(i, r) rep(j, c) D2[i][j] = 1e7;
        rep(i, r) rep(j, c) if(mat[i][j] == 'x' and D[i][j] > k) {
            q.push({i, j});
            D2[i][j] = 0;
        }
        while(!q.empty()) {
            ll i = q.front().ff, j = q.front().ss; 
            q.pop();
            // if(D2[i][j] == k) continue;
            rep(h, 4) {
                ll di = i + dr[h], dj = j + dc[h];
                if(0 <= di and di < r and 0 <= dj and dj < c and mat[di][dj] == 'x' and D2[di][dj] > D2[i][j] + 1) {
                    q.push({di, dj}); 
                    D2[di][dj] = D2[i][j] + 1;
                }
            }
        }

        bool pos = 1;
        rep(i, r) rep(j, c) if(mat[i][j] == 'x' and D2[i][j] > k) {
            pos = 0;
        }
        cout<<(pos? "YES\n": "NO\n");

    }





    return 0;
}