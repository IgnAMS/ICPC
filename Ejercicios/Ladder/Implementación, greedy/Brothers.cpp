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

ll dr[] = {1, -1, 0, 0};
ll dc[] = {0, 0, -1, 1};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, r, c, k;
    while(cin>>n>>r>>c>>k and n) {
        ll mat[r][c]; 
        rep(i, r) rep(j, c) cin>>mat[i][j];
        rep(_, k) {
            ll aux[r][c];
            rep(i, r) rep(j, c) aux[i][j] = mat[i][j];
            rep(i, r) rep(j, c) rep(h, 4){
                ll di = i + dr[h], dj = j + dc[h];
                if(0 <= di and di < r and 0 <= dj and dj < c and (mat[i][j] - mat[di][dj] == -1 or (mat[i][j] == n - 1 and mat[di][dj] == 0))) {
                    aux[di][dj] = mat[i][j];
                }
            } 
            rep(i, r) rep(j, c) mat[i][j] = aux[i][j];
        }
        rep(i, r) {
            rep(j, c) cout<<mat[i][j]<<" \n"[j == c - 1];
        }
    }


    return 0;
}