#pragma GCC optimize("Ofast")
#include<vector>
#include<iostream>
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
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txtß

const int mxN = 5e5+5;
int V[mxN];
vl G[mxN];

void dfs(int u) {
    V[u] = 1;
    for(auto v: G[u]) if(!V[v]) {
        dfs(v);
    }
}



void solve(int caso) {
    int n; cin>>n;
    vl A(n); rep(i, n) cin>>A[i];

    ll l = 0, r = 1e9+2;
    while(l < r) {
        ll m = (l + r) / 2;

        rep(i, n + 1) {
            G[i].clear();
            V[i] = 0;
        }

        rep(i, n) {
            if(i + 1 < n and abs(A[i] - A[i + 1]) <= m) {
                G[i].pb(i + 1);
                G[i + 1].pb(i);
            }
            if(A[i] <= m) {
                G[i].pb(n);
                G[n].pb(i);
            }
        }
        dfs(n);
        ll cont = 0;
        rep(i, n) cont += V[i];
        // cout<<m<<" "<<cont<<endl;
        if(cont == n) r = m;
        else l = m + 1;
    }
    cout<<"Case #"<<caso + 1<<": "<<l<<"\n";
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t; 
    rep(i, t) solve(i);
    return 0;
}