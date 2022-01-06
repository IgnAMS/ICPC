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

int movi[]={1,-1,0,0};
int movj[]={0,0,1,-1};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cout.tie(0);
    OJ;
    int n,m,p;
    cin>>n>>m>>p;
    vector<string> lineas(n);
    vector<int> vel(p);
    for(int i=0;i<n;i++) cin>>vel[i];
    for(int i=0;i<n;i++) cin>>lineas[i];
    map<int,ii> mapa; //dado un jugador nos dice su posicion
    int cont=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if('1'<= lineas[i][j] && lineas[i][j]<='9'){
                mapa.insert(make_pair(lineas[i][j]-'0',ii(i,j)));
            }
        }
    }
    vector<vector<int>> visited(n,(vector<int>(m,-1)));
    queue<int> q;
    q.push(1); //insertamos el nodo 1 que es el primero a visitar
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int i=0;i<vel[u];i++){
            //voy a explorar los nodos del pana miguel
            for(int j=0;j<4;j++){
                int posi= 
            }
        }
    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}