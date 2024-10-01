#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define INF (int)1e9
#define pb push_back
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

vector<unordered_set<int>> Cycles;
vector<vii> AdjList;
vector<bool> visited;
vector<int> parent;
map<ii,int> caminos; //dado los nodos retornar los caminos

void dfs(int u){
    cout<<"entre al dfs para explorar a "<<u<<endl;
    if(visited[u]) return;
    visited[u]=true;
    for(int i=0;i<AdjList[u].size();i++){
        ii v=AdjList[u][i];

        if(visited[v.first] && parent[u] != v.first){
            //hay un ciclo :o
            cout<<"vaya encontre un ciclo entre "<<u<<" y "<<v.first<<endl;
            int root=u;
            unordered_set<int> ciclo;
            cout<<parent[root]<<" "<<v.first<<endl;
            while(parent[root] != v.first){
                ciclo.insert(caminos[ii(root,parent[root])]);
                cout<<"agrego el camino "<<caminos[ii(root,parent[root])]<<endl;
                root=parent[root];
            }
            ciclo.insert(caminos[ii(u,v.first)]);
            if(ciclo.size()%2!=0){
                Cycles.push_back(ciclo);
            }
        }
        
        if(!visited[v.first]){
            parent[v.first]=u;
            dfs(v.first);
        }
    }
    return;
}

struct SegmentTree{
    int n;
    vector<int> S;
    SegmentTree(int asd){
        n=asd;
        S.resize(4*n);
        build(1,0,n,Cycles);
    }

    void build(int u, int l, int r,vector<unordered_set<int>> &vset){
        vector<unordered_set<int>> copia=vset;
        cout<<"entre al segment"<<endl;
        if(l==r){
            bool possible=false;
            for(int i=0;i<copia.size();i++){
                if(!copia[i].count(l)){
                    possible=true;
                    break;
                }
                else{
                    //si contiene la calle lo mato xd
                    copia.erase(copia.begin()+i);
                }
            }
            S[u]=possible;
        }
        build(u*2, l , (l+r)/2, copia);
        build(2*u+1, (l+r)/2+1, r, copia);
        if(S[u*2] && S[u*2+1]) S[u]=true;
        else S[u]=false;
    }
    bool query(int i, int j){
        return queryy(1,0,n,i,j);
    }
    bool queryy(int u, int l, int r, int i, int j){
        //si esta completamente contenido
        if(i<=l && r<=j){
            return S[u];
        }
        //si esta fuera de rango
        if(r<i || j<l){
            return true;
        }
        //si no
        return queryy(u*2,l,(l+r)/2,i,j) && queryy(u*2+1, (l+r)/2+1, r, i ,j);
    }

};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cout.tie(0);
    OJ;
    int n,m,q;
    cin>>n>>m>>q;
    int u,v;
    AdjList.assign(n,vii());
    visited.assign(m,false);
    parent.assign(n,-1);
    for(int i=0;i<m;i++){
        cin>>u>>v;
        AdjList[u-1].push_back(ii(v-1,0));
        AdjList[v-1].push_back(ii(u-1,0));
        caminos.insert(make_pair(ii(u-1,v-1),i+1));
        caminos.insert(make_pair(ii(v-1,u-1),i+1));
    }
    //el segment tree se inicializa con la cantidad de dias
    dfs(0);
    cout<<"termine de ingresar el input"<<endl;
    SegmentTree ST(m);
    cout<<"sobrevii el segment tree"<<endl;
    int l,r;
    for(int i=0;i<q;i++){
        cin>>l>>r;
        cout<<ST.query(l,r)<<endl;
    }



    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}