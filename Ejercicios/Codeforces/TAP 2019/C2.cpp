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
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

ll mat[2000][2000];
ll V[2000][2000];
int n, m;

bool check(int i, int j) {
    if(j == 0 or j == m - 1) return false;
    if(i and mat[i - 1][j]) return false;
    // cerr<<i<<' '<<j<<'\n';
    ll u = 0, d = 0, l = 0, r = 0;
    repx(k, i, n) {
        if(!mat[k][j]) return false;
        V[k][j] = 1;
        if(mat[k][j - 1] and mat[k][j + 1]) { u = k - i; break; }
        if(mat[k][j - 1] or mat[k][j + 1]) return false;
    }
    // cerr<<"pase por el primer for!"<<' '<<u<<"\n";
    // no paro nunca o llega hasta el final o lo encuentra al inicio
    if(!u or i + u == n - 1) return false;
    repx(k, j + 1, m) {
        if(!mat[i + u][k]) { r = k - j - 1; break; }
        V[i + u][k] = 1;
        if(mat[i + u + 1][k] or mat[i + u - 1][k]) return false;
        if(k == m - 1) r = k - j;
    }
    // cerr<<"pase por el segundo for!"<<' '<<r<<"\n";
    for(int k = j - 1; k >= 0; k--) {
        if(!mat[i + u][k]) { l = j - k - 1; break; }
        V[i + u][k] = 1;
        if(mat[i + u + 1][k] or mat[i + u - 1][k]) return false;
        if(k == 0) l = j - k;
    }
    // cerr<<"pase por el tercer for!"<<' '<<l<<"\n";
    repx(k, i + u + 1, n) {
        if(!mat[k][j]) { d = k - (i + u) - 1; break; }
        V[k][j] = 1;
        if(mat[k][j + 1] or mat[k][j - 1]) return false;
        if(k == n - 1) d = k - (i + u);
    }
    // cerr<<"pase por el quinto for!"<<' '<<d<<"\n";
    // cerr<<i<<' '<<j<<": "<<u<<' '<<d<<' '<<l<<' '<<r<<'\n';
    if(u == l and u == r and u < d) return true;
    return false;
}




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i, n) {
        string s; cin>>s;
        rep(j, m) mat[i][j] = s[j] == '*';
    }
    rep(i, n) rep(j, m) V[i][j] = 0;
    ll ans = 0;
    rep(i, n) rep(j, m) if(mat[i][j] and !V[i][j]) ans += check(i, j);
    cout<<ans<<'\n';


    return 0;
}