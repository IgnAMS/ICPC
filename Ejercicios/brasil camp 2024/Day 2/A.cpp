#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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



vl G[130];
vl mt;  
vector<bool> used;

bool dfs(int u) {
    if(used[u]) return 0;
    used[u] = 1;
    for(auto v: G[u]) if(mt[v] == -1 or dfs(mt[v])) {
        // cout<<"asigno a "<<u<<" con "<<v<<'\n';
        mt[v] = u;
        return 1;
    }
    return 0;
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    int n; cin>>n;
    vector<vector<char>> Cubes(n, vector<char>(6, 'a'));
    rep(i, n) {
        rep(j, 6) {
            cin>>Cubes[i][j];
            rep(k, s.length()) {
                if(s[k] == Cubes[i][j]) {
                    G[k].pb(i);
                    // G[i].pb(k);
                }
            }
        }
    }

    bool pos = 1;
    mt.assign(n, - 1);
    rep(i, s.size()) {
        used.assign(s.size(), 0);
        // cerr<<"probare con "<<i<<'\n';
        if(!dfs(i)) pos = 0;
    }

    cout<<(pos? "YES\n": "NO\n");



    return 0;
}