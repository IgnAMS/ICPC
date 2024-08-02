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


int a[2], b[2], c[2];
ll V[1002][1002];
int n;

void dfs(ll i, ll j) {
    // cerr<<"visito "<<i<<' '<<j<<'\n';
    V[i][j] = 1;
    for(int di = i - 1; di <= i + 1; di++) if(0 <= di and di < n) {
        for(int dj = j - 1; dj <= j + 1; dj++) if(0 <= dj and dj < n) {
            if(di == a[0]) continue;
            if(dj == a[1]) continue;
            if(abs(di - a[0]) == abs(dj - a[1])) continue;
            if(!V[di][dj]) dfs(di, dj);
        }
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i, 2) cin>>a[i];
    rep(i, 2) cin>>b[i];
    rep(i, 2) cin>>c[i];
    // dfs(b[0], b[1]);
    bool ib = bool(b[0] <= a[0]), ic = bool(c[0] <= a[0]);
    bool jb = bool(b[1] <= a[1]), jc = bool(c[1] <= a[1]);
    if(ib == ic and jb == jc) cout<<"YES\n";
    else cout<<"NO\n";

    // if(V[c[0]][c[1]]) cout<<"YES\n";
    // else cout<<"NO\n";

    return 0;
}