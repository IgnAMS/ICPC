#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second
typedef long long ll;
typedef pair<int,int> ii;

vector<int> D,L;
vector<set<int>> G;
stack<ii> S, O; 
vector<int> P; 

bool dfs(int u, int p, int d, bool c){
    D[u] = L[u] = d;
    P[u]=c; bool ans=false;
    for(int v : G[u]) if (v != p){
        if (D[v] == -1){
            S.emplace(u, v); 
            bool op=dfs(v, u, d + 1, !c);
            //encuentro el nodo "padre" de la bicomponente
            //guardo sus aristas para eventualmente sacarlas
            if (p == -1 or L[v] >= d) while (1){
                ii e = S.top(); S.pop();
                if(op) O.emplace(e);
                //if(op) cout<<e.ff<<" "<<e.ss<<"\n";
                if (e == make_pair(u, v)) break;
            }
            //debo buscar el nodo inicio mas arriba, le digo que debo sacarlo
            else ans|= op;
            L[u] = min(L[u], L[v]); 
        }
        else if (D[v] < d){
            S.emplace(u, v); L[u] = min(L[u], D[v]);
            //encuentro un ciclo impar
            if(P[u]==P[v]) ans=1;
        }
    }
    return ans;
}

int id=0;
void dfs(int u, vector<int>& C){
    C[u]=id;
    for(int v: G[u]) if(C[v]==-1) dfs(v,C);
}




int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin>>n>>m;
    G.resize(n);
    D.assign(n,-1); L.resize(n); P.resize(n);
    rep(i,m){
        int u,v; cin>>u>>v; u--,v--;
        G[u].insert(v); G[v].insert(u);
    }

    rep(u,n) if(D[u]==-1) dfs(u,-1,0,0);

    vector<int> C1(n,-1);
    id=0; rep(u,n) if(C1[u]==-1) ++id,dfs(u,C1);

    while(!O.empty()){
        ii e=O.top(); O.pop(); int u=e.ff, v=e.ss;
        G[u].erase(v); G[v].erase(u);
    } 

    vector<int> C2(n,-1);
    id=0; rep(u,n) if(C2[u]==-1) ++id,dfs(u,C2);
    
    int q; cin>>q;
    rep(i,q){
        int u,v; cin>>u>>v; u--,v--;
        if(C1[u]!=C1[v]) cout<<"No\n"; //no estuvieron en la misma componente
        else if(C2[u]!=C2[v]) cout<<"Yes\n"; //se separon
        else if(P[u]!=P[v]) cout<<"Yes\n"; //no se separararon, tenian un camino impar
        else cout<<"No\n"; //estaban unidas y tenian un camino par
    }

    return 0;
}