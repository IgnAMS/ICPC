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


struct Node {
    map<int, int> F;
    int mx;
    ll sum;
    Node(): mx(0), sum(0) {}
    Node(int col) {
        mx = 1;
        sum = col;
        F[col] = 1;
    }

    void merge(Node &A) {
        if(A.F.size() > F.size()) { // A.F siempre sera el mas pequeno
            mx = A.mx, sum = A.sum;
            swap(A.F, F);
        }
        for(auto [c, cont]: A.F) {
            F[c] += cont;
            if(F[c] > mx) mx = F[c], sum = c;
            else if(F[c] == mx) sum += c;
        }

    }
};


vector<bool> V;
vector<vi> G;
vi C;
vi Ans;

void dfs(int u, Node& P) {
    Node curr = Node(C[u]);
    V[u] = 1;
    for(auto v: G[u]) if(!V[v]) dfs(v, curr);
    Ans[u] = curr.sum;
    P.merge(curr);
}




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    G.assign(n, vi());
    V.assign(n, 0); C.resize(n); Ans.assign(n, 0);
    rep(i, n) cin>>C[i];
    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].push_back(v); G[v].push_back(u);
    }
    
    Node N;
    dfs(0, N);
    rep(i, n) cout<<Ans[i]<<' '; cout<<'\n';


    return 0;
}