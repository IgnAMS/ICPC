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

pll dir[] = {{1, 0}, {0, 1}};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    // hay 3 opciones, poner 2, 1 o 0
    // poner 2 es el default, es facil evaluar poner 0 ya que es solo el bfs
    // hay que ver como podemos evaluar el 1, para eso, debe haber un punto de articulacion 

    int n, m; cin>>n>>m;
    string s[n]; rep(i, n) cin>>s[i];

    deque<pll> q = {{0, 0}};
    pll P[n][m];
    vector<vl> D(n, vl(m, -1));
    D[0][0] = 0;
    while(!q.empty()) {
        auto [i, j] = q.front(); q.pop_front();
        for(auto d: dir) {
            int di = i + d.ff, dj = j + d.ss;
            if(0 <= di and di < n and 0 <= dj and dj < m and s[di][dj] != '#' and D[di][dj] == -1) {
                D[di][dj] = D[i][j] + 1;
                P[di][dj] = {i, j};
                q.push_back({di, dj});
            }
        }
    }
    if(D[n - 1][m - 1] == -1) {
        cout<<0<<'\n';
        return 0;
    }
    
    // bloqueo el camino encontrado
    pll x = {n - 1, m - 1};
    vector<pll> X;
    while(x.ff != 0 or x.ss != 0) {
        x = P[x.ff][x.ss];
        X.push_back(x);
    }
    X.pop_back();
    for(auto [i, j]: X) s[i][j] = '#';

    // vuelvo a hacer BFS
    D.assign(n, vl(m, -1));
    D[0][0] = 0;
    q = {{0, 0}};
    while(!q.empty()) {
        auto [i, j] = q.front(); q.pop_front();
        for(auto d: dir) {
            int di = i + d.ff, dj = j + d.ss;
            if(0 <= di and di < n and 0 <= dj and dj < m and s[di][dj] != '#' and D[di][dj] == -1) {
                D[di][dj] = D[i][j] + 1;
                q.push_back({di, dj});
            }
        }
    }
    if(D[n - 1][m - 1] == -1) cout<<1<<'\n';
    else cout<<2<<'\n';


    return 0;
}