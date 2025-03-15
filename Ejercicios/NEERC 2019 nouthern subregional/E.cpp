#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

using namespace std;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
typedef long long ll;
typedef pair<ll, ll> pll;

// g++ -O2 A.cpp && time ./a.out <input.txt> output.txt

const int mxN = 2e5+5;

int n, m, marked[mxN], pp[mxN];
vector<int> adj[mxN];
vector<int> path;
set<int> ss;

pair<int, int> mx = {-1, -1};

void dfs1(int u, int p = -1, int dis = 0){
    if(marked[u]){
        mx = max(mx, {dis, u});
    }
    pp[u] = p;
    for(int v : adj[u]){
        if(v == p) continue;
        dfs1(v, u, dis+1);
    } 
    path.pop_back();
}

void dfs2(int u, int p = -1, int dis = 0){
    if(marked[u]) ss.insert(dis);
    for(int v : adj[u]){
        if(v == p) continue;
        dfs2(v, u, dis+1);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    rep(i, n-1){
        int a, b;
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }   
    vector<int> vv(m); 
    memset(marked, 0, sizeof(marked));
    rep(i, m){
        cin >> vv[i], --vv[i];
        if(i) marked[vv[i]] = 1;
    }
    if(m == 1){
        cout << "YES\n" << vv[0]+1 << "\n";
        return 0;
    }
    dfs1(vv[0]);
    marked[vv[0]] = 1;
    for(int i = 0; i<mx.first/2; ++i){
        mx.second = pp[mx.second];
    }
    dfs2(mx.second);
    // for(int val : path){
    //     cout << val << " ";
    // }
    // for(int val : ss){
    //     cout << val << " ";
    // }
    // cout << "\n";
    if(ss.size() == 1){
        cout << "YES\n" << mx.second+1 << "\n";
    }else{
        cout << "NO\n";
    }
}


