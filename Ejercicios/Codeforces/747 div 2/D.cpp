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

vector<vector<int>> crew;
vector<vector<int>> imp;
vector<int> D;
bool pos = 1;
vector<int> C;
int id = 0;
void dfs(int u, int col){
    cerr<<u<<' '<<col<<'\n';
    D[u] = col;
    C[id] += (col == id); C[id+1] += (col == id+1);
    for(auto& v: crew[u]) {
        if(!pos) break;
        if(D[v] == -1) dfs(v, col);
        if(D[v] != col) { 
            pos = 0; break;
        }
    }
    for(auto& v: imp[u]){
        int aux;
        if(col%2 == 0) aux = col + 1;
        else aux = col - 1;
        if(!pos) break;
        if(D[v] == -1) dfs(v, aux);
        if(D[v] != aux) { 
            cerr<<v<<' '<<D[v]<<' '<<col<<' '<<aux<<'\n';
            pos = 0; break;
        }
    }
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        crew.assign(n, vector<int>());
        imp.assign(n, vector<int>());
        rep(i, m){
            int u, v; string l; cin>>u>>v>>l; u--, v--;
            if(l[0] == 'c') { 
                crew[u].push_back(v);
                crew[v].push_back(u);
            }
            else { 
                imp[u].push_back(v);
                imp[v].push_back(u);
            }
        }
        D.assign(n, -1); id = 0; pos = 1; C.clear();
        rep(i, n) if(D[i] == -1 and (crew.size() + imp.size() != 0)) { // ahora si reviso todas las componentes
            C.push_back(0); C.push_back(0);
            dfs(i, id);
            id += 2;
        }
        cerr<<"termine el dfs"<<'\n';
        int maxi = 0; 
        rep(i, n) if(D[i] == -1) maxi++;
        rep(i, C.size()/2){
            maxi += max(C[2 * i], C[2 * i + 1]);
        }
        if(pos) cout<<maxi<<'\n';
        else cout<<-1<<'\n';
    }


    return 0;
}