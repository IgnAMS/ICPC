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

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    int A[n][m];
    rep(i, n) rep(j, m) cin>>A[i][j];
    
    int ans = 1;
    int V[n][m];
    rep(i, n) rep(j, m) {
        priority_queue<array<int, 3>> pq;
        rep(a, n) rep(b, m) V[a][b] = 0;
        pq.push({-A[i][j], i, j});
        V[i][j] = 0;
        int curr = 0;
        while(!pq.empty()) {
            auto [x, i, j] = pq.top(); pq.pop();
            x *= -1;
            curr++;
            rep(h, 4) {
                int di = i + dr[h], dj = j + dc[h];
                if(0 <= di and di < n and 0 <= dj and dj < m and A[di][dj] > x and !V[di][dj]) {
                    pq.push({-A[di][dj], di, dj});
                    V[di][dj] = 1;
                }
            }
        }
        // cout<<"partiendo desde "<<i<<' '<<j<<" puedo recolectar "<<curr<<'\n';
        ans = max(ans, curr);
    }
    cout<<ans<<'\n';

    return 0;
}