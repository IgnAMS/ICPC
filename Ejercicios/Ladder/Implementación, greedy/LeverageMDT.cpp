#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    char mat[n][m]; rep(i, n) rep(j, m) cin>>mat[i][j];
    vector<vi> L(n, vi(m, 0)), R(n, vi(m, 0));
    rep(i, n) {
        vi A; ll cont = 1;
        repx(j, 1, m) {
            if(mat[i][j] == mat[i][j-1]) cont++;
            else { A.push_back(cont); cont = 1; }
        }
        A.push_back(cont);
        ll x = 0;
        for(auto u: A){
            rep(j, u) L[i][x + j] = j + 1, R[i][x + j] = u - j;
            x += u; 
        }
    }
    ll ans = 0;
    rep(i, m){ // itero columna por columna
        vi S; 
        vi Li(n), Ri(n); rep(i, n) Li[i] = i, Ri[i] = i;
        rep(j, n){
            while(!S.empty() and R[S.back()][i] >= R[j][i]) { Li[j] = Li[S.back()]; S.pop_back(); }
            S.push_back(j);
        }
        S.clear();
        rep(j, n){
            while(!S.empty() and R[S.back()][i] >= R[n - j - 1][i]) { Ri[n - j - 1] = Ri[S.back()]; S.pop_back(); }
            S.push_back(n - j - 1);
        }
        rep(j, n) ans = max(ans, min(R[j][i], Ri[j] - Li[j] + 1));
    }
    cout<<ans * ans<<'\n';






    return 0;
}