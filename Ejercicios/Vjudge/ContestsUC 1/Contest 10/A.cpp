#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define INF (int)1e9
#define pb push_back
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int movei[4]={1,-1, 0,0};
int movej[4]={0, 0,-1,1};

vector<string> mat; 
vector<vector<int>> visited;
int cont;
int comp;


void dfs(int i, int j, int n, int m){
    if(visited[i][j]!=-1) return;
    visited[i][j]=comp;
    cont++;
    //cout<<"el elemento "<<i<<", "<<j<<" pertenece al conjunto "<<comp<<endl;
    for(int h=0;h<4;h++){
        int posi= i+movei[h];
        int posj= j+movej[h];
        if(0<=posi && posi<n && 0<=posj && posj<m){
            if(mat[posi][posj]=='.') {
                dfs(posi,posj,n,m);
            }
        }
    }
    return;

}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cout.tie(0);
    //OJ;
    int n, m;
    cin>>n>>m;
    mat.assign(n,string());
    for(int i=0;i<n;i++){
        cin>>mat[i];
    }
    //debo tener un unordered map que dado una posicion me dice el componente
    comp = 0;
    cont = 0;
    vector<int> conts;
    visited.assign(n,vector<int>(m,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='.'){
                dfs(i,j,n,m);
                conts.push_back(cont);
                cont=0;
                comp++;
            }
        }
    }
    
    vector<int> visitComp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='*'){
                set<int> ss;
                int num=1;
                for(int h=0;h<4;h++){
                    int posi= i+movei[h];
                    int posj= j+movej[h];
                    if(!(0<=posi && posi<n && 0<=posj && posj<m)) continue;
                    if(mat[posi][posj]=='.'){
                        ss.insert(visited[posi][posj]);
                    }
                }
                for(auto s : ss){
                    num+= conts[s];
                }
                mat[i][j]= char(num%10+'0');
            }
        }
        cout<<mat[i]<<"\n";
    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
    //g++ -O2 [path] && time ./a.out < in > out
}