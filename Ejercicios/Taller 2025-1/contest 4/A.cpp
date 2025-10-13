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

pll dir[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    string s[n];
    pll start, finish;
    rep(i, n) {
        cin>>s[i];    
        rep(j, m) {
            if(s[i][j] == 'A') start = {i, j};
            if(s[i][j] == 'B') finish = {i, j};
        }
    }

    deque<pll> q = {start};
    vector<vl> D(n, vl(m, -1));
    D[start.ff][start.ss] = 0;
    while(!q.empty()) {
        auto [i, j] = q.front(); q.pop_front();
        for(auto d: dir) {
            int di = i + d.ff, dj = j + d.ss;
            if(0 <= di and di < n and 0 <= dj and dj < m and s[di][dj] != '#' and D[di][dj] == -1) {
                D[di][dj] = D[i][j] + 1;
                q.push_back({di, dj});
            } 
        }
    }

    cout<<D[finish.ff][finish.ss]<<'\n';

    return 0;
}