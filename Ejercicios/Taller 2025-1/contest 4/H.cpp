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


pll dir[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve() {
    int n, m; cin>>n>>m;
    string s[n];
    pll lab;
    rep(i, n) {
        cin>>s[i];
        rep(j, m) if(s[i][j] == 'L') lab = {i, j};
    }

    deque<pll> q = {lab};
    vector<vl> D(n, vl(m, 0));
    vector<vl> V(n, vl(m, 0));
    rep(i, n) rep(j, m) if(s[i][j] == '.') {
        for(auto d: dir) {
            int di = i + d.ff, dj = j + d.ss;
            if(0 <= di and di < n and 0 <= dj and dj < m and s[di][dj] == '.') 
                D[i][j]++;
        }
    }
    D[lab.ff][lab.ss] = 0;

    while(!q.empty()) {
        auto [i, j] = q.front(); q.pop_front();
        ll cont = 0;
        D[i][j] = 0;
        V[i][j] = 1;

        for(auto d: dir) {
            int di = i + d.ff, dj = j + d.ss;
            if(0 <= di and di < n and 0 <= dj and dj < m and s[di][dj] == '.') {
                if(s[i][j] != 'L') D[di][dj] -= 1;
                if(D[di][dj] <= 1 and !V[di][dj]) {
                    q.push_back({di, dj});
                    V[di][dj] = 1;
                }
            }
        }
    }
    D[lab.ff][lab.ss] = 2;
    rep(i, n) rep(j, m) if(D[i][j] <= 1 and V[i][j]) s[i][j] = '+';
    rep(i, n) cout<<s[i]<<'\n';
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        solve();
    }

    return 0;
}