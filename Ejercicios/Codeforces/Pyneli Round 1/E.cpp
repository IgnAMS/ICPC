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

const ll mxN = 4005;

string mat[mxN];
vl C[mxN], Leaf[mxN];
ll V[mxN], P[mxN], D[mxN], L[mxN];
int n;


int rc = 0;
ll ind = 0;

void dfs(ll u, int p = -1, int d = 0) {
    V[u] = ind;
    ll aux = u;
    C[ind].pb(u);
    D[u] = L[u] = d;
    bool articulation = 0;
    rep(v, n) if(mat[u][v] == '1' and v != p) {
        if(V[v] == -1) {
            dfs(v, u, d + 1);
            if((p == 1 and ++rc == 2) or (p != -1 and L[v] >= d)) {
                articulation = 1;
            }
            L[u] = min(L[u], L[v]); 
        }
        else if (D[v] < d) L[u] = min(L[u], D[v]);
    }
    if(!articulation) Leaf[ind].pb(u);
}

ll check2(ll comp) {
    for(auto u: C[comp]) {
        for(auto v: C[comp]) if(u != v  and mat[u][v] == '0') return u;
    }
    // Si es una componente completa
    return -1;
}

ll getP(ll comp) {
    for(auto u: Leaf[comp]) {
        for(auto v: C[comp]) if(u != v and mat[u][v] == '0') return u;
    }
    return -1;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        cin>>n;
        rep(i, n) {
            C[i].clear();
            Leaf[i].clear();
            V[i] = -1;
        }
        
        rep(i, n) cin>>mat[i];

        ind = 0, rc = 0;
        vl Ans;
        ll mn = 0;
        rep(u, n) if(V[u] == -1) {
            dfs(u);
            if(Ans.size() == 0 and check2(ind) != -1) Ans.pb(getP(ind));
            if(C[ind].size() < C[mn].size()) mn = ind;

            ind++;
        }

        // Hay solo una componente por lo que es 0
        if(ind == 1) { 
            cout<<"0\n";
            continue;
        }
        // Hay al menos una componente qeu no es un clique y lo uso
        if(Ans.size() == 1) {
            cout<<"1\n";
            cout<<Ans[0] + 1<<'\n';
            continue;
        }

        if(C[mn].size() <= 2 or ind == 2) {
            // Hay mas de un clique, entonces uso el minimo clique
            cout<<C[mn].size()<<'\n';
            sort(C[mn].begin(), C[mn].end());
            for(auto u: C[mn]) cout<<u + 1<<' '; cout<<'\n';
        }
        else {
            // tengo 3 o mas componenetes y cada son cliques mayores o iguales a 3
            cout<<2<<'\n';
            cout<<1<<' ';
            rep(i, n) if(V[i] != V[0]) {
                cout<<i + 1<<'\n';
                break;
            }
        }

        
    }



    return 0;
}