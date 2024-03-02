#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define rep(i, n) for(int i = 0; i<(int)n; ++i)
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define ff first
#define ss second

ll const N = 1e3 + 2;

bool vis[N][N], f[N][N];
int mark1[N][N], mark2[N][N], mark3[N][N], mark4[N][N];

bool D[N][N][4]; // 0: up, 1: right, 2: down, 3: left
pll dir[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};


int main(){
    ll n;
    cin >> n;

    vector<pll> d;
    rep(i, n+1){
        ll x, y, x2, y2;
        cin >> x >> y;
        d.push_back({x, y});
        if(i > 0){
            x2 = d[i-1].first;
            y2 = d[i-1].second;

            if(x == x2){ // segmento vertical
                if(y2 < y) swap(y, y2);

                for(int j = y; j < y2; j++){
                    D[x-1][j][2] = 1;
                    D[x][j][0] = 1;
                }
            }
            else{
                if(x2 < x) swap(x, x2);
                for(int j = x; j < x2; j++){
                    D[j][y-1][1] = 1;
                    D[j][y][3] = 1;
                }
            }

        }
    }


    queue<pll> q;
    q.push({0, 0});
    while(!q.empty()){
        ll x, y;
        tie(x, y) = q.front();
        q.pop();
        if(vis[x][y])continue;
        vis[x][y] = 1;
        
        rep(i, 4) {
            auto d = dir[i];
            ll nx = x + d.ff, ny = y + d.ss;
            if(0 <= nx and nx < N and 0 <= ny and ny < N and !D[x][y][i]) q.push({nx, ny});
        }
    }
    ll ans = 0;
    rep(i, N){
        rep(j, N){
            int aux = 0;
            if(vis[i][j]) continue;
            q.push({i, j});
            while(!q.empty()){
                ll x, y;
                tie(x, y) = q.front();
                q.pop();
                if(vis[x][y])continue;
                aux++;
                vis[x][y] = 1;

                rep(i, 4) {
                    auto d = dir[i];
                    ll nx = x + d.ff, ny = y + d.ss;
                    if(0 <= nx and nx < N and 0 <= ny and ny < N and !D[x][y][i]) q.push({nx, ny});
                }
            }
            if(aux > ans) ans = aux;
        }
    }
    cout << ans << "\n";
}