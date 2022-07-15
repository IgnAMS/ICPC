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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, q; cin>>n>>m>>q;
    vector<vector<vi>> E(n); // posicion, type, val
    // type: 0 -> agregar, 1 -> query, 2 -> eliminar
    rep(i, m) {
        ll k, a, b; cin>>k>>a>>b; a--, b--;
        E[b - a].push_back({a, 0, 0});
        E[b - a].push_back({a + k - 1, 2, 0});
    }
    rep(i, q) {
        ll x, y; cin>>x>>y; x--, y--;
        if(y < x) swap(x, y);
        E[y - x].push_back({x, 1, i});
    }
    rep(i, n) sort(E[i].begin(), E[i].end());
    vi Ans(q);
    rep(i, n) {
        ll sum = 0;
        for(auto e: E[i]) {
            // cout<<e[0]<<' '<<e[1]<<' '<<e[2]<<'\n';
            if(e[1] == 0) sum++;
            else if(e[1] == 2) sum--;
            else Ans[e[2]] = sum % 2;
        }
    }
    rep(i, q) cout<<(Ans[i]? "SI": "NO")<<'\n';

    return 0;
}