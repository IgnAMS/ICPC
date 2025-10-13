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
            if(s[i][j] == 'E') finish = {i, j};
            if(s[i][j] == 'S') start = {i, j};
        }
    }
    
    deque<pll> q = {start};
    vector<vl> D(n, vl(m, 1e7));
    D[start.ff][start.ss] = 0;
    while(!q.empty()) {
        auto [i, j] = q.front(); q.pop_front();
        for(auto d: dir) {
            int di = i + d.ff, dj = j + d.ss;
            if(0 <= di and di < n and 0 <= dj and dj < m and s[di][dj] != 'T' and D[di][dj] == 1e7) {
                D[di][dj] = D[i][j] + 1;
                q.push_back({di, dj});
            }
        }
    }
    
    vector<vl> D2(n, vl(m, 1e7));
    D2[finish.ff][finish.ss] = 0;
    q = {finish};
    while(!q.empty()) {
        auto [i, j] = q.front(); q.pop_front();
        for(auto d: dir) {
            int di = i + d.ff, dj = j + d.ss;
            if(0 <= di and di < n and 0 <= dj and dj < m and s[di][dj] != 'T' and D2[di][dj] == 1e7) {
                D2[di][dj] = D2[i][j] + 1;
                q.push_back({di, dj});
            }
        }
    }



    ll dist = D[finish.ff][finish.ss];
    ll ans = 0;
    set<ll> digits;
    rep(i, 10) digits.insert(i);
    rep(i, n) rep(j, m) {
        // cout<<s[i][j]<<' '<<D[i][j]<<' '<<dist<<'\n';
        if(digits.count(s[i][j] - '0') and D2[i][j] <= dist) {
            ans += s[i][j] - '0';
        }
    }
    cout<<ans<<'\n';


    return 0;
}