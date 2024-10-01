#pragma GCC optimize("Ofast")
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

vector<vi> G;
vector<bool> V;
int comps;
void dfs(int u) {
    V[u] = 1;
    for(auto v: G[u]) if(!V[v]) { dfs(v); comps--; }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<ii> X(n); rep(i, n) cin>>X[i].ff>>X[i].ss;
    G.assign(n, {});
    rep(i, n) rep(j, n) if(i != j) {
        if(X[i].ff == X[j].ff or X[i].ss == X[j].ss) {
            G[i].push_back(j); G[j].push_back(i); 
        }
    }

    comps = n;
    V.assign(n, 0); 
    rep(i, n) if(!V[i]) dfs(i);
    cout<<comps - 1<<'\n';


    return 0;
}