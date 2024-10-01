#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef int ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt


// 2*10^5, 2*10^5, 2*10^5, 4*10^5
vl D, L;
vl ID;
vector<vl> G;
vector<vl> G2;
vl tam;
bool primera;

vl Ans;
bool badind = 0;

stack<pll> S;
void dfs(int u, int p, int d) {
    D[u] = L[u] = d;
    for(int v : G[u]) if (v != p) {
        if (D[v] == -1) {
            S.emplace(u, v); dfs(v, u, d + 1);
            if (p == -1 or L[v] >= d) {
                // Componente biconexa encontrada
                ll cont = 0;
                while (1) {
                    pll e = S.top(); S.pop();
                    if(!primera) {
                        // cout<<"ciclo: "<<e.ss<<' '<<e.ff<<'\n';
                        ID[e.ss] = ID.size();
                        ID[e.ff] = ID.size();
                        cont++;
                    }
                    else {
                        if(ID[e.ff] < G2.size() and ID[e.ss] < G2.size()) {
                            G2[ID[e.ff]].pb(ID[e.ss]);
                            G2[ID[e.ss]].pb(ID[e.ff]);
                        }
                        else {
                            cout<<"estoy indexando mal con ";-
                            rep(i, G.size()) {
                                for(auto u: G[i]) cout<<"("<<u<<"), "; 
                                cout<<'\n';
                            }
                            badind = 1;
                            return;
                        }
                    }
                    if (e.ff == u and e.ss == v) break;
                }
                
                if(!primera) {
                    G2.pb(vl());
                    ID.pb(ID.size());
                    tam.pb(cont);
                    primera = 1;
                }
            }
            L[u] = min(L[u], L[v]); 
        }+
        else if (D[v] < d) { S.emplace(u, v); L[u] = min(L[u], D[v]); }
    }
}

ll contar(ll u, ll p) {
    ll ans = 1;
    for(auto v: G2[u]) if(v != p) ans += contar(v, u);
    return ans;
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n, k; cin>>n>>k;
        vl A(n); rep(i, n) cin>>A[i];
        rep(i, n) A[i]--;

        bool pos = 1;
        if(k == 1) {
            rep(i, n) if(A[i] != i) pos = 0; 
        }
        else {
            D.assign(n, -1); L.assign(n, 0); G.assign(n, vl());
            rep(i, n) {
                G[A[i]].pb(i);
                G[i].pb(A[i]);
                if(A[i] == i) pos = 0;
            }
            
            if(pos == 0) {
                Ans.pb(0);
                continue;
            }

            ID.assign(n, 0); rep(i, n) ID[i] = i;
            G2.assign(n, vl()); tam.clear();

            rep(i, n) {
                primera = 0;
                if(D[i] == -1) dfs(i, -1, 0);
                if(badind) return 0;
            }

            if(G2.size() == n) pos = 0;
            repx(i, n, G2.size()) {
                for(auto v: G2[i]) if(contar(v, i) % (k - 1) != 0) pos = 0;
                if(tam[i - n] % k != 0) pos = 0;
            }
        }

        if(pos) Ans.pb(1);
        else Ans.pb(0);
    }
    for(auto u: Ans) cout<<(u == 0? "NO\n": "YES\n");

    return 0;
}