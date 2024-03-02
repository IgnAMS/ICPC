#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i<(int)n; ++i)
#define ll long long
#define vl vector<ll>

const int mxN = 3e5+5;
vector<ll> adj[mxN];
ll n, a, b, cnt1 = 0, cnt2 = 0;
ll ans = 0;
bool flag = 0;


void check(int u, int p = -1){
    if(u == b){
        flag = 1;
        return;
    }
    for(int v : adj[u]){
        if(v != p){
            check(v, u);
        }
    }
}

void dfs(int u, int p = -1){
    cnt1++;
    for(int v : adj[u]){
        if(v != p){
            if(u == a){
                check(v, u);
            }
            if(flag == 0){
                dfs(v, u);
            }else{
                flag = 0;
            }
        }
        
    }
}
void check2(int u, int p = -1){
    if(u == a){
        flag = 1;
        return;
    }
    for(int v : adj[u]){
        if(v != p){
            check2(v, u);
        }
    }
}

void dfs2(int u, int p = -1){
    cnt2++;
    for(int v : adj[u]){
        if(v != p){
            if(u == b){
                check2(v, u);
            }
            if(flag == 0){
                dfs2(v, u);
            }else{
                flag = 0;
            }
        }
        
    }
}
/*
void dfs2(int u, int p = -1, ll cnt = 2){
    if(u != b){
        ans += cnt;
    }
    for(int v : adj[u]){
        if(v!=p){
            if(v == a){
                dfs2(v, u, cnt-1);
            }else{
                dfs2(v, u, cnt);
            }
        }
    }
}
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> a >> b, --a, --b;
    rep(i, n-1){
        int x, y;
        cin >> x >> y, --x, --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(a);
    flag = 0;
    dfs2(b);
    cout << n*(n-1) - cnt1*cnt2 << '\n';
}

