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


int dc[] = {1, -1, 0, 0};
int dr[] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n = 8;
    db Mat[101][n][n];
    db Ans[n][n];
    rep(i, n) rep(j, n) Ans[i][j] = 1;
    int k; cin>>k;
    rep(i, n) rep(j, n) {
        rep(l, k + 1) rep(i1, n) rep(j1, n) Mat[l][i1][j1] = 0;
        Mat[0][i][j] = 1;
        rep(l, k) {
            rep(i1, n) rep(j1, n) {
                db vecinos = 0;
                rep(h, 4) {
                    int di = i1 + dr[h], dj = j1 + dc[h];
                    if(0 <= di and di < 8 and 0 <= dj and dj < 8) vecinos += 1;
                }
                rep(h, 4) {
                    int di = i1 + dr[h], dj = j1 + dc[h];
                    if(0 <= di and di < 8 and 0 <= dj and dj < 8) {
                        Mat[l + 1][di][dj] += Mat[l][i1][j1] / vecinos;
                    }
                }
            }
        }
        rep(i1, n) rep(j1, n) Ans[i1][j1] *= (1LL - Mat[k][i1][j1]);
    }
    
    db ans = 0;
    rep(i, n) rep(j, n) ans += Ans[i][j];
    
    cout<<setprecision(6)<<fixed<<ans<<'\n';


    return 0;
}