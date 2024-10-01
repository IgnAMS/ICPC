#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define ss second
#define ff first
#define rep(i,n) for(int i=0;i<n;i++) 

vector<vii> G;
vector<vector<int>> D;

void add_edge(int u, int e, int p){
    for(auto &v: G[u]) if(v.ff!=p)
        //si v es vecino de e entonces lo agrego
        if(D[v.ff][u]+ v.ss ==D[u][e]) {add_edge(v.ff, e, u); return;}
    //no es vecino, por ende lo agrego
    G[u].emplace_back(e,D[u][e]);
    G[e].emplace_back(u,D[u][e]);
}

bool check(int s, int u, int p, int d){
    //s es el nodo root, u es el nodo al que estoy visitando
    //p es el nodo parent, d es la distancia
    if(D[s][u]!=d) return false;
    for(auto &v: G[u]) if(v.ff!= p)
        if(!check(s,v.ff,u,d+v.ss)) return false;
    return true;
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    G.assign(n,{});
    D.assign(n,vector<int>(n));
    rep(i,n) rep(j,n) cin>>D[i][j];
    bool flag=true;
    //reviso que sean simetricas
    //reviso que las dist != 0
    rep(i,n) rep(j,n) if((D[j][i]!=D[i][j]) || (i!=j && D[i][j]==0))
        flag=false;
    //reviso que las diagonales sean 0
    rep(i,n) if(D[i][i]!=0)
        flag=false;

    if(!flag) {cout<<"NO\n"; return 0;}
    
    vii v;
    rep(i,n) if(i) v.emplace_back(D[0][i],i);
    sort(v.begin(),v.end());

    for(auto &e: v) add_edge(0,e.ss,-1);
    
    rep(i,n) if(!check(i,i,-1,0)) {cout<<"NO\n"; return 0;}



    return 0;
}