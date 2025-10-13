#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int, int> pll;
typedef double db;
typedef vector<int> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin>>n>>m>>k;
    string s[n];
    rep(i, n) cin>>s[i];

    set<ll> R[n], C[m];
    rep(i, n) rep(j, m) {
        if(s[i][j] == '.') {
            R[i].insert(j), C[j].insert(i);
        }
        else {
            R[i].insert(j), C[j].insert(i);
        }
    }
    rep(i, n) R[i].insert(-1005);
    rep(i, m) C[i].insert(-1005);

    pll start, finish;
    cin>>start.ff>>start.ss>>finish.ff>>finish.ss;
    start.ff--, start.ss--, finish.ff--, finish.ss--;

    deque<pll> q;
    q.push_back(start);
    R[start.ff].erase(start.ss);
    C[start.ss].erase(start.ff);
    
    int D[n][m];
    rep(i, n) rep(j, m) D[i][j] = 1e8;

    D[start.ff][start.ss] = 0;

    while(!q.empty()) {
        auto [i, j] = q.front(); q.pop_front();
        vector<pll> erase;
        for(auto it = R[i].lower_bound(j); it != R[i].end() and *it <= j + k and s[i][*it] != '#'; it++) {
            erase.pb({i, *it});
        }
        for(auto it = prev(R[i].lower_bound(j)); *it >= j - k and s[i][*it] != '#'; it--) {
            erase.pb({i, *it});
        }

        for(auto it = C[j].lower_bound(i); it != C[j].end() and *it <= i + k and s[*it][j] != '#'; it++) {
            erase.pb({*it, j});
        }
        for(auto it = prev(C[j].lower_bound(i)); *it >= i - k and s[*it][j] != '#'; it--) {
            erase.pb({*it, j});
        }

        for(auto [a, b]: erase) {
            R[a].erase(b);
            C[b].erase(a);
            
            D[a][b] = D[i][j] + 1;
            q.push_back({a, b});
        }
    }
    if(D[finish.ff][finish.ss] == 1e8) cout<<"-1\n";
    else cout<<D[finish.ff][finish.ss]<<'\n';

    return 0;
}