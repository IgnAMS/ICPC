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

vector<vl> G;
vl D;
int n, k;

int poscase = 0;
void dfs1(int u, int p, int d) {
    D[u] = d;
    for(auto v: G[u]) {
        // cout<<u<<' '<<v<<' '<<D[u]<<' '<<D[v]<<'\n';
        // Si encuentro un ciclo de largo k entonces estoy listo
        if(D[v] != -1 and D[v] < D[u] and D[v] + k - 1 == D[u] and poscase != -1) {
            poscase = 1;
        }
        // Si encuentro un ciclo de largo diferente a k entonces estoy muerto
        if(D[v] != -1 and p != v and D[v] < D[u] and D[v] + k - 1 != D[u]) {
            // cout<<"entre con "<<u<<' '<<v<<'\n';
            poscase = -1;
        }
        if(D[v] == -1) dfs1(v, u, d + 1);
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        cin>>n>>k;
        vl A(n); rep(i, n) cin>>A[i];
        bool pos = 1;
        rep(i, n) A[i]--;
        if(k == 1) {
            rep(i, n) if(A[i] != i) pos = 0;
        }
        else {
            G.assign(n, vl()); D.assign(n, -1);
            rep(i, n) {          
                G[A[i]].pb(i);
                G[i].pb(A[i]);
                if(A[i] == i) pos = 0;
            }
            rep(i, n) if(D[i] == -1) {
                poscase = 0;
                dfs1(i, -1, 0);
                if(poscase != 1) pos = 0;
            }
        }
        if(pos) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}