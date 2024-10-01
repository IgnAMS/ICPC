#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;

bool debil(int u, set<int>& S){
    return !S.empty() and *S.begin() > u; 
}


void printeo(set<int>& S){
    for(auto& u: S) cerr<<u<<' '; cerr<<'\n';
}

int main(){
    int n, m; cin>>n>>m;
    //int ans = 0;
    vector<set<int>> G(n, set<int>());
    rep(i, m) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].insert(v); G[v].insert(u);
    }
    set<int> nobles;
    rep(i, n) if(G[i].empty() or *G[i].rbegin() < i) nobles.insert(i);

    int q; cin>>q;
    while(q--){
        int t, u, v; cin>>t;
        if(t == 1) { // agrego
            cin>>u>>v; u--, v--;
            if(u > v) swap(u, v); 
            G[u].insert(v); G[v].insert(u);
            if(*G[v].rbegin() < v)  nobles.insert(v);
            if(nobles.count(u)) nobles.erase(u);
        }
        if(t == 2) {
            cin>>u>>v; u--; v--;
            if(u > v) swap(u, v);
            G[u].erase(v); G[v].erase(u); 
            if(G[u].empty() or (!G[u].empty() and *G[u].rbegin() < u)) nobles.insert(u);
            if(!G[u].empty() and *G[u].rbegin() > u and nobles.count(u)) nobles.erase(u);

            if(G[v].empty() or (!G[v].empty() and *G[v].rbegin() < v)) nobles.insert(v);
            if(!G[v].empty() and *G[v].rbegin() > v and nobles.count(v)) nobles.erase(v);
        }
        if(t == 3){
            //printeo(nobles);
            cout<<nobles.size()<<'\n';       
        }
    }

    return 0;
}