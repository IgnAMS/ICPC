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


//         N   S  E  W
ll dr[] = {-1, 1, 0, 0};
ll dc[] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int w, h; cin>>w>>h;
    string mapa[h];
    rep(i, h) cin>>mapa[i];
    string commands; cin>>commands;

    map<char, int> mp;
    mp['N'] = 0, mp['S'] = 1, mp['E'] = 2, mp['W'] = 3;

    pll init;
    rep(i, h) rep(j, w) if(mapa[i][j] == 'S') init = {i, j};

    ll D1[h][w];
    rep(i, h) rep(j, w) D1[i][j] = 1000000000LL;
    deque<pll> q; q.push_back(init);
    D1[init.ff][init.ss] = 0;
    while(!q.empty()) {
        int i, j; tie(i, j) = q.front(); q.pop_front();
        rep(k, 4) {
            int di = i + dr[k], dj = j + dc[k];
            if(0 <= di and di < h and 0 <= dj and dj < w and mapa[di][dj] != '#' and D1[di][dj] > D1[i][j] + 1) {
                D1[di][dj] = D1[i][j] + 1;
                q.push_back({di, dj});
            }
        }
    }

    ll D2[h][w];
    rep(i, h) rep(j, w) D2[i][j] = 1000000000LL;
    q.push_back(init);
    D2[init.ff][init.ss] = 0;
    while(!q.empty()) {
        int i, j; tie(i, j) = q.front(); q.pop_front();
        if(D2[i][j] >= commands.length()) continue;

        rep(k, 4) if(k != mp[commands[D2[i][j]]]) {
            int di = i + dr[k], dj = j + dc[k];
            if(0 <= di and di < h and 0 <= dj and dj < w and mapa[di][dj] != '#' and D2[di][dj] > D2[i][j] + 1 and D1[di][dj] == D2[i][j] + 1) {
                D2[di][dj] = D2[i][j] + 1;
                q.push_back({di, dj});
            }
        }
    }

    rep(i, h) rep(j, w) if(D2[i][j] == commands.length()) mapa[i][j] = '!';
    rep(i, h) cout<<mapa[i]<<'\n';



    return 0;
}