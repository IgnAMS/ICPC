#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define repx(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define rep(i, n) repx(i, 0, n)
#define pb push_back

const int mxN = 2005;
int a[mxN][mxN];

struct DSU{
    int p[mxN], sz[mxN];
    void init(){
        iota(p, p+mxN-1, 0);
        rep(i, mxN) sz[i] = 1;
    }
    int find_set(int x){
        if(x == p[x]) return x;
        return p[x] = find_set(p[x]);
    }
    bool unite(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a == b) return false;
        if(sz[a] < sz[b]) swap(a, b);
        sz[b] += sz[a];
        p[a] = b;
        return true;
    }
}dsu;


bool same(int a, int b){
    return dsu.find_set(a) == dsu.find_set(b);
}

void init(){
    dsu.init();
}

void solve(){
    init();
    int n;
    cin >> n;
    rep(i, n){
        rep(j, n){
            cin >> a[i][j], --a[i][j];
        }
    }
    vector<pair<int, int>> ans;
    rep(i, n){
        if(!same(a[i][0], a[i][1])){
            ans.push_back({a[i][0], a[i][1]});
            dsu.unite(a[i][0], a[i][1]);
        }
    }
    for(int i = 2; i<n; ++i){
        if(!same(a[0][0], a[0][i])){
            int s1 = dsu.find_set(a[0][0]);
            for(int j = 1; j<n; ++j){
                if(dsu.find_set(a[a[0][i]][j]) == s1){
                    ans.push_back({a[0][i], a[a[0][i]][j]});
                    dsu.unite(a[0][i], a[a[0][i]][j]);
                    break;
                }
            }
        }
    }
    for(auto val : ans){
        cout << val.first+1 << " " << val.second+1 << " \n";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}

