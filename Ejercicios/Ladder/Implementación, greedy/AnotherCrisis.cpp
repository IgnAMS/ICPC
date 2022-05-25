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

vector<vi> G;
vector<bool> V;
int T;
ll dfs(int u, int p) {
    if(G[u].size() == 1 and u != 0) return 1;
    vi L;
    for(auto v: G[u]) if(v != p) {
        L.push_back(dfs(v, u));
    }
    sort(L.begin(), L.end());
    ll acc = 0;
    rep(i, (T * L.size() + 99) / 100) acc += L[i];
    return acc;
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin>>n>>T and n) {
        G.assign(n + 1, vi());
        rep(i, n) {
            int u; cin>>u;
            G[i + 1].push_back(u);
            G[u].push_back(i + 1);
        }
        cout<<dfs(0, -1)<<'\n';
    }
    return 0;
}