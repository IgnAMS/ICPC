#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<int> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int n;
vi P, D, MxD;
vector<vi> G;
vector<vi> Path;

int dfs(int u, int d, int p) {
    P[u] = p;
    D[u] = d;
    if(p != -1) Path[u] = Path[p];
    Path[u].push_back(u);
    MxD[u] = d; 
    for(auto v: G[u]) if(v != p) MxD[u] = max(MxD[u], dfs(v, d + 1, u));
    return MxD[u];
}

vector<vi> UP, DO;

void setUp() {
    UP.resize(n); DO.resize(n);
    rep(u, n) UP[u].assign(D[u] + 1, 0);
    rep(u, n) DO[u].assign(D[u] + 1, 0);

    vi X(n);
    repx(u, 1, n) {
        int mx = D[u] - 1;
        for(auto v: G[P[u]]) if(v != u and v != P[P[u]]) {
            mx = max(mx, MxD[v]);
        }
        X[u] = mx;
    }
    // nivel d
    rep(u, n) {
        int v = u;
        UP[u][0] = MxD[u] - D[u];
        repx(d, 1, D[u] + 1) {
            UP[u][d] = max(UP[u][d - 1], X[v] - (D[v] - 1) + d);
            v = P[v];
        }
        DO[u][0] = 0;
        repx(d, 1, D[u] + 1) {
            v = Path[u][d];
            // cout<<u<<' '<<d<<' '<<v<<' '<<X[v]<<'\n';
            DO[u][d] = max(DO[u][d - 1], X[v]);
        }
    }
}




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {    
        cin>>n;
        G.assign(n, vi()); D.assign(n, 0); P.assign(n, -1);
        rep(i, n - 1) {
            int u, v; cin>>u>>v; u--, v--;
            G[u].push_back(v); G[v].push_back(u);
        }
        MxD.resize(n); Path.assign(n, vi());
        dfs(0, 0, -1);
        setUp();

        vi Ans(n);
        repx(x, 1, n + 1) {
            int ans = MxD[0];
            rep(u, n) if(D[u] > x) {
                int r = D[u] - (D[u] + x + 1) / 2;
                // cout<<"u, r, x: "<<u<<' '<<r<<' '<<x<<'\n'; 
                // cout<<UP[u][r] + x<<' '<<DO[u][D[u] - r]<<'\n';
                // cout<<'\n';
                ans = min(ans, max(UP[u][r] + x, DO[u][D[u] - r]));
            }
            Ans[x - 1] = ans;
        }
        rep(i, n) cout<<Ans[i]<<' '; cout<<'\n';
        
    }
    
    
    

    return 0;
}